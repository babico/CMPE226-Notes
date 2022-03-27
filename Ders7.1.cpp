#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> liste1;
    int x = 5;
    liste1.push_front(x);
    cout << liste1.back() << endl;
    liste1.remove(x);
    liste1.sort();

    list<int> liste2 = {1, 2, 3, 4, 5};
    list<int>::iterator itr;
    for (itr = liste2.begin(); itr != liste2.end(); itr++)
    {
        cout << *itr << endl;
    }

    return 0;
}
