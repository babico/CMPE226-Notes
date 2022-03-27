#include <iostream>
// RECURSION
// Involves a function to call itself to solve a "smaller" version of the original problem.
using namespace std;
template <typename T>
T fibbo(T x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x == 1)
    {
        return 1;
    }
    else
    {
        return fibbo<T>(x - 1) + fibbo<T>(x - 2);
    }
}

int main()
{
    cout << fibbo<int>(6);
}