// MAKING HEADER FILE FOR BINARY SEARCH TREE

#include <assert.h>
#include "BinaryTree_CT.h"

namespace std
{
    template <typename T>
    class InheritingBinaryTreeBinarySearchTree_CT : protected BinaryTree_CT<T>
    {
    private:
        void deleteFromTreePriv(BinaryTreeNode<T> *&tempRoot, T &item);
        void recursiveInsertPriv(BinaryTreeNode<T> *&tempRoot, T &item)
        {
            if (!tempRoot)
            {
                tempRoot = new BinaryTreeNode<T>;
                tempRoot->info = item;
                tempRoot->leftLink = tempRoot->rightLink = NULL;
            }
            else if (item < tempRoot->info)
            {
                recursiveInsert(tempRoot->leftLink, item);
            }
            else
            {
                recursiveInsert(tempRoot->rightLink, item);
            }
        }

    protected:
        void recursiveInsertProt(T &item)
        {
            recursiveInsertPriv(root, item);
        }

    public:
        void recursiveInsert(T &item)
        {
            recursiveInsertProt(item);
        }
        BinaryTreeNode<T> *search(T &item)
        {
            BinaryTreeNode<T> *temp;
            bool found = false;

            if (root == NULL)
            {
                cerr << "Empty Tree" << endl;
            }
            else
            {
                temp = root;
                while (!found && temp != NULL)
                {
                    if (item == temp->info)
                    {
                        found = true;
                    }
                    else if (item < temp->info)
                    {
                        temp = temp->leftLink;
                    }
                    else
                    {
                        temp = temp->rightLink;
                    }
                }
            }

            return temp;
        }
        void insert(T &item)
        {
            BinaryTreeNode<T> *temp, *search, *father;
            temp->info = item;
            temp->leftLink = temp->rightLink = NULL;

            if (root == NULL)
            {
                root = temp;
            }
            else
            {
                search = root;
                while (search != NULL)
                {
                    father = search;
                    if (item < search->info)
                    {
                        search = search->leftLink;
                    }
                    else
                    {
                        search = search->rightLink;
                    }
                }
                if (father->info < temp->info)
                {
                    father->leftLink = temp;
                }
                else
                {
                    father->rightLink = temp;
                }
            }
        }
        void deleteNode(T &item)
        {
        }
    };

};