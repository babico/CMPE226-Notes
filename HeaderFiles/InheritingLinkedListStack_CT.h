// MAKING HEADER FILE FOR INHERITED LINKEDLIST STACK

#include "LinkedList_CT.h"

namespace std
{
    template <typename T>
    class InheritingLinkedListStack_CT::public LinkedList_CT<T>
    {
    public:
        InheritingLinkedListStack_CT()
        {

        }
        bool isEmpty()
        {
            return emptyList();
        }
        void push(cosnt T &item)
        {
            insertFirst(item);
        }
        T pop()
        {

        }
        T sTop()
        {
            return front()
        }
    };
    
}