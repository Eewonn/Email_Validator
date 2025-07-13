#include "../include/EmailValidator.h"
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

EmailValidator::EmailValidator() {
    // constructor implementation
    // email pattern: username@domain.extension or username@domain.subdomain.extension

    emailPattern = regex(R"((^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$))");
}

bool EmailValidator::isValid(const std::string& email) {
    // check if the email is valid

    return regex_match(email, emailPattern);
}

string EmailValidator::extractDomain(const std::string& email, std::string& domain) {
    // from the email, extract the domain part (after the '@' symbol)

    if (isValid(email)) {
        // if the email is valid, extract the domain

        char delimiter = '@';
        size_t position = email.find(delimiter);
        
        if (position != string::npos) {
            domain = email.substr(position + 1);
        } else {
            domain.clear();
        }

        return domain;
    }
}

