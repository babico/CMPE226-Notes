#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList.h"

// Write a recursive function that uses only addition to multiply 2 integers & returns the result.

using namespace std;

int mult(int x, int y)
{
    if (y < 0)
    {
        return -(mult(x, -y));
    }
    else if (y == 0)
    {
        return 0;
    }
    else if (y == 1)
    {
        return x;
    }
    else
    {
        return (x + mult(x, y - 1));
    }
}

int main()
{
    cout << mult(5, -4);

    return 0;
}