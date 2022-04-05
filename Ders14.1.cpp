#include <iostream>
#include "HeaderFiles/ArrayQueue_CT.h"
/*
    There is only 1 runway in a small airport where
    planes take off & land  one by one. Write a program
    for air traffic control which uses 2 queues, the
    first one for planes waiting to land & the second one
    for planes waiting to take off. The queues will store flight
    numbers (TK213). Note that the planes waiting to land have higher
    precedence the ones waiting to take off.


    Sample Run:
    Enter New, Avaiable, Quit: New
    Flight no? : TK111
    Land or Takeoff? : Takeoff
    Enter : New
    Flight no? : PGS251
    Land or Takeoff? : Land
    Enter : Avaiable
    PGS251 can land
    .
    .
    .
    .
    .
*/
using namespace std;

int main(int argc, char const *argv[])
{
    ArrayQueue_CT<string> land, takeoff;
    string comm, st, x;

    do
    {
        cout << "Enter New, Avaiable, Quit: ";
        cin >> comm;

        if (comm == "New")
        {
            cout << "Flight no: ";
            cin >> x;
            cout << "Land or Takeoff? : ";
            cin >> st;
            if (st == "Land")
            {
                land.insert(x);
            }
            else if (st == "Takeoff")
            {
                takeoff.insert(x);
            }
        }
        else if (comm == "Avaiable")
        {
            if (!land.isEmpty())
            {
                x = land.deleteQueue();
                cout << x << " can land." << endl;
            }
            else if (!takeoff.isEmpty())
            {
                x = takeoff.deleteQueue();
                cout << x << " can takeoff." << endl;
            }
        }

    } while (comm != "Quit");

    return 0;
}
