#include <iostream>
// TEMPLATE EXAMPLE
using namespace std;

template<class T>
void printArray(T *arr)
{
    for (int i = 0; i < sizeof(arr)-3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[5];
    double arr2[5];

    cout << "Enter 5 integer: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr1[i];
    }
    cout << "printing integers: ";
    printArray(arr1);

    cout << "Enter 5 double: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr2[i];
    }
    cout << "printing integers: ";
    printArray(arr2);
}
