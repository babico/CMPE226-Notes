#include <iostream>

// RECURSION
// Involves a function to call itself to solve a "smaller" version of the original problem.

using namespace std;

template <typename T>
T ussu(T x, T y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return x * ussu<T>(x, y - 1);
    }
}

int main()
{
    cout << ussu<int>(5, 3);
}