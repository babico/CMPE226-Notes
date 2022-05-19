#include <iostream>

// HEAP SORT
// Binary trees as lists/array

/*
    HEAPSORT ALGORITHM
    - Build heap from list
    - Exchange root & last element, remove the old root
    - Repeat the above process for the rest of the list.


    y---|---r---|---d
        |       |
        |       |---f
        |
        |---p

    
    _[0] [1] [2] [3] [4]_
    | y | r | p | d | f |

    PASS 1:
    r---|---f---|---d
        |
        |---p

    _[0] [1] [2] [3] [4]_
    | r | f | p | d | y |
                      ^
                      |
                    sorted

    PASS 2:
    p---|---f
        |
        |---d

    _[0] [1] [2] [3] [4]_
    | p | f | p | r | y |
                  ^   ^
                  |---|
                    sorted

    PASS 3:
    f---|---d

    _[0] [1] [2] [3] [4]_
    | f | d | p | r | y |
              ^       ^
              |-------|
                sorted

    PASS 4:
    d

    _[0] [1] [2] [3] [4]_
    | d | f | p | r | y |
      ^               ^
      |---------------|
            sorted
*/

using namespace std;

int main()
{

}