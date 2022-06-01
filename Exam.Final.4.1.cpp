#include <iostream>
#include "HeaderFiles/bSearchTreeType.h"

using namespace std;

/*
    2 or 0 child is strict bst
    make a member func to test it

    template <class T>
    void bSearchTreeType<T>::isStrictPriv(binaryTreeNode<T> *p, bool &res)
    {
        if (p == NULL)
        {
            return;
        }
        if (res == false)
        {
            return;
        }

        if (p->llink != NULL && p->rlink != NULL)
        {
            isStrictPriv(p->llink);
            isStrictPriv(p->rlink);
        }
        else if (p->llink == NULL && p->rlink == NULL)
        {
            isStrictPriv(p->llink);
            isStrictPriv(p->rlink);
        }
        else
        {
            res = false;
        }
    }

    template <class T>
    bool bSearchTreeType<T>::isStrict()
    {
        bool res = true;
        isStrictPriv(binaryTreeType<T>::root, res);
        return res;
    }
*/

int main(int argc, char const *argv[])
{
    //     1
    //    /
    //   2
    bSearchTreeType<int> a;
    int x = 1;
    a.insert(x);
    x = 2;

    //     2
    //    / \
    //   1   3
    bSearchTreeType<int> b;
    x = 2;
    b.insert(x);
    x = 1;
    b.insert(x);
    x = 3;
    b.insert(x);

    cout << "a: " << a.isStrict() << " b: " << b.isStrict();
    return 0;
}
