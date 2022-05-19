#include <iostream>
#include <map>

// HEAP SORT
// Binary trees as lists/array

using namespace std;

int main()
{
    map<char, int> first;
    first['a'] = 10;
    first['b'] = 20;
    first['c'] = 30;
    
    map<char, int>::iterator it;
    for (it = first.begin(); it != first.end(); ++it)
    {
        cout << it->first << " => " << it->second << endl;
    }    
}