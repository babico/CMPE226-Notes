/*
 * IQueue.h
 *
 *  Created on: Nov 25, 2020
 *      Author: Ziya Karakaya
 */

#ifndef INHERITINGLINKEDLISTQUEUE_H_
#define INHERITINGLINKEDLISTQUEUE_H_

#include <iostream>
#include <cassert>
#include "LinkedList.h"

namespace std
{

	template <typename T>
	class Queue : private LinkedList<T>
	{
	public:
		Queue() {}
		virtual ~Queue() {}

		bool isEmpty() const
		{
			return LinkedList<T>::isEmpty();
		}
		bool isFull() const
		{
			return false;
		}

		void clearQueue()
		{
			LinkedList<T>::clearList();
		}

		T front() const
		{
			return LinkedList<T>::front();
		}

		T rear() const
		{
			return LinkedList<T>::back();
		}

		void add(const T &val)
		{ // insert, push, enqueue, add
			LinkedList<T>::insertLast(val);
		}
		T remove()
		{ // Delete, serve, remove, dequeue, pop
			T item = front();
			LinkedList<T>::deleteFirst();
			return item;
		}
		int size() const
		{
			return LinkedList<T>::length();
		}
	};

}
#endif /* INHERITINGLINKEDLISTQUEUE_H_ */
