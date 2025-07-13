#include "StateOutput.hpp"
#include <iostream>
using namespace std;

void StateOutput::stateLocal(const string& local) {
    cout << "[START] ---> [LOCAL] \"" << local << "\" ";
}

void StateOutput::stateAt() {
    cout << " ---> [AT] \"@\" ";
}

void StateOutput::stateDomain(const string& domain) {
    cout << " ---> [DOMAIN] \"" << domain << "\" ";
}

void StateOutput::stateDomainDot() {
    cout << " ---> [DOMAIN_DOT] \".\" ";
}

void StateOutput::stateDomainSuffix(const string& suffix) {
    cout << " ---> [DOMAIN_SUFFIX] [FINAL] \"" << suffix << "\"" << endl;
}
