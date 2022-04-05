// MAKING HEADER FILE FOR LINKEDLIST STACK

#include <assert.h>

namespace std
{
    template <typename T>
    struct StackNode
    {
        T info;
        StackNode<T> *next;
    };

    template <typename T>
    class LinkedListStack_CT
    {
    private:
        StackNode<T> *top;

    public:
        LinkedListStack_CT()
        {
            top = NULL;
        }
        ~LinkedListStack_CT()
        {
            destroy();
        }

        T sTop()
        {
            assert(!isEmpty());
            return top->info;
        }
        T pop()
        {
            assert(!isEmpty());
            StackNode<T> *temp;
            temp = top;
            top = top->next;
            T item = temp->info;
            delete temp;
            return item;
        }

        bool isEmpty()
        {
            return top == NULL;
        }

        void push(const T &item)
        {
            StackNode<T> *temp = new StackNode<T>;
            temp->info = item;
            temp->next = top;
            top = temp;
        }
        void destroy()
        {
            StackNode<T> *temp;
            while (top != NULL)
            {
                temp = top;
                top = top->next;
                delete temp;
            }
        }
    };

}