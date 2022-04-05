#include <iostream>
#include <stack>
#include <list>

// STL CLASS STACK
using namespace std;

int main(int argc, char const *argv[])
{
    stack<int, list<int>> st;
    st.push(5);
    auto x = st.top();
    cout << x;
    
    return 0;
}
