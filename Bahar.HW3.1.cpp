#include <iostream>
#include "HeaderFiles/bSearchTreeType.h" // bSearchTreeType.h

using namespace std;

int main(int argc, char const *argv[])
{
    int num, inp, search, cnt = 0;
    binaryTreeNode<int> *p; 
    bSearchTreeType<int> tree;
    cout << "How many numbers you want to enter? ";
    cin >> inp;
    cout << "Enter numbers : ";
    for (int i = 0; i < inp; i++)
    {
        cin >> num;
        tree.insert(num);
    }
    tree.inorderTraversal();
    cout << endl << "Enter item to be searched: ";
    cin >> search;
    
    while (p != nullptr)
    {
        p = tree.search(search);
        cnt++;
        tree.deleteNode(search);
        p = tree.search(search);
    }
    
    
    cout << "The number " << search << " occures " << cnt << " time(s)." << endl;


    return 0;
}
