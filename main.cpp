#include <iostream>
#include <string>
#include "NsLookup.hpp"
using namespace std;

int main() {
    // Class instances

    // Get Input
    string input;
    cout << "Enter email: ";
    cin >> input;

    // INSERT HERE (Find @ To stop and check domain)
    // HEREEEEEEEEEEEEE
    // Change this to only include text after @
    // Example: email = markeron5@gmail.com; domain after @ = gmail.com
    string domain = input;

    NsLookup nslookup(domain);
    nslookup.run();


    // Email input
    // string email;
    // cout << "Enter email to validate: ";
    // cin >> email;

    return 0;
}
