#include <iostream>

// RECURSION
// Involves a function to call itself to solve a "smaller" version of the original problem.

using namespace std;

template <typename T>
T faktoriyel(T x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * faktoriyel(x - 1);
    }
}

int main()
{
    cout << faktoriyel<int>(5);
}