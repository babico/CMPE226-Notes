#include <iostream>

// HEAP SORT
// Binary trees as lists/array

/*
    The left child of node k is in position 2k+1
    The right child of node k is in position 2k+2
*/

// HEAP SORT:
// A LIST IN WHOCH FOR ALL POSITION k IN THE LIST
// THE KEY AT POSITION k IS AT LEAST AS LARGE AS
// THE KEYS IN POSITIONS 2k+1 & 2K+2 İF THEY EXIST.
// [CONTENT OF EACH NODE <= FATHER]

/*
    0---|---1---|---3---|---7
        |       |       |
        |       |       |---8
        |       |
        |       |---4---|---9
        |               |
        |               |---10
        |
        |---2---|---5---|---11
                |       |
                |       |---12
                |
                |---6---|---13
                        |
                        |---14

    k = 2
        2k+1 left child = 5
        2k+2 right child = 6
    k = 3
        2k+1 left child = 7
        2k+2 right child = 8
*/

using namespace std;

int main()
{

}