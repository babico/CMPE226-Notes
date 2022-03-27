#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList.h"

// Write a recursive function to output elements a LL in reverse order

using namespace std;

template <typename T>
void printrev(LLNode<T> *temp)
{
    if (temp != NULL)
    {
        printrev(temp->next);
        cout << temp->data << endl;
    }
}

int main()
{
    LLNode<int> *temp1 = new LLNode<int>;
    LLNode<int> *temp2 = new LLNode<int>;
    LLNode<int> *temp3 = new LLNode<int>;
    temp1->data = 1;
    temp1->next = temp2;
    temp2->data = 2;
    temp2->next = temp3;
    temp3->data = 3;
    temp3->next = NULL;

    printrev(temp1);

    return 0;
}