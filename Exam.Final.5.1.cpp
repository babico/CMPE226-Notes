#include <iostream>
#include <fstream>
#include "HeaderFiles/bSearchTreeType.h"
using namespace std;
/*
    Make student class store id and grades.
    get id from a file and store a bst
    get grades from a file and store bst except 0
*/

class Student
{
public:
    int id = 0, grade = 0;
    bool operator==(const Student &other)
    {
        return id == other.id;
    }
    bool operator>(const Student &other)
    {
        return id > other.id;
    }
    friend ostream &operator<<(ostream &os, Student &s)
    {
        os << s.id << " " << s.grade << "\n";
        return os;
    }
};

int main(int argc, char const *argv[])
{
    bSearchTreeType<Student> students;  
    Student temp;
    fstream id("Exam.Final.5.1.id.txt");
    fstream grades("Exam.Final.5.1.grades.txt");

    while (!id.eof())
    {
        id >> temp.id;
        students.insert(temp);
    }

    while (!grades.eof())
    {
        grades >> temp.id >> temp.grade;
        if (temp.grade == 0)
        {
            students.deleteNode(temp);
        }
        else
        {
            binaryTreeNode<Student> *x = students.search(temp);
            x->info.grade = temp.grade;
        }
    }

    students.inorderTraversal();

    return 0;
}
