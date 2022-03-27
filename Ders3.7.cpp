#include <iostream>
// BUUDING LINKLIST IN FORWARD DIRECTION
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createForward()
{
    Node *head, *last, *curr;
    int num;

    cout << "Enter number: ";
    cin >> num;

    head = NULL;
    while (num != -99)
    {
        curr = new Node;
        curr->data = num;
        curr->next = NULL;
        if (head == NULL)
        {
            head = curr;
        }
        else
        {
            last->next = curr;
        }
        last = curr;
        cin >> num;
    }
    return head;
}

int main()
{
    Node *h, *p;
    h = createForward();

    p = h;
    while(p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}