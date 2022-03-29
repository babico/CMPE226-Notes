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
            DNode<T> *temp = new DNode<T>;
            temp->data = item;
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
        DNode<T> *search(T &item);
        /*
            Write a function in the DoublyLinkedList class
            which recives an item & searches for it in the list list.
            If found, it deletes all nodes occuruing before the found node
        */

        void delEvenIndex() // Mid1 Question
        {
            DNode<T> *temp, *temp2;
            temp = head;
            if (count > 1)
            {
                temp2 = temp->right;
            }
            bool valid = (count % 2 == 0);

            if (head == NULL)
            {
                cerr << "List is empty";
                return;
            }
            if (count == 1)
            {
                cerr << "List has only 1 node";
                return;
            }
            for (int i = 0; i < (count / 2); i++)
            {
                temp->right = temp2->right;
                if (count > 2)
                {
                    temp2->right->left = temp;
                }
                delete temp2;
                temp = temp->right;
                if (count > 2)
                {
                    temp2 = temp->right;
                }
            }
            if (valid)
            {
                temp = head;
                for (int i = 0; i < count; i++)
                {
                    temp->right;
                }
                last = temp;
            }
        }
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
        bool isFibonacci() // Ders11.3.cpp
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

        template <typename S>
        friend ostream &operator<<(ostream &out, const DoublyLinkedList_CT<S> &list)
        {
            DNode<T> *temp = list.head;
            while (temp != NULL)
            {
                out << temp->data << " ";
                temp = temp->right;
            }
            return out;
        }
    };
}
