#include <iostream>
#include <assert.h>
// INSERT ANY NODE CONTAINING X TO THE FRONT OF A LIST
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *n, *t, *h, *p;

    n = new Node;
    n->data = 1;
    t = n;
    h = n;

    n = new Node;
    n->data = 2;
    t->next = n; // t = n;
    t = t->next;

    n = new Node;
    n->data = 3;
    n->next = NULL;
    t->next = n;

    cout << h->data << h->next->data << h->next->next->data << endl;

    int x;
    cout << "Enter number: ";
    cin >> x;
    p = new Node;
    assert(p != NULL);
    p->data = x;
    p->next = h;
    h = p;

    cout << h->data << h->next->data << h->next->next->data << h->next->next->next->data;
}