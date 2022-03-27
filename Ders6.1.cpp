/*
Delta airlines maintains & scheduled flights/day from Ankara
numbered 100,200,300 & 400. For each of these flights they
keep a LL of passenger names as follows.
*/

#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList.h"

using namespace std;

struct FlightNode
{
    int flightNo;
    LinkedList<string> pass;
};

int main()
{
    string command, name;
    int no;
    FlightNode flights[4]; // every one of the node is 40 bit long // cout << sizeof(flights) / 40;
    for (int i = 100; i <= 400; i += 100)
    {
        flights[(i / 100) - 1].flightNo = i;
    }

    do
    {
        cout << "Enter Add, Delete, List, Check & Quit: ";
        cin >> command;
        if (command == "Add")
        {
            cout << "Enter name & flight no: ";
            cin >> name >> no;
            flights[(no / 100) - 1].pass.insertLast(name);
        }
        else if (command == "Delete")
        {
            cout << "Enter name & flight no: ";
            cin >> name >> no;
            flights[(no / 100) - 1].pass.deleteNode(name);
        }
        else if (command == "List")
        {
            cout << "Enter flight no: ";
            cin >> no;
            cout << flights[(no / 100) - 1].pass;
            cout << endl;
        }
        else if (command == "Check")
        {
            cout << "Enter name: ";
            cin >> name;
            for (int i = 0; i < 4; i++)
            {
                if (flights[i].pass.search(name) != NULL)
                {
                    cout << name << " is here: " << flights[i].flightNo << endl;
                }
            }
        }
    } while (command != "Quit");

    return 0;
}