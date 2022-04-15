#include <iostream>

// SORTING

using namespace std;

// ORDERING ARRAYS OR LINKED LIST
// INSERTION SORT:
// INSERT ELEMENTS INTO THE SORTED PORTION OF THE ARRAY

/*
    | 8| SORTED
    |__|
    | 3| ITEM
    |__|
    | 2| <-|
    |__|   |
    | 9|   | UNSORTED
    |__|   |
    | 1| <-|
    |__|



PASS 1:
    | 3| <-|
    |__|   | SORTED
    | 8| <-|
    |__|
    | 2| ITEM
    |__| 
    | 9| <-| UNSORTED
    |__|   |
    | 1| <-|
    |__|



PASS 2:
    | 2| <-|
    |__|   | 
    | 3|   | SORTED
    |__|   |
    | 8| <-|
    |__| 
    | 9| ITEM
    |__| 
    | 1| UNSORTED
    |__|



PASS 3:
    | 2| <-|
    |__|   | 
    | 3|   | 
    |__|   | SORTED
    | 8|   |
    |__|   |
    | 9| <-|
    |__| 
    | 1| ITEM
    |__|



PASS 4:
    | 1| <-|
    |__|   |
    | 2|   |
    |__|   | 
    | 3|   | SORTED
    |__|   | 
    | 8|   |
    |__|   |
    | 9| <-|
    |__|
*/
int main(int argc, char const *argv[])
{

    return 0;
}