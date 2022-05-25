// MAKING HEADER FILE FOR BINARY SEARCH TREE

#include <assert.h>

namespace std
{
    template <typename T>
    struct BinaryTreeNode
    {
        T info;
        BinaryTreeNode<T> *leftLink, *rightLink;
    };

    template <typename T>
    class BinarySearchTree_CT
    {
    private:
        BinaryTreeNode<T> *root;
        void deleteNodePriv(const T &item)
        {
            BinaryTreeNode<T> *curr, *prev;
            bool found = false;

            if (root == NULL)
            {
                cerr << "Empty Tree!";
            }
            else
            {
                curr = prev = root;
                while (!found && curr != NULL)
                {
                    if (curr->info == item)
                    {
                        found = true;
                    }
                    else
                    {
                        curr = curr->rightLink;
                    }
                }
                if (!found)
                {
                    cout << "Item Not Found!";
                }
                else
                {
                    if (curr == root)
                    {
                        deleteFromTreePriv(root);
                    }
                    else if (item < prev->info)
                    {
                        deleteFromTreePriv(prev->leftLink);
                    }
                    else
                    {
                        deleteFromTreePriv(prev->rightLink);
                    }
                }
            }
            
        }
        void deleteFromTreePriv(const BinaryTreeNode<T> *&p)
        {
            BinaryTreeNode<T> *curr, *prev, *temp;

            // Leaf Node
            if (p->leftLink == NULL && p->rightLink == NULL)
            {
                delete p;
                p = NULL;
            }
            // Right One Child
            else if (p->leftLink == NULL) 
            {
                temp = p;
                p = temp->rightLink;
                delete temp;
            }
            // Left One Child
            else if (p->rightLink == NULL)
            {
                temp = p;
                p = temp->leftLink;
                delete temp;
            }
            // Right & Left Two Child
            // Find inorder predecessor (right node of the left subtree of p.)
            else
            {
                curr = p->leftLink;
                prev = NULL;
                while (curr->rightLink != NULL)
                {
                    prev = curr;
                    curr = curr->rightLink;
                }
                p->info = curr->info;
                if (prev == NULL)
                {
                    p->leftLink = curr->leftLink;
                }
                else
                {
                    prev->rightLink = curr->leftLink;
                }
                delete curr;
            }
        }
        void insertPriv(const T &item)
        {
            BinaryTreeNode<T> *p, *q, *r;
            r = new BinaryTreeNode<T>;
            r->info = item;
            r->leftLink = r->rightLink = NULL;

            if (root == NULL)
            {
                root = r;
            }
            else
            {
                p = root;
                while (p != NULL)
                {
                    q = p;
                    if (item < p->info)
                    {
                        p = p->leftLink;
                    }
                    else
                    {
                        p = p->rightLink;
                    }
                }
                if (item < q->info)
                {
                    q->leftLink = r;
                }
                else
                {
                    q->rightLink = r;
                }
            }
        }
        void recursiveInsertPriv(const BinaryTreeNode<T> *&p, const T &item)
        {
            if (!p) // or (p == NULL)
            {
                p = new BinaryTreeNode<T>;
                p->info = item;
                p->leftLink = p->rightLink = NULL;
            }
            else if (item < p->info)
            {
                recursiveInsert(p->leftLink, item);
            }
            else
            {
                recursiveInsert(p->rightLink, item);
            }
        }
        BinaryTreeNode<T>* searchPriv(const T &item)
        {
            BinaryTreeNode<T> *p;
            bool found = false;
            if (root == NULL)
            {
                cerr << "Empty Tree!" << endl;
            }
            else
            {
                p = root;
                while (!found && p != NULL)
                {
                    if (p->info == item)
                    {
                        found = true;
                    }
                    else if (item < p->info)
                    {
                        p = p->leftLink;
                    }
                    else
                    {
                        p = p->rightLink;
                    }
                }
                return p;
            }
        }
    protected:
        void recursiveInsertP(const T &item)
        {
            recursiveInsertPriv(root, item);
        }
    public:
        BinarySearchTree_CT()
        {
            root = NULL;
        }
        ~BinarySearchTree_CT()
        {
            //destroyP(root);
        }

        BinaryTreeNode<T> *search(const T &item)
        {
            return searchPriv(item); 
        }
        void deleteNode(const T &item)
        {
            deleteNodePriv(item);
        }
        void insert(const T &item)
        {
            insertPriv(item);
        }
        void recursiveInsert(const T &item)
        {
            recursiveInsertP(item);
        }
    };

};