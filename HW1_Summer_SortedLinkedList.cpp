#include <iostream>
#include "HW1_Summer_SortedLinkedList.h"

using namespace std;

int main()
{
    SortedLinkedList xD;

    xD.Add(20);
    xD.Add(60);
    xD.Add(30);
    xD.Add(90);
    xD.Add(70);
    cout << "Created SortedLinkedList is:\nPrint all values in ascending order\n";
    xD.PrintAscending();
    cout << "\nPrint all values in descending order\n";
    xD.PrintDescending();
    cout << "\nForward Index of 30 is: " << xD.ForwardIndex(30)
    << "\nBackward Index of 30 is: " << xD.BackwardIndex(30)
    << "\nSortedLinkedList includes " << xD.NoOfNodes() << " number of node\n";

    return 0;
}
