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
            QueueNode *temp;
            T item;

            temp = front;
            item = temp->info;
            front = temp->next;

            if (front == NULL)
            {
                rear = NULL;
            }

            delete temp;
            return item;
        }

        bool isEmpty()
        {
            return front == NULL; // rear == NULL // samething
        }

        void insert(T &item)
        {
            QueueNode<T> *temp = new QueueNode;
            temp->info = item;
            temp->next = NULL;
            if (front == NULL)
            {
                front = rear = temp;
            }
            else
            {
                rear->info = temp;
                rear = temp;
            }
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
        }
    };
}