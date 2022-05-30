#include <iostream>
#include "bSearchTreeType.h"
using namespace std;

int main()
{
    bSearchTreeType<int> a, b;
    int sizeoftree, num, cnt = 0;

    do
    {
        cout << "Enter the size of tree: ";
        cin >> sizeoftree;
    } while (sizeoftree <= 0);

    cout << "Enter nums: ";
    for (int i = 0; i < sizeoftree; i++)
    {
        cin >> num;
        a.insert(num);
        b.insert(num);
    }

    cout << "Enter number for search: ";
    cin >> num;

    while (b.search(num) != NULL)
    {
        b.deleteNode(num);
        cnt++;
    }

    cout << cnt << " times  " << num << " found";
    return 0;
}