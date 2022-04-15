#include <iostream>

using namespace std;
// IF THE HASSH TABELS BELOWS IS GIVEN WITH THE
// KEYS & THEIR RESPECTIVE HASHING & COLLISON RESULUTION
// ALGORITHIMS, INSERT THE KEYS

// a) KEYS: 12, 35, 8, 14, 26, 21, 13
// ARRAY SIZE: 7
// HASH FUNC: MOD ARITMETIC
// COLLUSION RESULATION

int main(int argc, char const *argv[])
{
    int arr[7];
    arr[12 % 7] = 12;
    arr[35 % 7] = 35;
    arr[8 % 7] = 8;
    arr[14 % 7] = 14;
    arr[26 % 7] = 26;
    arr[21 % 7] = 21;
    arr[13 % 7] = 13;

    /*
        |14| 0
        |__|
        | 8| 1
        |__|
        |21| 2
        |__|
        |13| 3
        |__|
        |25| 4 
        |__|
        |12| 5
        |__|
        |26| 6
        |__|
    */
    return 0;
}
