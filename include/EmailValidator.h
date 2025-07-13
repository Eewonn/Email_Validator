#ifndef EMAIL_VALIDATOR_H
#define EMAIL_VALIDATOR_H

#include <string>
#include <regex>

class EmailValidator {
public:
    EmailValidator();
    ~EmailValidator();

    bool isValid(const std::string& email) const;
};

#endif // EMAIL_VALIDATOR_H