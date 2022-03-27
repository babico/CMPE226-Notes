Binary Trees:
------------
Binary Tree is a structure with a unique starting node called the root, in which
each node is capable of having maximum of two child nodes and in which a unique
path exists from the root to every node. 

Root:
-----
the top, or the base node of the tree structure. This is the beginning point for the
binary tree data structure.

Leaf Node:
---------
a tree node that has no children.

Level of a Node:
---------------
number of branches on the path from the root to the node.

Height (depth) of a binary tree:
-------------------------------
Number of nodes	on the longest path from the root to a leaf node.

Declaration of a node in a Binary Tree:
--------------------------------------

template <class T>
struct node
{
	T info;	//Hold the actual information
	node<T> *llink; //Left link
	node<T> *rlink; //Right link	
};

Binary Tree Traversal: Visiting each node of the tree.
---------------------

Preorder:  Visit root, traverse left subtree, traverse right subtree

Inorder:   Traverse left subtree, visit root, traverse right subtree

Postorder: Traverse left subtree, traverse right subtree, visit root






