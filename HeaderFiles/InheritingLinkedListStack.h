/*
 * IStack.h
 *
 *  Created on: Nov 17, 2020
 *      Author: Ziya Karakaya
 *      Stack class implemented by inheriting LinkedList class
 */

#ifndef INHERITINGLINKEDLISTSTACK_H_
#define INHERITINGLINKEDLISTSTACK_H_

#include <cassert>
#include "LinkedList.h"

namespace std{

template <typename T>
class InheritingLinkedListStack:private LinkedList<T>{
public:
	bool isEmpty(){
		return LinkedList<T>::isEmpty(); // OR return this->isEmpty();
	}

	void push(const T &item){
		this->insertFirst(item);
	}

	T peek(){
		return this->front();
	}

	void clear(){
		this->clearList();
	}

	T pop(){
		T item = this->front();
		this->deleteFirst();
		return item;
	}

	int size(){
		return this->size();
	}
};


}
#endif /* INHERITINGLINKEDLISTSTACK_H_ */
