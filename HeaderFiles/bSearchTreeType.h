#include <iostream>
#include "binaryTreeType.h"

using namespace std;

template <class T>
class bSearchTreeType : public binaryTreeType<T>
{
public:
	binaryTreeNode<T> *root;
	bool search(const T &searchItem) const;
	void insert(const T &insertItem);
	void deleteNode(const T &deleteItem);

private:
	void deleteFromTree(binaryTreeNode<T> *&p);
};

template <class T>
bool bSearchTreeType<T>::search(const T &searchItem) const
{
	binaryTreeNode<T> *current;
	bool found = false;

	if (root == NULL)
	{
		cerr << "Cannot search the empty tree." << endl;
	}
	else
	{
		current = root;
		while (current != NULL && !found)
		{
			if (current->info == searchItem)
			{
				found = true;
			}
			else if (current->info > searchItem)
			{
				current = current->llink;
			}
			else
			{
				current = current->rlink;
			}
		}
	}
}

template <class T>
void bSearchTreeType<T>::insert(const T &insertItem)
{
	binaryTreeNode<T> *current;
	binaryTreeNode<T> *trailCurrent;
	binaryTreeNode<T> *newNode;

	newNode = new binaryTreeNode<T>;
	assert(newNode != NULL);
	newNode->info = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (root == NULL)
		root = newNode;
	else
	{
		current = root;
		while (current != NULL)
		{
			trailCurrent = current;

			if (current->info == insertItem)
			{
				cerr << "The insert item is already in the list dup�,cates are not allowed." << insertItem << endl;
				return;
			}
			else if (current->info > insertItem)
			{
				current = current->llink;
			}
			else
			{
				current = current->rlink;
			}
		}

		if (trailCurrent->info > insertItem)
		{
			trailCurrent->llink = newNode;
		}
		else
		{
			trailCurrent->rlink = newNode;
		}
	}
}

template <class T>
void bSearchTreeType<T>::deleteFromTree(binaryTreeNode<T> *&p)
{
	binaryTreeNode<T> *current;
	binaryTreeNode<T> *trailCurrent;
	binaryTreeNode<T> *temp;

	if (p == NULL)
	{
		cerr << "Error: The node to be deleted is NULL" << endl;
	}
	else if (p->llink == NULL && p->rlink == NULL)
	{
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->llink == NULL)
	{
		temp = p;
		p = temp->rlink;
		delete temp;
	}
	else if (p->rlink == NULL)
	{
		temp = p;
		p = temp->llink;
		delete temp;
	}
	else
	{
		current = p->llink;
		trailCurrent = NULL;

		while (current->rlink != NULL)
		{
			trailCurrent = current;
			current = current->rlink;
		}

		p->info = current->info;

		if (trailCurrent == NULL)
		{
			p->llink = current->llink;
		}
		else
		{
			trailCurrent->rlink = current->llink;
		}
		delete current;
	}
}
