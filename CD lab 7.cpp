#include <iostream>
using namespace std;


string getFullName(string first, string last) {
    string full = first + " " + last;
    return full;
}

int main() {
    string firstName, lastName, fullName;

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;


    fullName = getFullName(firstName, lastName);

    cout << "Full name = " << fullName << endl;

    return 0;
}

