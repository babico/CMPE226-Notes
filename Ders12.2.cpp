#include <iostream>
#include <string>
#include "HeaderFiles/ArrayStack_CT.h"
// INFIX TO POSTFIX
using namespace std;

bool prec(char a, char b)
{
    if ((a == '-') || (a == '+') && (b == '/') || (b == '*'))
    {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ArrayStack_CT<char> oper;
    char ch, op;
    string expr;

    cout << "Enter Infix Exp: ";
    cin >> expr;

    for (int i = 0; i < expr.length(); i++)
    {
        ch = expr[i];
        if (isalnum(ch))
        {
            cout << ch;
        }
        else
        {
            if (!oper.isEmpty() && prec(oper.sTop(), ch))
            {
                cout << oper.pop();
            }
            oper.push(ch);
        }
    }
    while (!oper.isEmpty())
    {
        cout << oper.pop();
    }

    return 0;
}
