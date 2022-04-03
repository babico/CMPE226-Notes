#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int id;

public:
    Person(string n, int i)
    {
        name = n;
        id = i;
    }
    Person() {}

    bool operator==(Person &p)
    {
        return id == p.id;
    }
    friend ostream &operator<<(ostream &out, Person &p)
    {
        out << "name: " << p.name << " id: " << p.id << endl;
        return out;
    }
    void setid(int i)
    {
        id = i;
    }
    int getid() { return id; }
    void setname(string n)
    {
        name = n;
    }
    string getname() { return name; }
};
#endif /* PERSON_H_ */
