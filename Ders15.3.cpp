#include <iostream>

using namespace std;

int hashing(string item)
{
    // 32448 --> (3+2+4+4+8) mod 5 = 1
    int sum = 0;
    for (int i = 0; i < item.length(); i++)
    {
        sum += static_cast<int>(item[i]);
    }

    return sum % item.length();
}
int main(int argc, char const *argv[])
{
    cout << 32448 << " " << hashing("32448");
    return 0;
}
