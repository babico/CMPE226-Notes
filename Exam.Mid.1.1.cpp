#include <iostream>

using namespace std;

void func(int x)
{
    if (x > 1)
    {
        cout << x * 3 << " ";
        func(x - 1);
        cout << x << " ";
    }
    else
    {
        cout << "one" << endl;
    }
}

int main(int argc, char const *argv[])
{
    func(4);
    cout << "End" << endl;
    return 0;
}
