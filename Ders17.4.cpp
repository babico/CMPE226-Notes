#include <iostream>

using namespace std;
// IF THE HASSH TABELS BELOWS IS GIVEN WITH THE
// KEYS & THEIR RESPECTIVE HASHING & COLLISON RESULUTION
// ALGORITHIMS, INSERT THE KEYS

// d) KEYS: 654, 237, 110, 8, 9, 9112, 714, 898, 512
// ARRAY SIZE: 10
// HASH FUNC: SUM OF DIGITS % SIZE
// COLLUSION RESULATION: RANDOM PROBING
// RANDOM NUMBERS: 2, 4, 6, 11, 24, 38, 51

int main(int argc, char const *argv[])
{

    int arr[10];

    arr[(6 + 5 + 4) % 10] = 654;
    arr[(2 + 3 + 7) % 10] = 237;
    arr[((1 + 1 + 0) % 10) + 2] = 110; // collision with 237 so add 2 (first collision for equal 2)
    arr[(8) % 10] = 8;
    arr[(9) % 10] = 9;
    arr[(9 + 1 + 1 + 2) % 10] = 9112;
    arr[((7 + 1 + 4) % 10) + 4] = 714; // collision with 110 so add 4 (second collision for equal 2)
    arr[((8 + 9 + 8) % 10) + 2] = 898; // collision with 654 so add 2 (first collision for equal 5)
    arr[(5 + 1 + 2) % 10] = 512;       // collision with 8 so add 2 (first collision for equal 8)

    /*
        0 | 512|
          |____|
        1 |    |
          |____|
        2 | 237|
          |____|
        3 |9112|
          |____|
        4 | 110|
          |____|
        5 | 654|
          |____|
        6 | 714|
          |____|
        7 | 898|
          |____|
        8 |   8|
          |____|
        9 |    |
          |____|
    */
    return 0;
}
