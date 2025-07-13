#include <iostream>
#include <string>
#include <limits>
#include "NsLookup.hpp"
#include "EmailValidator.hpp"
using namespace std;

void printHeader() {
    cout << "==========================================" << endl;
    cout << "         EMAIL VALIDATOR & NSLOOKUP        " << endl;
    cout << "==========================================" << endl << endl;
}

void printFooter() {
    cout << endl << "==========================================" << endl;
}

int main() {
    EmailValidator emailValidator;
    string input;
    char choice;

    do {
        system("cls"); // Clear screen for Terminal
        printHeader();

        cout << "Enter an email to check validity and domain existence:" << endl;
        cout << ">> ";
        try {
            cin >> input;
            if (input.find('@') == string::npos) {
                throw invalid_argument("Invalid email format: missing '@'.");
            }
        } catch (const exception& e) {
            cerr << "\n[!] Error: " << e.what() << endl;
            printFooter();
            cout << "Try again? (Y/N): ";
            cin >> choice;
            continue;
        }

        if (!emailValidator.isValid(input)) {
            cerr << "\n[!] Invalid email format." << endl;
            printFooter();
        } else {
            cout << "\nValid email format." << endl;
            string domain = emailValidator.extractDomain(input);
            cout << "[i] Extracted domain: " << domain << endl << endl;

            cout << "Running NSLookup for domain: " << domain << " ..." << endl;
            NsLookup nslookup(domain);
            nslookup.run();
            printFooter();
        }

        cout << "Would you like to check another email? (Y/N): ";
        cin >> choice;
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (toupper(choice) == 'Y');

    cout << "\nThank you for using Email Validator & NSLookup!" << endl;
    cout << "\n==========================================" << endl;
    cout << "  GROUP NAME: AutomaTeam" << endl;
    cout << "  MEMBERS:" << endl;
    cout << "    - DIAZ, Mark Eron" << endl;
    cout << "    - MAGUGAT, Zio Gregory" << endl;
    cout << "    - MEJIA, Klyde Hedrick" << endl;
    cout << "    - TAGUIAM, Johann Patrick" << endl;
    cout << "==========================================" << endl;

    return 0;
}
