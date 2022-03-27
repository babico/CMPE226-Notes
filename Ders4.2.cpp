#include <iostream>
// READ AN INTIGER X AND INSERT IT INTO ITS PROPER PLACE IN A LL SORTED IN ASCENDING ORDER
using namespace std;

struct Node
{
    int data;
    Node *next;
};
int main()
{
    int x;
    Node *n, *t, *h, *g;

    n = new Node;
    n->data = 3;
    h = n;
    t = n;
    g = n;

    n = new Node;
    n->data = 5;
    h->next = n;
    t = n;
    g = n;
    
    n = new Node;
    n->data = 8;
    t->next = n;
    g = n;
    
    n = new Node;
    n->data = 12;
    n->next = NULL;
    g->next = n;

    cout << h->data << " " << h->next->data << " " << h->next->next->data << " " << h->next->next->next->data;

    Node *p, *q, *s;
    cout << endl << "enter: ";
    cin >> x;
    p = h;
    while ((p != NULL) && (x > p->data))
    {
        q = p;
        p = p->next;
    }

    s = new Node;
    s->data = x;
    s->next = p;

    if (p == h)
    {
        h = s;
    }
    else
    {
        q->next = s;
    }

    cout << h->data << " " << h->next->data << " " << h->next->next->data << " " << h->next->next->next->data << " " << h->next->next->next->next->data;
}