#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cctype>
using namespace std;


bool isKeyword(const string& s) {
    string keywords[] = {
        "int","float","double","char","void","long","short","if","else","for",
        "while","do","return","break","continue","switch","case","class",
        "struct","public","private","protected","virtual","include","using",
        "namespace","true","false","new","delete","this","const","static",
        "enum","try","catch","throw","inline","typedef","sizeof"
    };

    for (string k : keywords)
        if (s == k) return true;
    return false;
}


bool isIdentifier(const string& s) {
    if (s.empty()) return false;
    if (!(isalpha(s[0]) || s[0] == '_')) return false;

    for (char c : s)
        if (!(isalnum(c) || c == '_'))
            return false;

    return true;
}


bool isPunctuation(char c) {
    string punct = ";,(){}[]";
    return punct.find(c) != string::npos;
}


vector<string> operatorsList = {
    "+","-","*","/","%","=",
    "==","!=",">=","<=","<",">",
    "++","--",
    "+=","-=","*=","/=","%=",
    "&&","||","!",
    "&","|","^","~"
};


bool isOperatorStart(char c) {
    string opStart = "+-*/%=!<>&|^~";
    return opStart.find(c) != string::npos;
}

int main() {
    ifstream file("sample.txt");
    if (!file.is_open()) {
        cout << "Error: Cannot open sample.txt\n";
        return 1;
    }

    map<string, vector<int>> identifiers;
    map<string, vector<int>> keywords;
    map<string, vector<int>> punctuation;
    map<string, vector<int>> operators;

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;
        string word = "";

        for (size_t i = 0; i < line.length(); i++) {
            char c = line[i];


            if (isalnum(c) || c == '_') {
                word += c;
            }
            else {

                if (!word.empty()) {
                    if (isKeyword(word))
                        keywords[word].push_back(lineNumber);
                    else if (isIdentifier(word))
                        identifiers[word].push_back(lineNumber);
                    word = "";
                }


                if (isPunctuation(c)) {
                    string p(1, c);
                    punctuation[p].push_back(lineNumber);
                }


                if (isOperatorStart(c)) {
                    string op(1, c);


                    if (i + 1 < line.size()) {
                        string op2 = op + line[i + 1];
                        for (auto &o : operatorsList) {
                            if (o == op2) {
                                operators[op2].push_back(lineNumber);
                                i++;
                                goto continue_loop;
                            }
                        }
                    }


                    for (auto &o : operatorsList) {
                        if (o == op) {
                            operators[op].push_back(lineNumber);
                            break;
                        }
                    }
                }

                continue_loop:;
            }
        }


        if (!word.empty()) {
            if (isKeyword(word))
                keywords[word].push_back(lineNumber);
            else if (isIdentifier(word))
                identifiers[word].push_back(lineNumber);
        }
    }

    file.close();


    cout << "\n===== IDENTIFIER TABLE =====\n";
    for (auto& x : identifiers) {
        cout << x.first << " -> ";
        for (auto n : x.second) cout << n << " ";
        cout << endl;
    }

    cout << "\n===== KEYWORD TABLE =====\n";
    for (auto& x : keywords) {
        cout << x.first << " -> ";
        for (auto n : x.second) cout << n << " ";
        cout << endl;
    }

    cout << "\n===== PUNCTUATION TABLE =====\n";
    for (auto& x : punctuation) {
        cout << x.first << " -> ";
        for (auto n : x.second) cout << n << " ";
        cout << endl;
    }

    cout << "\n===== OPERATOR TABLE =====\n";
    for (auto& x : operators) {
        cout << x.first << " -> ";
        for (auto n : x.second) cout << n << " ";
        cout << endl;
    }

    return 0;
}


