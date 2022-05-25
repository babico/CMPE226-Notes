#include <iostream>
#include "HeaderFiles/ArrayStack_CT.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    ArrayStack_CT<int> stck;

    int x = 1;
    int y = 4;
    int z = 5;

    stck.push(x);
    stck.push(y);
    stck.push(z);
    cout << stck.sTop();

    return 0;
}