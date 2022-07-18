#include <iostream>

using namespace std;

/* LinkedListNode */
class LinkedListNode
{
public:
    int key;                        /* Key */
    LinkedListNode *prev = nullptr; /* Pointer to the previous node */
    LinkedListNode *next = nullptr; /* Pointer to the next node */
    bool operator==(const LinkedListNode &node)
    {
        return this->key == node.key;
    }
};

class SortedLinkedList
{
private:
    LinkedListNode *head, *tail; /* Head and tail of the list of nodes */
    int noOfNodes;               /* Current number of nodes in the list */

public:
    /***********************************************
     * Constructor: Initializes the linked list
     ***********************************************/
    SortedLinkedList()
    {
        this->head = this->tail = nullptr;
        noOfNodes = 0;
    }
    /***********************************************
     * Removes all of the nodes from this list.
     ***********************************************/
    void Clear()
    {
        this->head = this->tail = nullptr;
        noOfNodes = 0;
    }
    /***********************************************
     * Returns the number of nodes in the list
     ***********************************************/
    int NoOfNodes()
    {
        return noOfNodes;
    }
    /***********************************************
     * Returns the forward index of node
     ***********************************************/
    int ForwardIndex(int key)
    {
        int cnt = 1;
        LinkedListNode *temp = head;
        while (temp->key != key)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;    
    }
    /***********************************************
     * Returns the backward index of node
     ***********************************************/
    int BackwardIndex(int key)
    {
        int cnt = 1;
        LinkedListNode *temp = tail;
        while (temp->key != key)
        {
            temp = temp->prev;
            cnt++;
        }
        return cnt;
    }
    /***********************************************
     * Inserts the given key in ascending order in the list
     ***********************************************/
    void Add(int key)
    {
        // Add 1 to node counter
        noOfNodes++;
        // Create a node
        LinkedListNode *node = new LinkedListNode;
        node->key = key;
        if (head == nullptr)
        {
            // Add first node
            this->tail = this->head = node;
            return;
        }
        // // Add node at the end position
        // tail->next = node;
        // node->prev = tail;
        // tail = tail->next;

        LinkedListNode *temp = this->head;
        while (temp != nullptr)
        {
            if (temp->key > node->key)
            {
                node->prev = temp->prev;
                node->next = temp;
                temp->prev->next = node;
                temp->prev = node;
                return;
            }

            temp = temp->next;
        }

        this->tail->next = node;
        node->prev = this->tail;
        this->tail = this->tail->next;
    }
    /***********************************************
     * Removes the node that contains the key from the list
     * (if the key is found)
     * Returns 0 upon successful deletion, -1 on error
     ***********************************************/
    void Remove(int key)
    {
        if (head == nullptr)
        {
            cerr << "List is blank!"
                 << "\n";
        }

        // Minus 1 to node counter
        noOfNodes--;
        if (this->head->key == key)
        {
            LinkedListNode *temp = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete temp;
            return;
        }
        if (this->tail->key == key)
        {
            LinkedListNode *temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete temp;
            return;
        }

        LinkedListNode *temp = this->head;
        while (temp->key != key)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = temp->prev = nullptr;
        delete temp;
    }
    /************************************************
     * Removes a node from the list given a pointer to the node
     ***********************************************/
    void Remove(LinkedListNode node)
    {
        if (head == nullptr)
        {
            cerr << "List is blank!"
                 << "\n";
        }

        // Minus 1 to node counter
        noOfNodes--;
        LinkedListNode *temp = head;
        if (*this->head == node)
        {
            LinkedListNode *temp2 = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete temp2;
            return;
        }
        if (*this->tail == node)
        {
            LinkedListNode *temp2 = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete temp2;
            return;
        }
        while (temp != nullptr)
        {
            if (node == *temp)
            {
                break;
            }
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = temp->prev = nullptr;
    }
    /************************************************
     * Print list ascending order
     ***********************************************/
    void PrintAscending()
    {
        if (head == nullptr)
        {
            cerr << "List is blank!"
                 << "\n";
        }

        LinkedListNode *temp = this->head;
        while (temp != nullptr)
        {
            cout << temp->key << " ";
            temp = temp->next;
        }
    }
    /************************************************
     * Print list descending order
     ***********************************************/
    void PrintDescending()
    {
        if (head == nullptr)
        {
            cerr << "List is blank!"
                 << "\n";
        }

        LinkedListNode *temp = this->tail;
        while (temp != nullptr)
        {
            cout << temp->key << " ";
            temp = temp->prev;
        }
    }
    /************************************************
     * Searches a key in the list and returns a pointer
     * to the list node that contains the key
     ***********************************************/
    LinkedListNode Find(int key)
    {
        if (head == nullptr)
        {
            cerr << "List is blank!"
                 << "\n";
        }

        LinkedListNode *node = head;
        while (node != nullptr)
        {
            if (node->key == key)
            {
                break;
            }
            node = node->next;
        }

        return *node;
    }
};