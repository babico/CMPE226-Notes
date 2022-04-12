#include <iostream>
#include <fstream>
#include "HeaderFiles/LinkedList.h"

using namespace std;

// HASH(2312324) = 4
// HASH(195646) = 4

// COLLISION RESOLUTION: WHEN 2 KEYS MAP TO THE SAME INDEX,
// HOW DO YOU HANDLE IT?
// 1) OPEN ADDRESSING
// 2) CHAINING

int h(int key)
{
    return key % 10;
}

class Person
{
private:
    string naem;

public:
    int key;
};

int main(int argc, char const *argv[])
{
    // CHANINING: KEEP A LINKED LIST FOR ALL
    // RECORDS WHOSE KEYS HASH INTI A PARTICULAR INDEX.
    // h(256) = 6 <-|
    // h(711) = 1   |
    // h(516) = 6 <-|

    ifstream input("in.dat");
    LinkedList<Person> bucket[10];
    Person obj;
    while (!input.eof())
    {
        cin >> obj;
        int i = h(obj.key);
        bucket[i].insertLast(obj);
    }

    return 0;
}
