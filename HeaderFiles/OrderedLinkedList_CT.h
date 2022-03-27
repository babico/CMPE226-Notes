/*
ORDERED LINKEDLIST
*/

#include <iostream>

namespace std
{
    template <typename T>
    struct ONode
    {
        T data;
        ONode<T> *next;
    };
    template <typename T>
    class OrderedLinkedList
    {
    protected:
        ONode<T> *head, *last;
        int count;

    public:
        OrderedLinkedList()
        {
            count = 0;
            head = last = NULL;
        }
        void insert(T &item)
        {
        }
        ONode<T> *search(T &item)
        {
            ONode<T> *temp = head;
            while (temp != NULL)
            {
                if (item > temp->data)
                {
                    temp = temp->next
                }
                else if (item == temp->data)
                {
                    return temp;
                }
                else
                {
                    return NULL;
                }
            }
        }
    };

}
