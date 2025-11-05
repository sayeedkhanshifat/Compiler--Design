#include<iostream>
using namespace std;

void CheckNumeric(string n) {
    int i;
    for (i = 0; i < n.length(); i++) {
        if (n[i] >= '0' && n[i] <= '9') {
            continue;
        } else {
            cout << "Not Numeric Constant" << endl;
            return; 
        }
    }
    cout << "Numeric Constant" << endl;
}

int main() {
    string n;
    cout << "Enter the input: ";
    cin >> n;

    CheckNumeric(n);

    return 0;
}


































