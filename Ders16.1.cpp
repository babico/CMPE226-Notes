#include <iostream>

using namespace std;

// HASH(2312324) = 4
// HASH(195646) = 4

// COLLISION RESOLUTION: WHEN 2 KEYS MAP TO THE SAME INDEX,
// HOW DO YOU HANDLE IT?
// 1) OPEN ADDRESSING
// 2) CHAINING

int main(int argc, char const *argv[])
{
    // LINNEAR PROBING: IF A COLLISION OCCURED
    //  DO A SEQUANTIAL SEARCH THROUGH THE ARRAY FOR AN
    //  EMPTY LOCATION

    char emptyKey = '*';

    int key;
    cin >> key;

    int i = h(key);
    bool found = false;
    while ((ht[i] != emptyKey) && !found)
    {
        if (ht[i] == key)
        {
            found = true;
        }
        else
        {
            i = (i + 1 % ht.lenght);
        }
    }
    if (found)
    {
        cout << "Already in array" << endl;
    }
    else
    {
        ht[i] = key;
    }
    
    

    return 0;
}
