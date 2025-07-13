#ifndef NS_LOOKUP_HPP
#define NS_LOOKUP_HPP
#include <string>

class NsLookup {
public:
    explicit NsLookup(const std::string& domain);
    bool run() const;
    bool checkDomainExistence();

private:
    std::string domain;
    std::string runCommand(const std::string& command) const;
    
};

#endif // NS_LOOKUP_HPP
