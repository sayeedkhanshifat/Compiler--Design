#include <iostream>
using namespace std;


bool isIdentifier(string s) {
    int i;


    if (!((s[0] >= 'A' && s[0] <= 'Z') ||
          (s[0] >= 'a' && s[0] <= 'z') ||
          s[0] == '_'))
        flag =0;


    for (i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= '0' && s[i] <= '9') ||
              s[i] == '_'))
            flag=0;
    }

    flag=1;
}

int main() {
    string s;

    cout << "Enter a word: ";
    cin >> s;

    if (flag=1)
        cout << s << " is a valid identifier." << endl;
    else
        cout << s << " is NOT a valid identifier." << endl;

    return 0;
}

