#include <iostream>
// RECURSION
// Involves a function to call itself to solve a "smaller" version of the original problem.
using namespace std;

void guess(int &x)
{
    if (x > 0)
    {
        cout << x;
        x--;
        guess(x);
        cout << endl
             << x;
    }
}

int main()
{
    int x = 3;
    guess(x);
}