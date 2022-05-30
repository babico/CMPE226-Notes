#include <iostream>
#include "HeaderFiles/bSearchTreeType.h" // bSearchTreeType.h

using namespace std;

template <class T>
int occurrences(bSearchTreeType<T> *root, T searchItem)
{
    int count = 0;
    binaryTreeNode<T> *tempNode = root->search(searchItem);
    while (tempNode != NULL)
    {
        if (tempNode->info == searchItem)
        {
            count++;
        }
        if (tempNode->info > searchItem)
        {
            tempNode = tempNode->llink;
        }
        else
        {
            tempNode = tempNode->rlink;
        }
    }
    return count;
}
int main()
{
    bSearchTreeType<int> binarySTree;
    int num, searchItem, x;
    cout << "Enter numbers ending with -1:" << endl;
    cin >> num;
    while (num != -1)
    {
        binarySTree.insert(num);
        cin >> num;
    }
    if (binarySTree.isEmpty())
    {
        cout << "Binary search tree is empty.";
    }
    else
    {
        cout << "\nEnter the number to be repeated: ";
        cin >> searchItem;
    }
    x = occurrences<int>(&binarySTree, searchItem);
    cout << x;
    return 0;
}