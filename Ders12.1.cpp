#include <iostream>
#include <string>
#include "HeaderFiles/LinkedListStack.h"
// CALC POSTFIX EXPRESION
using namespace std;

float calc(int a, int b, char op)
{
    switch (op)
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

bool isDigit(char x)
{
    return ((x < '9') && (x > '0'));
}

int main(int argc, char const *argv[])
{
    LinkedListStack<int> stack;
    string expr;
    int x, y;
    char ch;

    cout << "Enter Postfix Exp: ";
    cin >> expr;

    for (int i = 0; i < expr.length(); i++)
    {
        ch = expr[i];
        if (isDigit(ch))
        {
            stack.push(ch - '0');
        }
        else
        {
            y = stack.pop();
            x = stack.pop();
            stack.push(calc(x, y, ch));
        }
    }

    cout << "Result: " << stack.pop() << endl;

    return 0;
}
