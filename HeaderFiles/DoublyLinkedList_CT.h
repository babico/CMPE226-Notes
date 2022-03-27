/*
DOUBLY LINKED LINKEDLIST
*/

#include <iostream>

namespace std
{
    template <typename T>
    struct DNode
    {
        T data;
        DNode<T> *right, *left;
    };
    
    template <typename T>
    class DoublyLinkedList_CT
    {
    protected:
        DNode<T> *head, *last;
        int count;

    public:
        DoublyLinkedList_CT()
        {
            count = 0;
            head = last = NULL;
        }
        void insertLast(T &item)
        {
            DNode<T> *temp = new Node<T>;
            temp->info = item;
            temp->right = NULL;
            if (head != NULL)
            {
                last->right = temp;
                temp->left = last;
                last = temp;
            }
            else
            {
                head = last = temp;
                temp->left = NULL;
            }

            count++;
        }
        Node<T> *search(T &item);
        /*
            Write a function in the DoublyLinkedList class
            which recives an item & searches for it in the list list.
            If found, it deletes all nodes occuruing before the found node
        */
        void deleteRest(T &item)
        {
            DNode<T> *temp, *tempPrev1, *tempPrev2;
            temp = search(item);

            if (temp = NULL)
            {
                cout << "Not Found!";
            }
            else
            {
                tempPrev1 = temp->left;
                while (tempPrev1 != NULL)
                {
                    tempPrev2 = tempPrev1->left;
                    delete tempPrev1;
                    tempPrev1 = tempPrev2;
                    count--;
                }
                head = temp;
                head->left = NULL;
            }
        }
    };
}
