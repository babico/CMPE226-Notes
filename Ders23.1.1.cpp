#include <iostream>
#include <fstream>
#include "HeaderFiles/BinarySearchTree_CT.h"

using namespace std;
/*
    Implenting a simple search engine including the following:

    - class FileInfo containing a file name a BST composed
    of all words in the file. Note that a word can only
    appear once in a BST.
    - 10 element away to hold the information of 10 files.
    - input the away where every line in a file ends with '.'.
    - Read Search/Quit
    - For search, input a word 2 o/p the files the word appears in.
*/
class FileInfo
{
public:
    string name;
    BinarySearchTree_CT<string> w;
};
int main(int argc, char const *argv[])
{
    FileInfo arr[10];
    string st1, st2;

    for (int i = 0; i < 10; i++)
    {
        cout << "Input file name: ";
        cin >> arr[i].name;

        ifstream inp;
        inp.open(arr[i].name);
        inp >> st1;
        arr[i].w.insert(st1);

        while (!inp.eof())
        {
            inp >> st1;
            if (st1 != ".")
            {
                if (arr[i].w.search(st1) == NULL)
                {
                    arr[i].w.insert(st1);
                }
            }
        }
        inp.close();
        do
        {
            cout << "Enter Search or Quit: ";
            cin >> st2;

            if (st2 == "Search")
            {
                cout << "Enter a word: ";
                cin >> st1;

                for (int i = 0; (i < 10) && (arr[i].w.search(st1) != NULL); i++)
                {
                    cout << i << ": " << arr[i].name << endl;
                }
            }
        } while (st2 != "Quit");
    }

    return 0;
}
