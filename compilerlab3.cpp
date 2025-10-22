#include <iostream>
#include <string>
using namespace std;

void checkComment( string &line) {
    int n = (int)line.length();
    if (n >= 2 && line[0] == '/' && line[1] == '/') {
        cout << "It is a single-line comment\n";
    }
    else if (n >= 4 && line[0] == '/' && line[1] == '*'&& line[n-2] == '*' && line[n-1] == '/') {
        cout << "It is a multi-line comment\n";
    }
    else {
        cout << "It is not a comment\n";
    }
}

int main() {
    string input;
    cout << "Enter a line: ";

    getline(cin, input);
    checkComment(input);
    return 0;
}
