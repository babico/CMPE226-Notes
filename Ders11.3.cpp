#include <iostream>
#include "HeaderFiles/DoublyLinkedList_CT.h"
using namespace std;

// Write isFibonacci() member function in the Doubly LL
// class which returns true if the nodes in the list contains
// the fibonacci sequanece, false otherwise assume that ther are last int the list

// Doubly linklist örneği soruda var

/*
    template <typename T>
    bool DoublyLinkedList_CT<T>::isFibonacci()
    {
        DNode<T> *temp;
        bool fib = true;

        // 1   1   2   3   5
        //         ^

        if (head->data == 1 && head->right->data == 1)
        {
            temp = head->right->right;
            while ((temp != NULL) && fib)
            {
                if (temp->data == temp->left->data + temp->left->left->data)
                {
                    temp = temp->right;
                }
                else
                {
                    fib = false;
                }
            }
        }

        return fib;
    }
*/
int main(int argc, char const *argv[])
{
    DoublyLinkedList_CT<int> fib;
    fib.isFibonacci();
    return 0;
}