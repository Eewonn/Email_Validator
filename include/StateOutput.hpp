#ifndef STATEOUTPUT_HPP
#define STATEOUTPUT_HPP
#include <string>

class StateOutput {
public:
    void stateLocal(const std::string& local);
    void stateAt();
    void stateDomain(const std::string& domain);
    void stateDomainDot();
    void stateDomainSuffix(const std::string& suffix);
};

#endif // STATE_OUTPUT_HPP