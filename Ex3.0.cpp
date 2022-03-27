#include <iostream>
#include <string>
#include "HeaderFiles/LinkedListStack.h"

using namespace std;

float eval(float a, float b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        break;
    }
}

bool validDigit(char c)
{
    return (c >= '0' && c <= '9');
    // check if it is a digit
}

main()
{
    char ch;
    float x, y;
    string expr;
    LinkedListStack<float> st;

    cout << "Enter an expression in Postfix:";
    cin >> expr;
    
    int l = expr.length();
    for (int i = 0; i < l; i++)
    {
        ch = expr[i];
        if (validDigit(ch))
        {
            float val = float(ch - '0');
            st.push(val);
        }
        else
        {
            y = st.pop();
            x = st.pop();
            float res = eval(x, y, ch);
            st.push(res);
        }
    }

    cout << "Result=" << st.pop() << endl;

    return 0;
}