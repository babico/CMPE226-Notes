#include <iostream>
#include "HeaderFiles/DoublyLinkedList_CT.hpp"

using namespace std;
/*  // Mid1 Question
    void DoublyLinkedList_CT::delEvenIndex()
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
*/

int main(int argc, char const *argv[])
{
    DoublyLinkedList_CT<int> liste, liste2, liste3, liste4;
    int x;
    /*
        Example Output:
        1 3 5 4 7
        1 5 7
    */
    x = 1;
    liste.insertLast(x);

    x = 3;
    liste.insertLast(x);

    x = 5;
    liste.insertLast(x);

    x = 4;
    liste.insertLast(x);

    x = 7;
    liste.insertLast(x);

    cout << liste << endl;
    liste.delEvenIndex();
    cout << liste << endl
         << endl;

    /*
        Example Output:
        1 3
        1
    */
    x = 1;
    liste2.insertLast(x);

    x = 3;
    liste2.insertLast(x);

    cout << liste2 << endl;
    liste2.delEvenIndex();
    cout << liste2 << endl
         << endl;

    /*
        Example Output:
        1
        List has only 1 node
    */
    x = 1;
    liste3.insertLast(x);

    cout << liste3 << endl;
    liste3.delEvenIndex();
    cout << endl << endl;

    /*
            Example Output:
            List is empty
    */
    liste4.delEvenIndex();

    return 0;
}