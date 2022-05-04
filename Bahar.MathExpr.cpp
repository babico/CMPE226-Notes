#include <iostream>
#include <string>
#include "HeaderFiles/LinkedListStack.h"

using namespace std;

// input a math expression and chech it

int main(int argc, char const *argv[])
{
    LinkedListStack<char> st;
    int valid = 1;
    string exp;
    char c;

    cout << "enter: ";
    cin >> exp;
    
    for (int i = 0; (i < exp.length() && valid); i++)
    {
        c = exp[i];
        if (c == '(')
        {
            st.push(c);
            cout << "pushed\n";
        }
        else if (c == ')')
        {
            if (!st.isEmpty())
            {
                st.pop();
                cout << "popped\n";
            }
            else
                valid = 0;
        }
    }
    if (!st.isEmpty())
    {
        valid = 0;
    }

    else if (valid)
    {
        cout << "valid\n";
    }
    else
        cout << "not valid\n";

    return 0;
}
