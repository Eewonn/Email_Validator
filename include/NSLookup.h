#ifndef NS_LOOKUP_H
#define NS_LOOKUP_H

#include <string>

class NSLookup {
public:

    bool isDomainValid(const std::string& domain) const;

private:

    std::string runCommand(const std::string& command) const;
};

#endif // NS_LOOKUP_H
