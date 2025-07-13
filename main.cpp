#include <iostream>
#include <string>
#include "NsLookup.hpp"
#include "EmailValidator.hpp"
using namespace std;

int main() {
    // Class instances
    EmailValidator emailValidator;

    // Get Input
    string input;
    cout << "Enter email to check validity and domain existence: ";
    try {
        cin >> input;
        if (input.find('@') == string::npos) {
            throw invalid_argument("Invalid email format: missing '@'.");
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    if (!emailValidator.isValid(input)) {
        cerr << "Invalid email format." << endl;
        return 1;
    } else {
        cout << "Valid email format." << endl;
    }
    
    string domain = emailValidator.extractDomain(input);
    cout << "Extracted domain: " << domain << endl << endl;

    cout << "Running NSLookup for domain: " << domain << endl;

    // NSLookup

    NsLookup nslookup(domain);
    nslookup.run();
    

    return 0;
}
