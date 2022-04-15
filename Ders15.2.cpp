#include <iostream>
#include "MoodleCodes/Person.h"

using namespace std;

// Recursive Binary Search
int BinarySearch(Person list[], int low, int lenght, int item)
{
    int high = lenght - 1, mid;
    mid = (low + high) / 2;
    if (item == list[mid].getId())
    {
        return mid;
    }
    else if (item < list[mid].getId())
    {
        return BinarySearch(list, low, mid-1, item);
    }
    else
    {
        return BinarySearch(list, mid + 1, lenght, item);
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    Person liste[3];
    liste[0].setId(1);
    liste[0].setName("zbab1");
    liste[0].setSurname("xD1");

    liste[1].setId(3);
    liste[1].setName("zbab2");
    liste[1].setSurname("xD2");

    liste[2].setId(4);
    liste[2].setName("zbab3");
    liste[2].setSurname("xD3");

    cout << liste[BinarySearch(liste, 0, 3, 3)].getName();
    return 0;
}
