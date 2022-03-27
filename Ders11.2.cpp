#include <iostream>
using namespace std;

// Write a recursive function for an ATM that 
// recieves the amount to withdraw & displays
// the banknotes to be givin to the customer.
// ATM only has 100, 20, 10 TL banknotes.

// 270 TL -> 2x100, 3x20, 1x10

void ATM(int amount)
{
    if (amount >= 100)
    {
        cout << 100 << endl;
        ATM(amount-100);
    }
    else if (amount >= 20)
    {
        cout << 20 << endl;
        ATM(amount-20);
    }
    else if (amount >= 10)
    {
        cout << 10 << endl;
        ATM(amount-10);
    }
    
}

int main()
{
    ATM(270);
    return 0;
}