#include <iostream>
#include <string>

using namespace std;

void reverseString(string xD)
{
    if (xD.length() == 0)
    {
        return;
    }
    reverseString(xD.substr(1));
    cout << xD[0];
}

int main(int argc, char const *argv[])
{
    reverseString("123456789");

    cout << endl << endl;
    for (int i = sizeof("123456789"); i > 0; i--)
    {
        cout << "123456789"[i - 1];
    }

    return 0;
}
