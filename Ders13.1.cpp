#include <iostream>
#include "HeaderFiles/ArrayStack_CT.hpp"
// Write a program to input the exam grades
// of 50 students & find the names of the students
// who received the top grade. Use a stack of object
// storing the name & grade of students receiving 
// the top grade. There may be more than 1 student with top grade
using namespace std;

class Student
{
public:
    string name;
    int grade;
    friend istream &operator>>(istream &is, Student &obj)
    {
        is >> obj.name >> obj.grade;
        return is;
    }
};

int main(int argc, char const *argv[])
{
    int max = 0;
    Student s;
    ArrayStack_CT<Student> st(50);

    for (int i = 0; i < 50; i++)
    {
        cin >> s;
        if (s.grade > max)
        {
            max = s.grade;
            st.destroy();
            st.push(s);
        }
        else if (s.grade == max)
        {
            st.push(s);
        }
    }

    cout << "Max = " << max << endl;
    cout << "Student receiving the top grade: ";
    while (!st.isEmpty())
    {
        s = st.pop();
        cout << s.name;
    }

    return 0;
}