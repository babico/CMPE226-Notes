/*
CIRCULAR LINKED LINKEDLIST
*/

#include <iostream>

namespace std
{
    template <typename T>
    struct CNode
    {
        T data;
        CNode<T> *next;
    };
    template <typename T>
    class CircularLinkedList
    {
    protected:
        CNode<T> *head, *last;
        int count;

    public:
    };

}