#include <iostream>
#include "HeaderFiles/BinaryTree_CT.hpp"

// UNION DATA TYPES

using namespace std;

union A
{
    int x;
    double y;
    char z[10];
};

int main(int argc, char const *argv[])
{
    union A obj;

    obj.x = 2;
    cout << obj.x;
    obj.y = 3.45;

    return 0;
}