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

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    EmailValidator emailValidator;
    string input;
    char choice;

    do {

        clearScreen();

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

        bool emailValid = emailValidator.isValid(input);
        if (!emailValid) {
            cerr << "\n[!] Invalid email format." << endl;
            printFooter();
        } else {
            cout << "\nValid email format." << endl;
            string domain = emailValidator.extractDomain(input);
            cout << "[i] Extracted domain: " << domain << endl << endl;

            cout << "Running NSLookup for domain: " << domain << " ..." << endl;

            NsLookup nslookup(domain);
            nslookup.run();

            cout << "\nChecking domain existence..." << endl;
            bool domainExists = nslookup.checkDomainExistence();

            cout << endl;
            if (domainExists && emailValid) {
                cout << "Email is Valid and the Domain Exists." << endl;
            } else if (!domainExists && emailValid) {
                cout << "Email is Valid but the Domain Does Not Exist." << endl;
            } else {
                cout << "Email is Invalid." << endl;
            }

            printFooter();
        }

        cout << "Would you like to check another email? (Y/N): ";
        cin >> choice;

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
