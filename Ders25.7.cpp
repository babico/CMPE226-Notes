#include <iostream>
#include <set>

// HEAP SORT
// Binary trees as lists/array

using namespace std;

int main()
{
    set<int, greater<int>> s1;
    s1.insert(4);
    s1.insert(3);
    s1.insert(6);
    s1.insert(4);
    set<int, greater<int>>::iterator it;
    for (it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    
}