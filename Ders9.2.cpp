#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList.h"

// Write a recursive function to convert a decimal number to binary

using namespace std;

void convert(int x)
{
    if ((x != 0))
    {
        convert(x / 2);
        cout << x % 2;
    }
}

int main()
{
    convert(3);

    return 0;
}