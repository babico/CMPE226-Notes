#include <iostream>

using namespace std;

// HASH(2312324) = 4
// HASH(195646) = 4

// COLLISION RESOLUTION: WHEN 2 KEYS MAP TO THE SAME INDEX,
// HOW DO YOU HANDLE IT?
// 1) OPEN ADDRESSING
// 2) CHAINING

int main(int argc, char const *argv[])
{
    // RANDOM PROBING: A RANDOM NUMBER GENERATOR
    // IS USED TO FIND THE NEXT SLOT (SAME SEQUENCE OF 
    // RANDOM NUMBERS ARE USED)

    // h(key) = 16
    // random number sequence: 3, 4, 10, 12
    // try following indices
    // 16
    // 16+3 = 19
    // 16+4 = 20
    // 16+10 = 26
    // 16+12 = 28
    

    return 0;
}
