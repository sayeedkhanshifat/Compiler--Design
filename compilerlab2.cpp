#include <iostream>
using namespace std;

void check(string equation)
{
    int n = 1;
    for (int i = 0; i < equation.length(); i++)
    {

        if (equation[i] == '+' || equation[i] == '-' || equation[i] == '/' ||
            equation[i] == '%' || equation[i] == '=' || equation[i] == '*')
        {
            cout << "Operation " << n << ": " << equation[i] << endl;
            n++;
        }
    }
}

int main()
{
    string equation;
    cout << "Enter an equation: ";
    cin >> equation;
    check(equation);
    return 0;
}



