/*
 * AStack.h
 *
 *  Created on: Nov 11, 2020
 *      Author: Ziya Karakaya
 *      Stack class implemented using Array notation
 */

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_
using namespace std;
#include <cassert>
#include <iostream>

template<class T>
class ArrayStack {
protected:
	T *arr; //array hold elements
	int top; //index of first available place in array
	int sz; //size of array
public:
	ArrayStack(int size = 100);
	ArrayStack(const ArrayStack<T>&);
	virtual ~ArrayStack();

	bool isEmpty();
	bool isFull();
	int size();
	void clear();
	void push(const T&);
	T pop();	// retrieve top element and remove it from stack
	T peek(); //retrieve top element. You can name it as getTop
};

template<class T>
ArrayStack<T>::ArrayStack(int stackSize) {
	sz = stackSize;
	arr = new T[sz];
	top = 0;
}
template<class T>
ArrayStack<T>::~ArrayStack() {
	delete[] arr;
}

template<class T>
bool ArrayStack<T>::isEmpty() {
	return (top == 0);
}

template<class T>
bool ArrayStack<T>::isFull() {
	return (top == sz);
}

template<class T>
int ArrayStack<T>::size() {
	return top;
}

template<class T>
void ArrayStack<T>::clear() {
	top = 0;
}
template<class T>
void ArrayStack<T>::push(const T &data) {
	if (!isFull()) {
		arr[top] = data;
		top++;
	} else {
		cout << "Stack Full" << std::endl;
	}
}
template<class T>
T ArrayStack<T>::pop() {
	assert(!isEmpty());
// If function evaluates to false, abort (FOR DEBUGGING)
	top--;
	return arr[top];
}

template<class T>
T ArrayStack<T>::peek() {
	assert(!isEmpty());
// If function evaluates to false, abort (FOR DEBUGGING)
	return arr[top - 1];
}

template<class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> &st) {
	delete[] arr;
	sz = st.sz;
	top = st.top;
	arr = new T[sz];
	for (int n = 0; n < top; n++) {
		arr[n] = st.arr[n];
	}
}




#endif /* ARRAYSTACK_H_ */
