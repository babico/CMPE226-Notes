#include <iostream>
#include <HeaderFiles/LinkedList.h>

using namespace std;
// IF THE HASSH TABELS BELOWS IS GIVEN WITH THE
// KEYS & THEIR RESPECTIVE HASHING & COLLISON RESULUTION
// ALGORITHIMS, INSERT THE KEYS

// c) KEYS: 12, 25, 8, 14, 26, 21, 13, 5, 6
// ARRAY SIZE: 7
// HASH FUNC: MODULAR ARITHMETIC
// COLLUSION RESULATION: CHAINING

int main(int argc, char const *argv[])
{
    LinkedList<int> arr[7];

    arr[12 % 7].insertLast(12);
    arr[25 % 7].insertLast(25);
    arr[8 % 7].insertLast(8);
    arr[14 % 7].insertLast(14);
    arr[26 % 7].insertLast(26);
    arr[21 % 7].insertLast(21);
    arr[13 % 7].insertLast(13);
    arr[5 % 7].insertLast(5);
    arr[6 % 7].insertLast(6);

    /*
        0 |  |-->|14|-->|21|
          |__|
        1 |  |-->| 8|
          |__|
        2 |  |
          |__|
        3 |  |
          |__|
        4 |  |-->|25|
          |__|
        5 |  |-->|12|-->|26|-->| 5|
          |__|
        6 |  |-->|13|-->| 6|
          |__|
    */

    return 0;
}
