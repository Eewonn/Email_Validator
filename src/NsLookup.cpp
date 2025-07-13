#include "NsLookup.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

// Constructor Implementation
NsLookup::NsLookup(const string& domain) : domain(domain) {}

// Run nslookup commant thru system commands
bool NsLookup::run() const {

    string filename = "nslookup_results.txt";   
    //Initialize string command "nslookup" + extracted domain
    string nslookup = "nslookup -q=mx " + domain + " > " + filename + " 2>&1";;
    int result = system(nslookup.c_str());
    

    // If result = 1, Success; else result = 0, Failed
    if (result != 0) {
        cerr << "nslookup failed with code " << result << endl;
        return false;
    }
    
    return true;
}

bool NsLookup::checkDomainExistence() {
    regex notFoundPattern(R"(\*\*\* UnKnown can't find .+)");

    // read results from file

    ifstream file("nslookup_results.txt");
    if (!file.is_open()) {
        cerr << "Error checking results." << endl;
        return 1;
    }
    cout << "Results from nslookup:" << endl << endl;
    string line;
    bool domainExists = false;
    while (getline(file, line)) {
        cout << line << endl;
        if (regex_search(line, notFoundPattern)) {
            domainExists = false;
            break;
        } else {
            domainExists = true;
            
        }
    }
    file.close();
    return domainExists;
}