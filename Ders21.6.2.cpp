/*
    Write a member function called in the QUEUE class implanted
    with linked list. For all the values in the queue, the function will remove the multiple
    occurence of those values and leave only their 1st occurence in the queue

    3 -> 5 -> 3 -> 5 -> 7 -> 3

    3 -> 5 -> 7
*/

#include <iostream>
#include "HeaderFiles/LinkedListQueue_CT.hpp"

using namespace std;

template<typename T>
void LinkedListQueue_CT<T>::unique()
{
    // 3 -> 5 -> 3 -> 5 -> 7 -> 3
    // 3 -> 5 -> -> 7
    QueueNode<T> *p, *q, *prev;
    p = front;
    while (p != NULL)
    {
        q = p->next;
        prev = p;

        while (q != NULL)
        {
            if (p->info == q->info)
            {
                prev->next = q->next;
                if (q == rear)
                {
                    rear = prev;
                }
                delete q;
                q = prev->next;
            }
            else
            {
                prev = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
