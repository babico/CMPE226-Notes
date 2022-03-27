// MAKING HEADER FILE FOR STACK

#include <assert.h>
namespace std
{
    template <typename T>
    class ArrayStack_CT
    {
    private:

    public:
        int size;
        int top;
        T *arr;

        ArrayStack_CT(int stackSize = 100)
        {
            size = stackSize;
            top = 0;
            arr = new T[size];
        }
        ~ArrayStack_CT()
        {
            delete[] arr;
        }

        bool isEmpty()
        {
            return top == 0;
        }
        bool isFull()
        {
            return top == size;
        }
        void destroy()
        {
            top = 0;
        }
        T pop()
        {
            assert(!isEmpty());
            return arr[--top];
        }
        void push(T &item)
        {
            if (!isFull())
            {
                arr[top++] = item;
            }
            else
            {
                cerr << "Stack is Full!!";
            }
        }
        T sTop()
        {
            assert(!isEmpty());
            return  arr[top-1];
        }
    };
}