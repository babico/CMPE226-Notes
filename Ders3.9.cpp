#include <iostream>
// READ A NUMBER, SEARCH FOR IT IN THE LL IF ADD FOUND 3 TO IT
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
    cout << "enter number: ";
    cin >> x;
    p = h;
    while ((p != NULL) && (p->data != x))
    {
        p = p->next;
    }
    if (p != NULL)
    {
        p->data += 3;
    }
    else
    {
        cout << "not found";
    }

    cout << h->data << h->next->data << h->next->next->data << endl;
}