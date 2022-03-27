#include <iostream>
#include <string>
#include "HeaderFiles/LinkedListStack.h"

// input a math expression and check it.

int main()
{
    LinkedListStack<char> par;
    bool valid = true;
    string expr;
    char next, x;

    cout << "Enter expression: ";
    cin >> expr;

    for (int i = 0; (i < sizeof(expr)) && valid; i++)
    {
        next = expr[i];
        if (next == '(')
        {
            par.push(next);
        }
        else if (next == ')')
        {
            if (par.isEmpty())
            {
                valid = false;
            }
            else
            {
                x = par.pop();
            }
        }
    }
    if (!par.isEmpty())
    {
        valid = false;
    }
    if (valid)
    {
        cout << "correct";
    }
    else
    {
        cout << "incorrect";
    }
}