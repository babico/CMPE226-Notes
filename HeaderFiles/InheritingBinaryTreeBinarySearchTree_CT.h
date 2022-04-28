// MAKING HEADER FILE FOR BINARY SEARCH TREE

#include <assert.h>
#include "BinaryTree_CT.h"
namespace std
{

    template <typename T>
    class InheritingBinaryTreeBinarySearchTree_CT::public BinaryTree_CT<T>
    {
    private:
        void deleteFromTree(BinaryTreeNode<T> *&temp)
    protected:
    public:
        BinaryTreeNode<T> *search(T &temp);
        void insert(T &temp);
        void deleteNode(T &temp);
    };

}