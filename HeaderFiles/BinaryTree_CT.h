// MAKING HEADER FILE FOR STACK

#include <assert.h>
#include "./LinkedListStack_CT.h"
namespace std
{
    template <typename T>
    struct BinaryTreeNode
    {
        T info;
        BinaryTreeNode<T> *leftLink, *rightLink;
    };

    template <typename T>
    class BinaryTree_CT
    {
    protected:
        BinaryTreeNode<T> *root;
        void destroyP(BinaryTreeNode<T> *&temp) // & ile pointer olarak fonksiyona yollanan değişkende manüpile edilebiliiyor
        {
            if (temp != NULL)
            {
                destroyP(temp->leftLink);
                destroyP(temp->rightLink);
                delete temp;
                temp = NULL;
            }
        }
        void nonrecursiveInOrderP()
        {
            // NONRECURSIVE INORDER TREVARSAL

            LinkedListStack_CT<BinaryTreeNode<T>*> s;
            BinaryTreeNode<T> *temp = root;
            while ((temp != NULL) || (!s.isEmpty()))
            {
                if (temp != NULL)
                {
                    s.push(temp);
                    temp = temp->leftLink;
                }
                else
                {
                    temp = s.pop();
                    cout << temp->info;
                    temp = temp->rightLink;
                }
            }
        }
        void inOrderP(BinaryTreeNode<T> *temp)
        {
            // RECURSIVE INORDER TREVARSAL

            if (temp != NULL)
            {
                inOrderP(temp->leftLink);
                cout << temp->info;
                inOrderP(temp->rightLink);
            }
        }
        void preOrderP(BinaryTreeNode<T> *temp)
        {
            if (temp != NULL)
            {
                cout << temp->info;
                preOrderP(temp->leftLink);
                preOrderP(temp->rightLink);
            }
        }
        void postOrderP(BinaryTreeNode<T> *temp)
        {
            if (temp != NULL)
            {
                preOrderP(temp->leftLink);
                preOrderP(temp->rightLink);
                cout << temp->info;
            }
        }

        int maxP(int x, int y)
        {
            if (x >= y)
            {
                return x;
            }
            else
            {
                return y;
            }
        }
        int heightP(BinaryTreeNode<T> *temp)
        {
            if (temp == NULL)
            {
                return 0;
            }
            else
            {
                return 1 + maxP(heightP(temp->leftLink), heightP(temp->rightLink));
            }
        }
        int nodeCountP(BinaryTreeNode<T> *temp)
        {
            if (temp == NULL)
            {
                return 0;
            }
            else
            {
                return 1 + nodeCountP(temp.leftLink) + nodeCountP(temp->rightLink);
            }
        }
        int leavesCountP(BinaryTreeNode<T> *temp)
        {
            if (temp == NULL)
            {
                return 0;
            }
            else if ((temp->leftLink == NULL) && (temp->rightLink == NULL))
            {
                return 1;
            }
            else
            {
                return leavesCountP(temp->leftLink) + leavesCountP(temp->rightLink);
            }
        }

    public:
        BinaryTree_CT()
        {
            root = NULL;
        }
        ~BinaryTree_CT()
        {
            destroyP(root);
        }

        bool isEmpty()
        {
            return root == NULL;
        }

        void inOrder()
        {
            inOrderP(root);
        }
        void preOrder()
        {
            preOrderP(root);
        }
        void postOrder()
        {
            postOrderP(root);
        }

        void nonrecursiveInOrder()
        {
            nonrecursiveInOrderP(root);
        }

        int treeHeight()
        {
            return heightP(root);
        }
        int nodeCount()
        {
            return nodeCountP(root);
        }
        int leavesCount()
        {
            return leavesCountP(root);
        }
    };

}