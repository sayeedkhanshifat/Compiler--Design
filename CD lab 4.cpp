#include <iostream>
using namespace std;

void check_identifier(string s)
{

    string keywords[] ={ " int", "float", " double", "char ",  "if ", " while", " for", " else", " return", "void" };

    for (int k = 0; k<10;k++)
    {
        if ( s == keywords[k])
        {
            cout<< s << "= Not Identifier (keyword)" << endl;
            return;
        }
    }



    int flag = 0;

    if ((s[0] >= 'a' && s[0] <= 'z') ||
        (s[0] >= 'A' && s[0] <= 'Z') ||
        (s[0] == '_'))
    {
        flag = 1;

        for (int i = 1; i < s.length(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] == '_') ||
                (s[i] >= '0' && s[i] <= '9'))
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1)
        cout << s << " is Identifier" << endl;
    else
        cout << s << " is not Identifier" << endl;
}
