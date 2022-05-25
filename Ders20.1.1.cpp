#include <iostream>
#include "HeaderFiles/BinaryTree_CT.hpp"

// UNION DATA TYPES

using namespace std;

template<typename T>
int BinaryTree_CT<T>::evalExpr(BinaryTreeNode<Uni> *temp = root)
{
    int op1, op2;
    char symbol;

    if (temp->info.utype == operand)
    {
        return temp->info.num;
    }
    op1 = evalExpr(temp->leftLink);
    op2 = evalExpr(temp->rightLink);
    symbol = temp->info.chinfo;

    return eval(symbol, op1, op2);
}

class Uni
{
public:
    short int utype;
    union
    {
        char chinfo;
        int num;
    };
};

const int oprator = 0;
const int operand = 1;

int main(int argc, char const *argv[])
{
    BinaryTree_CT<Uni> *expr = new BinaryTree_CT<Uni>;
    int res = expr.evalExpr();
    cout << res;

    return 0;
}