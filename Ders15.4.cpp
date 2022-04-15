#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int> q;

    q.push(1);
    q.push(3);
    q.push(2);
    q.push(4);
    q.push(78);

    cout << q.top();

    return 0;
}
