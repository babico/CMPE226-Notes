#include <iostream>
// BUILDING LINKLIST IN BACKWARD DIRECTION
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createBackward()
{
    Node *head, *curr;
    int num;
    cout << "Enter number: ";
    cin >> num;
    head = NULL;

    while (num != -99)
    {
        curr = new Node;
        curr->data = num;
        curr->next = head;
        head = curr;
        cin >> num;
    }
    return head;
}

int main()
{
    Node *h, *p;
    h = createBackward();

    cout << "printing" << endl;
    p = h;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}