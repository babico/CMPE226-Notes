// MAKING HEADER FILE FOR LINKEDLIST QUEUE

#include <assert.h>

namespace std
{
    template <typename T>
    struct QueueNode
    {
        T info;
        QueueNode<T> *next;
    };

    template <typename T>
    class LinkedListQueue_CT
    {
    private:
        int count = 0;
        QueueNode<T> *front, *rear;

    public:
        LinkedListQueue_CT()
        {
            front = rear = NULL;
        }
        ~LinkedListQueue_CT()
        {
            destroyQueue();
        }
        int size() const
        {
            return count;
        }
        T frontQueue()
        {
            assert(!isEmpty());
            return front->info;
        }
        T rearQueue()
        {
            assert(!isEmpty());
            return rear->info;
        }
        T deleteQueue()
        {
            assert(!isEmpty());
            QueueNode<T> *temp;
            T item;

            temp = front;
            item = temp->info;
            front = temp->next;

            if (front == NULL)
            {
                rear = NULL;
            }

            count--;
            delete temp;
            return item;
        }

        bool isEmpty()
        {
            return front == NULL; // rear == NULL // samething
        }

        void insert(T &item)
        {
            QueueNode<T> *temp = new QueueNode<T>;
            temp->info = item;
            temp->next = NULL;
            if (front == NULL)
            {
                front = rear = temp;
            }
            else
            {
                rear->next = temp;
                rear = temp;
            }
            count++;
        }
        void destroyQueue()
        {
            QueueNode<T> *temp;
            while (front != NULL)
            {
                temp = front;
                front = front->next;
                delete temp;
            }
            rear = NULL;
            count = 0;
        }
        bool operator==(const LinkedListQueue_CT &other) // Exam.Mid2.3.1.cpp
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
    };
}