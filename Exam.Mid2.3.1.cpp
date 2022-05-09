// queue ==

#include <iostream>
#include "HeaderFiles/LinkedListQueue_CT.h"

using namespace std;

// bool LinkedListQueue_CT::operator==(const LinkedListQueue_CT &other)
// {
//     if ((other.size() != this->size()) || (other.size() == 0) || (this->size() == 0))
//     {
//         return 0;
//     }
//     int count = 0;
//     QueueNode<T> tempA = this->front;
//     QueueNode<T> tempB = other.front;

//     if (tempA.info == tempB.info)
//     {
//         count++;
//     }

//     return count == other.size();
// }

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