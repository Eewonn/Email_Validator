#include "StateOutput.hpp"
#include <iostream>
using namespace std;

void StateOutput::stateLocal(const string& local) {
    cout << "[start] [local]\n";
    cout << "-----> [\"" << local << "\"] -----> \n";
}

void StateOutput::stateAt() {
    cout << "[at]\n";
    cout << "-----> [\"@\"] -----> \n";
}

void StateOutput::stateDomain(const string& domain) {
    cout << "[domain]\n";
    cout << "-----> [\"" << domain << "\"] -----> \n";
}

void StateOutput::stateDomainDot() {
    cout << "[domain_dot]\n";
    cout << "-----> [\".\"] -----> \n";
}

void StateOutput::stateDomainSuffix(const string& suffix) {
    cout << "[domain-suffix] [final]\n";
    cout << "-----> [\"" << suffix << "\"] -----> \n\n";
}
