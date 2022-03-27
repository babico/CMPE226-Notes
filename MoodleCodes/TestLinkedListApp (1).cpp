//============================================================================
// Name        : StackArray.cpp
// Author      : Ziya Karakaya
// Version     : 0.2
// Date		   : Mar 15 2021
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "Person.h"
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<Person> myList;

	Person p(28, "Ziya", "Karakaya");

	myList.insertLast(p);
	cout << myList << endl;

	myList.insertLast(Person(30, "Ibrahim", "Cereci"));
	cout << "First list: " << myList << endl;

	LinkedList<Person> secondList = myList;

	cout << "Second List : "<< secondList << endl;

	myList.deleteNode(Person(28));
	cout << "First list: " << myList << endl;
	cout << "Second list: " << secondList << endl;

	myList.insertAfter(Person(30), Person(49, "Ali","Veli"));
	cout << "First list: " << myList << endl;

	LinkedList<Person> thirdList;
	thirdList = myList;
	cout << "Third list: " << thirdList << endl;

	myList.insertAfter(Person(30), Person(17, "Ali", "Deli"));
	cout << "First list: " << myList << endl;

	myList.insertFirst(Person(51, "Erdem", "Korkmaz"));
	cout << "First list: " << myList << endl;

	myList.insertAt(2, Person(70, "Ozalp", "Tozan"));
	cout << "First list: " << myList << endl;

	myList.deleteNode(p);
	cout << "First list: " << myList << endl;

	myList.deleteNode(Person(70));
	cout << "First list: " << myList << endl;

	myList.deleteNode(Person(49));
	cout << "First list: " << myList << endl;

	myList.deleteNode(Person(50));
	cout << "First list: " << myList << endl;

	LLNode<Person>* result=myList.search(Person(17));
	if(result !=NULL)
		cout<<"You have found the person."<<result->data<<endl;
	else
		cout<<"You couldn't find the person."<<endl;

	cout << "First list in reverse: ";
	myList.reversePrint();
	cout << endl;
	cout << "There are "<<myList.length()<<" items in the First list." << endl;
	
	myList.clearList();
	cout << "First list: " << myList << endl;
	cout << "There are "<<myList.length()<<" items in the First list." << endl;

	cout<<myList.front()<<endl;

	return 0;
}
	


