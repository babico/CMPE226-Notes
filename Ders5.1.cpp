#include <iostream>
#include "HeaderFiles/LinkedList_CT.h"
// MUSING HEADER FILE

using namespace std;

int main()
{
    LinkedList<int> liste;

    int num;
    cin >> num;
    while (num != -99)
    {
        liste.insertLast(num);
        cin >> num;
    }

    cout << liste << endl;

    num = 3;
    liste.deleteNode(num);

    cout << liste << endl;
    return 0;
}
