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
    // QUADRATIC PROBING: FOLLOW THE PROBE SEQUENCE
    // TO FIND THE NEXT SLOT
    // h(key) = t
    // (t + 1^2) % size
    // (t + 2^2) % size
    // (t + 3^2) % size
    // (t + 4^2) % size
    // (t + 5^2) % size
    // .
    // .
    // (t + n^2) % size
    //
    // h(key) = 34
    // size = 101
    // sequnce to try:
    // 34
    // 35
    // 38
    // 43
    // 50
    // 59
    // 70
    // 83
    // 98
    // 115 % 101 = 14
    

    return 0;
}
