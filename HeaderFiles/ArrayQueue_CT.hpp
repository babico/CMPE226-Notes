// MAKING HEADER FILE FOR QUEUE

#include <assert.h>
namespace std
{
    template <typename T>
    class ArrayQueue_CT
    {
    private:
        int maxSize,
            front,
            rear,
            count;
        T *list;

    public:
        ArrayQueue_CT(int size = 100)
        {
            maxSize = size;
            front = count = 0;
            rear = maxSize -1;
            list = new T[maxSize];
        }
        ~ArrayQueue_CT()
        {
            delete[] list;
        }
        bool isEmpty()
        {
            return count == 0;
        }
        bool isFull()
        {
            return count == maxSize;
        }
        void insert(T &item)
        {
            if (!isFull())
            {
                rear = (rear + 1) % maxSize;
                list[rear] = item;
                count++;
            }
            else
            {
                cerr << "Stack Full" << endl;
            }
        }
        T deleteQueue()
        {
            T x;
            if (!isEmpty())
            {
                x = list[front];
                front = (front + 1) % maxSize;
                count--;
                return x;
            }
            else
            {
                cerr << "Stack Empty" << endl;
            }
        }
        int getCount()
        {
            return count;
        }
        void destroyQueue()
        {
            front = count = 0;
            rear = maxSize - 1;
        }
        T frontQueue()
        {
            assert(!isEmpty());
            return list[front];
        }
        T rearQueue()
        {
            assert(!isEmpty());
            return list[rear];
        }
    };
}