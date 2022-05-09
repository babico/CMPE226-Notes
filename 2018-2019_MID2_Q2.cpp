#include <iostream>
#include "HeaderFiles/LinkedListStack_CT.h"

using namespace std;

int main()
{
    LinkedListStack_CT<int> uniq;
    LinkedListStack_CT<int> dup;

    uniq.push(1);
    uniq.push(2);
    uniq.push(2);
    uniq.push(4);
    uniq.push(5);
    uniq.push(5);

    int size = uniq.size();
    for (int i = 0; i < size; i++)
    {
        dup.push(uniq.pop());
        if (uniq.sTop() == dup.sTop())
        {
            dup.pop();
        }
    }
}