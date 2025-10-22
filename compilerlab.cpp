#include <iostream>
using namespace std;

bool isNum(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << isNum("12345") << endl;
    cout << isNum("12a45") << endl;
    return 0;
}

































