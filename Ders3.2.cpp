#include <iostream>
// INSERT NODE
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

    p = new Node;
    p->data = 5;
    p->next = h->next;
    h->next = p;

    cout << h->data << h->next->data << h->next->next->data << h->next->next->next->data;
}