#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
struct Node
{
    T info;
    Node<T> *next;
};

template <typename T>
class LL
{
private:
    Node<T> *head, *last;
    int count;

public:
    LL()
    {
        count = 0;
        head = last = NULL;
    }
    ~LL()
    {
        destroyList();
    }

    int getcount() { return count; }
    Node<T> *gethead() { return head; }
    Node<T> *getlast() { return last; }

    void setcount(int c) { count = c; }
    void sethead(Node<T> *h) { head = h; }
    void setlast(Node<T> *l) { last = l; }

    T back()
    {
        assert(last != NULL);
        return last->info;
    }
    T front()
    {
        assert(head != NULL);
        return head->info;
    }
    int length()
    {
        return count;
    }
    bool isEmpty()
    {
        return (count == 0) ? true : false;
    }

    void destroyList()
    {
        Node<T> *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        count = 0;
        last = NULL;
    }

    void insertFirst(T &data)
    {
        Node<T> *temp;
        temp->info = data;
        temp->next = head;
        head = temp;

        if (last == NULL)
        {                // listede node olup olmadığını kontrol etme
            last = temp; // listede node yoksa last değişkenini atama
        }
        count++;
    }
    void insertLast(T &data)
    {
        Node<T> *temp;
        temp->info = data;
        temp->next = NULL;

        if (head != NULL)
        {                      // listede node olup olmadığını kontrol etme
            last->next = temp; // olan son nodeun sonrasına temp atama
            last = temp;       // son nodeu geçici node olarak atama
        }
        else
        {
            head = last = temp; // liste boşsa geçici nodeu atama
        }

        count++;
    }

    Node<T> *search(T &data)
    {
        Node<T> *p;
        p = head;
        bool found = false;
        while (p != NULL && !found)
        {
            if ((!found) && (p->info == data)) // !!!!data bir obje ise "==" operatörünün o objede tanımlı olması gerek!!!!
            {
                found = true;
            }
            else
            {
                p = p->next;
            }
        }
        return p;
    }

    void deleteNode(T &data)
    {
        Node<T> *temp1, *temp2;
        bool found = false;
        if (head->info == data)
        {
            temp1 = head;
            head = head->next;
            delete temp1;
            count--;

            if (head == NULL) // listede node kaldı mı diye kontrol etme
            {
                last = NULL; // listede node kalmadıysa last göstergesini boşa çıkarma;
            }
        }
        else
        {
            temp1 = head;
            temp2 = temp1->next;
            while (!found && temp2 != NULL)
            {
                if (temp2->info == data)
                {
                    found = true;
                }
                else
                {
                    temp1 = temp2;
                    temp2 = temp1->next;
                }
            }
            if (found)
            {
                temp1->next = temp2->next;
                if (last = temp2)
                {
                    last = temp1;
                }
                count--;
                delete temp2;
            }
        }
    }

    friend ostream &operator<<(ostream &out, LL<T> &list)
    {
        Node<T> *temp;
        temp = list.head;
        while (temp == NULL)
        {
            out << temp->info << endl;
            temp = temp->next;
        }
        return out;
    }
};