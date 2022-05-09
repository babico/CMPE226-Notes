// binary topla 3 stack
#include <iostream>
#include "HeaderFiles/LinkedListStack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int ext = 0;
    string num1, num2;
    LinkedListStack<int> st1, st2, sum;

    cout << "Enter 2 Binary: ";
    cin >> num1 >> num2;

    for (int i = 0; i < num1.size(); i++)
    {
        st1.push(num1[i] - '0');
        st2.push(num2[i] - '0');
    }
    while (st1.size() != 0)
    {
        int toplam = st1.pop() + st2.pop() + ext;
        if (toplam % 2 == 0)
        {
            toplam = 0;
            sum.push(toplam);
            ext = 1;
        }
        else
        {
            sum.push(toplam);
            ext = 0;
        }
        if (st1.size() == 0 && ext == 1)
        {
            sum.push(ext);
        }
    }

    int sumSize = sum.size();
    for (int i = 0; i < sumSize; i++)
    {
        cout << sum.pop();
    }
    return 0;
}
