#include <iostream>

// RECURSION
// Involves a function to call itself to solve a "smaller" version of the original problem.

using namespace std;

template <typename T>
T toplam(T x)
{
    if (x == 1)
    {
        return 1;
    }
    else
    {
        return x + toplam<T>(x - 1);
    }
}

int main()
{
    cout << toplam<int>(5);
}