#include <iostream>
#include "HeaderFiles/bSearchTreeType.h" // bSearchTreeType.h

using namespace std;

void countItems(int search, bSearchTreeType<int> BST)
{
    int count = 0;
    while (BST.search(search) != NULL)
    {
        BST.deleteNode(search);
        count++;
    }
    
    cout << count <<" for the search item " << search;
}

int main()
{
    bSearchTreeType<int> BST;
    int input = 0, count = 0;
    
    cout << "Enter number size: ";
    cin >> count;

    cout << "Enter number: ";
    for (int i = 0; i < count; i++)
    {
        cin >> input;
        BST.insert(input);
    }

    cout << "\nSearch number: ";
    cin >> input;
    countItems(input, BST);

    return 0;
}