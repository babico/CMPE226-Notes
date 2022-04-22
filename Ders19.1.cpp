#include <iostream>
#include "HeaderFiles/BinaryTree_CT.h"

// BINARY TREE

using namespace std;

int main(int argc, char const *argv[])
{
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>;
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>;
    BinaryTreeNode<int> *node3 = new BinaryTreeNode<int>;
    /*
              1
             / \
            2   3
    */
    node1->info = 1;
    node1->leftLink = node2;
    node1->rightLink = node3;

    node2->info = 2;
    node2->leftLink = NULL;
    node2->rightLink = NULL;

    node3->info = 3;
    node3->leftLink = NULL;
    node3->rightLink = NULL;

    return 0;
}