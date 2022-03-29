#include <iostream>
// BUILDING LINKLIST IN BACKWARD DIRECTION
using namespace std;

template <class T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
Node<T> *createBackward()
{
    Node<T> *head, *curr;
    int num;
    cout << "Enter number: ";
    cin >> num;
    head = NULL;

    while (num != -99)
    {
        curr = new Node<T>;
        curr->data = num;
        curr->next = head;
        head = curr;
        cin >> num;
    }
    return head;
}

int main()
{
    Node<int> *h, *p;
    h = createBackward<int>();

    cout << "printing" << endl;
    p = h;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}