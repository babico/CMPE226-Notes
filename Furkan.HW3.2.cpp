#include <iostream>
#include "HeaderFiles/bSearchTreeType.h" // bSearchTreeType.h

using namespace std;

int main(){
	
	bSearchTreeType<int> one;
	binaryTreeNode<int> *temp;
	
	int size;
	cout << "Enter the size of the array: ";
	cin >> size;
	
	int arr[size];
	int number;
	int counter = 0;
	
	cout << "Please enter your values: ";
	
	for(int i=0; i<sizeof(arr)/4; i++){
		cin >> arr[i];
		one.insert(arr[i]);
	}
		
	cout << "Enter your search item: ";
	cin >> number ;
	
	if (one.isEmpty())
		cout<<"Empty tree."<<endl;
	else{
		temp = one.search(arr[0]);
		while(temp != NULL){
			if(temp->info == number)
				counter++;
			if(temp->info>number)
				temp = temp->llink;
			else 
				temp = temp->rlink;
		}
	}
	
	if(counter != 0)
	    cout << "The value you entered " << number <<" has been found " << counter << " times." << endl;
	else
	    cout << "The value you entered " << number <<" could not be found. " << endl;

	return 0;
}
