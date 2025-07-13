#include "EmailValidator.hpp"
#include "StateOutput.hpp"
#include <iostream>
#include <string>

using namespace std;

EmailValidator::EmailValidator() {}

bool EmailValidator::isLocal(char c){
    return isalnum(c) || c == '.' || c == '-' || c == '+';
}

bool EmailValidator::isDomain(char c){
    return isalnum(c) || c == '-' || c == '.';
}

bool EmailValidator::isValid(const std::string& email) {
    // check if the email is valid when it reached final state
    enum State{
        start, local, local_dot, at, domain, domain_dot, domain_suffix
    };

    State state = start;
    StateOutput output;

    string localState = "";
    string domainState = "";
    string domainSuffixState = "";

    int n = 0;
    size_t i = 0;

    while (i < email.length()){
        char c = email[i];

        switch(state){
            case start:
                if (isalnum(c)){
                    state = local;
                    localState += c;
                } else {
                    return false;
                }

                break;

            case local:
                if (isLocal(c)){
                    localState += c;
                    if (c == '.'){
                        state = local_dot;
                    }
                } else if (c == '@'){
                    output.stateLocal(localState);
                    state = at;
                    output.stateAt();
                    n++;
                } else {
                    return false;
                }

                break;

            case local_dot:
                if (isalnum(c)){
                    localState += c;
                    state = local;
                } else {
                    return false;
                }

                break;

            case at:
                if (isalnum(c)){
                    domainState += c;
                    state = domain;
                } else {
                    return false;
                }

                break;

            case domain:
                if (isalnum(c)){
                    domainState += c;
                } else if (c == '.'){
                    output.stateDomain(domainState);
                    state = domain_dot;
                    domainState = "";
                } else {
                    return false;
                }
                break;

            case domain_dot:
                if (isalnum(c)){
                    domainSuffixState += c;
                    state = domain_suffix;
                } else {
                    return false;
                }

                break;

            case domain_suffix:
                if (isalnum(c)){
                    domainSuffixState += c;
                } else if (c == '.'){
                    output.stateDomainSuffix(domainSuffixState);
                    output.stateDomainDot();
                    state = domain_dot;
                } else {
                    return false;
                }

                break;

        }

        i++; // Character Iteration
    }

    if (state == domain || state == domain_suffix){
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

