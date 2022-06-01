#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

template <class T>
struct node
{
	T info;
	node<T> *llink;
	node<T> *rlink;
};

template <class T>
class BinaryTree
{
protected:
	node<T> *root;

private:
	void destroy(node<T> *);
	void inorderD(node<T> *);
	void preorderD(node<T> *);
	void postorderD(node<T> *);
	int height(node<T> *);
	int max(int, int);
	int nodecount(node<T> *);
	int leavescount(node<T> *);

public:
	BinaryTree()
	{
		root = NULL;
	}
	~BinaryTree()
	{
		destroy(root);
	}
	bool isEmpty()
	{
		return root == NULL;
	}
	void inorder()
	{
		inorderD(root);
	}
	void preorder()
	{
		preorderD(root);
	}
	void postorder()
	{
		postorderD(root);
	}
	int treeheight()
	{
		return height(root);
	}
	int count()
	{
		return nodecount(root);
	}
	int lcount()
	{
		return leavescount(root);
	}
};

template <class T>
void BinaryTree<T>::inorderD(node<T> *p)
{
	if (p != NULL)
	{
		inorderD(p->llink);
		cout << p->info << " ";
		inorderD(p->rlink);
	}
}

template <class T>
void BinaryTree<T>::preorderD(node<T> *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorderD(p->llink);
		preorderD(p->rlink);
	}
}

template <class T>
void BinaryTree<T>::postorderD(node<T> *p)
{
	if (p != NULL)
	{
		postorderD(p->llink);
		postorderD(p->rlink);
		cout << p->info << " ";
	}
}

template <class T>
int BinaryTree<T>::max(int x, int y)
{
	if (x >= y)
		return x;
	return y;
}

template <class T>
int BinaryTree<T>::height(node<T> *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->llink), height(p->rlink));
}

template <class T>
int BinaryTree<T>::nodecount(node<T> *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + nodecount(p->llink) + nodecount(p->rlink);
}

template <class T>
int BinaryTree<T>::leavescount(node<T> *p)
{
	if (p == NULL)
		return 0;
	else if (p->llink == NULL && p->rlink == NULL)
		return 1;
	else
		return leavescount(p->llink) + leavescount(p->rlink);
}

#endif
