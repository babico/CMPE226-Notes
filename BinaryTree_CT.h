// MAKING HEADER FILE FOR STACK

#include <assert.h>
namespace std
{
    template<typename T>
    struct BinaryTreeNode
    {
        T info;
        BinaryTreeNode<T> *leftLink, *rightLink;
    };

    template <typename T>
    class BinaryTree_CT
    {
    private:
        T /* data */
    
    public:
        BinaryTree_CT()
        {

        }
        ~BinaryTree_CT()
        {

        }
    };
    
}