#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *n, *t, *h;

    n = new Node;
    n->data = 1;
    t = n;
    h = n;

    cout << n->data << endl;
    cout << t->data << endl;
    cout << h->data << endl;

    n = new Node;
    n->data = 2;
    t->next = n; // t = n;
    t = t->next;

    cout << n->data << endl;
    cout << t->data << endl;

    n = new Node;
    n->data = 3;
    n->next = NULL;
    t->next = n;

    cout << n->data << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << n->data << endl;
    cout << t->data << endl;
    cout << h->data << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << h->next->next->data << endl;
    cout << h->next->data << endl;
    cout << h->data << endl;
}