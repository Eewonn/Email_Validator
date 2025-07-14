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

    // initialize the file to store results
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

    // Regex to check if domain exists (works for linux and windows)
    regex notFoundPattern(R"(UnKnown can't find|NXDOMAIN|does not exist|server can't find)");

    // read results from file

    // open and read the file
    ifstream file("nslookup_results.txt");
    if (!file.is_open()) {
        cerr << "Error checking results." << endl;
        return false;
    }

    // notify user about results
    cout << "Results from nslookup:" << endl << endl;
    string line;
    bool domainExists = true;

    // read each line and check for existence based on regex pattern
    while (getline(file, line)) {
        cout << line << endl;
        if (regex_search(line, notFoundPattern)) {
            domainExists = false;
            break;
        }
    }


    file.close();
    return domainExists;
}