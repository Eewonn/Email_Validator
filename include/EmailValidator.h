#ifndef EMAIL_VALIDATOR_H
#define EMAIL_VALIDATOR_H

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class EmailValidator {
private:
    regex emailPattern;
public:
    EmailValidator();
    ~EmailValidator();

    bool isValid(const std::string& email);
    string extractDomain(const std::string& email, std::string& domain);
};

#endif // EMAIL_VALIDATOR_H