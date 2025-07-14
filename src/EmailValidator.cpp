#include "EmailValidator.hpp"
#include "StateOutput.hpp"
#include <iostream>
#include <string>

using namespace std;

EmailValidator::EmailValidator() {}

// Check char if in local part
bool EmailValidator::isLocal(char c){
    return isalnum(c) || c == '.' || c == '-' || c == '+';
}

// Check char if in domain part
bool EmailValidator::isDomain(char c){
    return isalnum(c) || c == '-' || c == '.';
}

// Check if the email is valid when it reached final state
bool EmailValidator::isValid(const std::string& email) {

    // Available states
    enum State{
        start, local, local_dot, at, domain, domain_dot, domain_suffix
    };

    // State variables initialization
    State state = start;
    StateOutput output;

    string localState = "";
    string domainState = "";
    string domainSuffixState = "";

    int atCount = 0;
    char prevChar = '\0';
    bool hasDot = false;
    size_t i = 0; // char iteration

    // Check char state
    while (i < email.length()){
        char c = email[i];

        switch(state){
            // Initialize start state then continue to local
            case start:
                if (isalnum(c)){
                    state = local;
                    localState += c;
                } else {
                    return false;
                }

                break;
            
            // Check if character is still at local state or in @ state
            case local:
                if (isLocal(c)){
                    if (c == '.' && prevChar == '.') return false;
                    localState += c;
                    if (c == '.'){
                        state = local_dot;
                    }
                } else if (c == '@'){
                    if (prevChar == '.' || localState.front() == '.' || !isalnum(localState.back())) return false;
                    output.stateLocal(localState);
                    state = at;
                    output.stateAt();
                    atCount++;
                    if (atCount > 1) return false;
                } else {
                    return false;
                }

                break;
            
            // If encountered dot in local, continue in local state
            case local_dot:
                if (isalnum(c)){
                    localState += c;
                    state = local;
                } else {
                    return false;
                }

                break;
            
            // When encountered @ move to domain state
            case at:
                if (isalnum(c)){
                    domainState += c;
                    state = domain;
                } else {
                    return false;
                }

                break;
            
            // Check if in domain state and when encountered dot move to domain_dot state
            case domain:
                if (isalnum(c)){
                    domainState += c;
                } else if (c == '.'){
                    if (prevChar == '.' || domainState.empty()) return false;
                    output.stateDomain(domainState);
                    hasDot = true;
                    state = domain_dot;
                    domainState = "";
                } else {
                    return false;
                }
                break;
            
            // When in domain_dot move to domain_suffix state
            case domain_dot:
                if (isalnum(c)){
                    output.stateDomainDot();
                    domainSuffixState += c;
                    state = domain_suffix;
                } else {
                    return false;
                }

                break;
            
            // Check if in domain_suffix and valid suffix
            case domain_suffix:
                if (isalnum(c)){
                    domainSuffixState += c;
                } else if (c == '.'){
                    if (domainSuffixState.length() < 2) return false; // domain suffix must have 2 characters
                    output.stateDomainSuffix(domainSuffixState);
                    output.stateDomainDot();
                    domainSuffixState = "";
                    state = domain_dot;
                } else {
                    return false;
                }

                break;

        }

        prevChar = c; // Store the previous character
        i++; // Character Iteration
    }

    // Set domain_suffix as final state, check if valid suffix
    if (state == domain_suffix){
        if (!hasDot || domainSuffixState.length() < 2 || prevChar == '.') {
            return false;
        }

        if (!domainState.empty()) {
            output.stateDomain(domainState);
        }

        if (!domainSuffixState.empty()) {
            output.stateDomainSuffix(domainSuffixState);
        }

        return true;
    }

    return false;
}

string EmailValidator::extractDomain(const std::string& email) {
    // from the email, extract the domain part (after the '@' symbol)

    size_t pos = email.find('@');
    if (pos != string::npos) {
        return email.substr(pos + 1);
    }
    return "";
}