#ifndef EMAIL_VALIDATOR_HPP
#define EMAIL_VALIDATOR_HPP
#include <iostream>
#include <string>

class EmailValidator {
public:
    EmailValidator();
    bool isValid(const std::string& email);
    std::string extractDomain(const std::string& email);

private:
    bool isAlphaNumeric(char c);
    bool isLocal(char c);
    bool isDomain(char c);
};

#endif // EMAIL_VALIDATOR_HPP