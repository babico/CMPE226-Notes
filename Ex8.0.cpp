#include <iostream>
#include "HeaderFiles/bSearchTreeType.h"

using namespace std;

int main()
{
    bSearchTreeType<int> a;

    int x = 16; 
    a.insert(x);
    x = 6; 
    a.insert(x);
    x = 8; 
    a.insert(x);
    x = 4; 
    a.insert(x);
    x = 2;
    a.insert(x);
    x = 1;
    a.insert(x);
    x = 23; 
    a.insert(x);
    x = 71; 
    a.insert(x);
    x = 50; 
    a.insert(x);

    a.inorderTraversal();
    cout << "\n";

    a.deleteEven();

    a.inorderTraversal();
    return 0;
}