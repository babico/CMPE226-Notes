#include <iostream>
#include <string>
#include <fstream>
#include "HeaderFiles/BinarySearchTree_CT.h"

using namespace std;

/*
    Implement an English-Turkish dictoinary. Do the following.

    - One word class containing an English word & its Turkish translation
    - Crate a 26-element array where each element is BST
        - Element at index 0 -> words starting with 'A'
        - Element at index 1 -> words starting with 'B'
    - Read words from a text file & create the trees.
    - Read an Eng word & o/p its translation.
*/

class OneWord
{
public:
    string eng, tur;
    bool operator==(const OneWord &obj) const
    {
        return eng == obj.eng;
    }
    bool operator<(const OneWord &obj) const
    {
        return eng < obj.eng;
    }
};

int main(int argc, char const *argv[])
{
    BinarySearchTree_CT<OneWord> dict[26];
    BinaryTreeNode<OneWord> *p;
    OneWord obj;
    string w;
    ifstream inp("Ders23.2.2.txt");

    while (!inp.eof())
    {
        inp >> obj.eng >> obj.tur;
        dict[obj.eng[0] - 'A'].insert(obj);
    }

    cout << "Enter an English Word: ";
    cin >> obj.eng;
    p = dict[obj.eng[0] - 'A'].search(obj);

    if (p != NULL)
    {
        cout << "Turkish: " << p->info.tur << endl;
    }

    return 0;
}
