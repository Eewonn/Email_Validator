#include "NsLookup.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

// Constructor Implementation
NsLookup::NsLookup(const string& domain) : domain(domain) {}

// Run nslookup commant thru system commands
bool NsLookup::run() const {
    //Initialize string command "nslookup" + extracted domain
    string nslookup = "nslookup " + domain;
    int result = system(nslookup.c_str());

    // If result = 1, Success; else result = 0, Failed
    if (result != 0) {
        cerr << "nslookup failed with code " << result << endl;
        return false;
    }
    return true;
}
