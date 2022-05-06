#include <iostream>

using namespace std;
// IF THE HASSH TABELS BELOWS IS GIVEN WITH THE
// KEYS & THEIR RESPECTIVE HASHING & COLLISON RESULUTION
// ALGORITHIMS, INSERT THE KEYS

// b) KEYS: 1122, 7518, 1249, 2053, 2211, 6284
// ARRAY SIZE: 10
// HASH FUNC: FOLDING 2 DIGITS
// COLLUSION RESULATION: QUADRATIC RESULATION

int main(int argc, char const *argv[])
{
    int arr[10];

    arr[(11 + 22) % 10] = 1122;                     // arr[3]
    arr[((75 + 18) % 10) + (1 * 1)] = 7518;         // arr[3] collusion so 3 + 1^2 = 4
                                                    // arr[4]

    arr[(12 + 49) % 10] = 1249;                     // arr[1]
    arr[((20 + 53) % 10) + (2 * 2)] = 2053;         // arr[3] collusion so 3 + 2^2 = 7
                                                    // arr[7]

    arr[(((22 + 11) % 10) + (3 * 3)) % 10] = 2211;  // arr[3] collusion so 3 + 3^2 = 12 -> 12 % 10 = 2
                                                    // arr[2]

    arr[(62 + 84) % 10] = 6284;                     // arr[6]

    return 0;
}
