#include <iostream>
#include "HeaderFiles/ArrayStack_CT.h"
// MAKE AN EXAMPLE WITH STACK
using namespace std;

int main()
{
    int n;
    cout << "Enter size of stack: ";
    cin >> n;
    
    ArrayStack_CT<int> yigint(n);
    for (int i = 0; i < n; i++)
    {
        int xd;
        cout << "Enter your int number: ";
        cin >> xd;
        yigint.push(xd);
    }
    cout << "-------" << endl;
    for (int i = 0; !yigint.isEmpty(); i++)
    {
        cout << yigint.pop() << endl;
    }
}