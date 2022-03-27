/*
Delta airlines maintains & scheduled flights/day from Ankara
numbered 100,200,300 & 400. For each of these flights they
keep a LL of passenger names as follows.
*/
#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList_CT.h"

using namespace std;

class Person
{
public:
    string name;
    int num;

    Person(int x = 0)
    {
        num = x;
    }
    ~Person() {}
    friend istream &operator>>(istream &is, Person &per)
    {
        is >> per.name >> per.num;

        return is;
    }
    friend ostream &operator<<(ostream &os, const Person &per)
    {
        os << per.name << " " << per.num << endl;

        return os;
    }
    bool operator==(Person &per)
    {
        return num == per.num;
    }
};

struct Flights
{
    int flightNumber;
    LinkedList<Person> humanInfo;
};

int main()
{
    Flights Ucuslar[4];
    string komut;

    for (int i = 100; i <= 400; i += 100)
    {
        Ucuslar[(i / 100) - 1].flightNumber = i;
    }

    while (komut != "Quit")
    {
        if (komut == "Add")
        {
            /* code */
        }
    }

    return 0;
}