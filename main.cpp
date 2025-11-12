
#include <iostream>
#include <fstream>
using namespace std;

void check_identifier(string s);

int main() {
    ifstream file("cd1.txt");

    if (!file) {
        cout << "Error: Could not open cd1.txt file!" << endl;
        return 1;
    }

    string s;
    cout << "Checking Identifiers from cd1.txt\n" << endl;

    while (file >> s) {
        check_identifier(s);
    }

    file.close();
    return 0;
}
