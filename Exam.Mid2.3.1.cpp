#include <iostream>
#include "HeaderFiles/LinkedListQueue_CT.hpp"

using namespace std;
// Exam.Mid2.3.1.cpp
// queue ==

/*
template <typename T>
bool operator==(const LinkedListQueue_CT &other) 
{
    if ((other.size() != size()) || (other.size() == 0) || (size() == 0))
    {
        return false;
    }
    int count = 0;
    QueueNode<T> *tempA = front;
    QueueNode<T> *tempB = other.front;

    while (tempA != NULL)
    {
        if (tempA->info == tempB->info)
        {
            count++;
            tempA = tempA->next;
            tempB = tempB->next;
        }
    }

    return (count == other.size());
}
*/
int main(int argc, char const *argv[])
{
    LinkedListQueue_CT<int> a, b;

    int x = 1;
    a.insert(x);
    x = 2;
    a.insert(x);
    x = 3;
    a.insert(x);
    x = 4;
    a.insert(x);

    x = 1;
    b.insert(x);
    x = 2;
    b.insert(x);
    x = 3;
    b.insert(x);
    x = 4;
    b.insert(x);

    if (b == a)
    {
        cout << "xD";
    }
    else
    {
        cout << "sadge";
    }

    return 0;
}