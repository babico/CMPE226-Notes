#include <iostream>
#include <string>
#include <fstream>
#include "HeaderFiles/LinkedList_CT.hpp"
// USING HEADER FILE

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
    bool operator==(const Person &per)
    {
        return num == per.num;
    }
};
int main()
{
    fstream girisDosya("student.txt");

    Person insanlar;
    LinkedList<Person> liste;

    while (!girisDosya.eof())
    {
        girisDosya >> insanlar;
        liste.insertLast(insanlar);
    }

    cout << liste;

    Person ara(0);
    Node<Person> *temp;
    temp = liste.search(ara);

    temp->data.name = "can";

    cout << endl
         << "changed: " << endl
         << liste;

    girisDosya.close();
}