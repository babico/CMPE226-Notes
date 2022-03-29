#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList.h"

using namespace std;

class Digit
{
public:
    int pos, data;
    bool operator==(const Digit &other)
    {
        return pos == other.pos;
    }
};

int main(int argc, char const *argv[])
{
    LinkedList<Digit> number;
    string input;
    int pos;

    cout << "Enter your integer: ";
    cin >> input;

    int k = 0;
    for (int i = input.length(); i > 0; i--)
    {
        Digit temp;
        temp.data = input[k] - '0'; // string array indexi char dönüyor onada "- '0'" diyerek inte dönüştürüyoz
        temp.pos = i;
        number.insertLast(temp);
        k++;
    }

    cout << "Enter a position: ";
    cin >> pos;

    Digit temp;
    temp.pos = pos;
    cout << "Pos: " << number.search(temp)->data.pos << " Digit of number: " << number.search(temp)->data.data;

    return 0;
}

