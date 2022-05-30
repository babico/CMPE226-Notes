#include <iostream>
#include <string>
#include "HeaderFiles/bSearchTreeType.h" // bSearchTreeType.h

using namespace std;

// HW3 Member function impletatiton
template<class T>
void bSearchTreeType<T>::countItems(T& countItem)
{
	bSearchTreeType<T> *temp = this;
    int count = 0;
    while (temp->search(countItem) != NULL)
    {
        temp->deleteNode(countItem);
        count++;
    }
    
    std::cout << count <<" for the search item " << countItem << std::endl;
}

int main()
{
/*
10
10 14 44 44 44 44 50 50 55 66

15
20 20 20 20 20 20 20 20 20 20 20 20 20 20 10

10
20 21 20 21 20 21 20 21 20 21

10
10 11 12 13 14 15 16 17 18 19
*/
    bSearchTreeType<int> BST;
    int input = 0, count = 0;
    char comm = '_';

    cout << "Enter number size: ";
    cin >> count;

    cout << "Enter number: ";
    for (int i = 0; i < count; i++)
    {
        cin >> input;
        BST.insert(input);
    }

    BST.inorderTraversal();

    cout << "\nSearch number: ";
    cin >> input;
    BST.countItems(input);

    return 0;
}