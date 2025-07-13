#ifndef EMAIL_VALIDATOR_HPP
#define EMAIL_VALIDATOR_HPP
#include <iostream>
#include <regex>
#include <string>
#include <vector>

class EmailValidator {
private:
    std::regex emailPattern;
public:
    EmailValidator();

    bool isValid(const std::string& email);
    std::string extractDomain(const std::string& email);
};

#endif // EMAIL_VALIDATOR_HPP