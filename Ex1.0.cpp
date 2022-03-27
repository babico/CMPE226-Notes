/*
Delta airlines maintains & scheduled flights/day from Ankara
numbered 100,200,300 & 400. For each of these flights they
keep a LL of passenger names as follows.
*/
#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList.h"
using namespace std;

int main()
{
    LinkedList<int> sdasd;
    for (int i = 0; i < 5; i++)
    {
        sdasd.insertLast(i);
    }
    cout << sdasd << endl;

    int num = 67;
    cout << sdasd << endl;
    sdasd.insertAt(3, num);

    cout << sdasd;

    return 0;
}