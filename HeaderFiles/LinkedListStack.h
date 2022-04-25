/*
 * LStack.h
 *
 *  Created on: Nov 17, 2020
 *  Author: Ziya Karakaya
 * Desciption:
 * 	Stack class implemented using linked list notation
 *
 * Last update : Nov 25, 2020
 * Version: v0.2
 * Update Notes:
 * 	We changed the name Node to SNode in order to prevent redefinition error when used with other ADTs.
 *
 */

#ifndef LINKEDLISTSTACK_H_
#define LINKEDLISTSTACK_H_

#include <iostream>
#include <cassert>
using namespace std;

template<class T>
struct SNode {
	T data;
	SNode<T> *next;
};

template<class T>
class LinkedListStack {
protected:
	SNode<T> *top; //head becomes top. Items should be inserted from top.
	int cnt;
public:
//Constructor
	LinkedListStack() {
		top = NULL; //sets top initial value to NULL
		cnt = 0;
	}
//Destructor
	~LinkedListStack() {
		clear();
	}
	bool isEmpty() {
		return top == NULL;
	}
//There is no size limitation in Stack using LinkedList implementation. We do not need to check if the stack is full or not.
	T peek() { // you can name it as peek
		assert( !isEmpty() ); //if not empty
		return top->data;//return the value on the 	top
	}
	T pop();
	void push(const T&);
	void clear();
	int size();
};

//resets the stack to its initial state
template<class T>
void LinkedListStack<T>::clear() {
	SNode<T> *p;
	while (top != NULL) {
		p = top;
		top = top->next;
		delete p;
	}
	cnt = 0;
}

//insert a new item to the top of stack
template<class T>
void LinkedListStack<T>::push(const T &item) {
	SNode<T> *newNode = new SNode<T>;
	newNode->data = item;
	newNode->next = top;
	top = newNode;
	cnt++;
}

//retrieve (remove and return) the top value
template<class T>
T LinkedListStack<T>::pop() {
	SNode<T> *p; //pointer to traverse
	T item;
	assert(!isEmpty()); //if the stack is empty terminate
	p = top;
	item = top->data;
	top = top->next;
	delete p;
	cnt--;
	return item;
}

template<class T>
int LinkedListStack<T>:: size(){
	return cnt;
}

#endif /* LINKEDLISTSTACK_H_ */
