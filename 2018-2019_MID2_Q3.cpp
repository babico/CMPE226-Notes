#include <iostream>
#include "HeaderFiles/LinkedList.h"

using namespace std;

int main()
{
    LinkedList<string> arr[6];

    string x = "Process-3";
    arr[1].insertLast(x);

    x = "Process-6";
    arr[1].insertLast(x);

    x = "Process-1";
    arr[4].insertLast(x);

    LLNode<string> *temp = arr[1].search("Process-6");

    if (temp != NULL)
    {
        arr[4].insertLast(temp->data);
    }
    arr[1].deleteNode("Process-6");
}