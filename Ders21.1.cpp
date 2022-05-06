#include <iostream>
#include "HeaderFiles/InheritingBinaryTreeBinarySearchTree_CT.h"

// UNION DATA TYPES

using namespace std;

int main(int argc, char const *argv[])
{
    InheritingBinaryTreeBinarySearchTree_CT<int> BST;
    int x = 10;
    BST.insert(x);
    cout << BST.treeHeight();

    return 0;
}