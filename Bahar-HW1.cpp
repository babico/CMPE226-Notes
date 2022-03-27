#include <iostream>
#include "HeaderFiles/LinkedList.h"
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

class Questions
{
private:
    int qNum;
    string question, answer;

public:
    Questions() {}
    void setqNum(int n)
    {
        qNum = n;
    }
    void setquestion(string q)
    {
        question = q;
    }
    void setanswer(string a)
    {
        answer = a;
    }
    int getqNum()
    {
        return qNum;
    }
    string getanswer()
    {
        return answer;
    }
    string getquestion()
    {
        return question;
    }
    friend ostream &operator<<(ostream &out, Questions &q)
    {
        out << "q num: " << q.qNum << endl
            << "question: " << q.question << endl
            << "answer: " << q.answer << endl;
        return out;
    }
    bool operator==(const Questions &q)
    {
        return qNum == q.qNum;
    }
};

struct TopicNode
{
    string topicName;
    LinkedList<Questions> Topics;
};

int main()
{
    srand(time(NULL));
    ifstream file;
    file.open("Hw1TextFile.txt");

    int num = 1;
    string line = " ";
    TopicNode topicsArray[5];

    // getting topic names, quesitons & answers
    for (int i = 0; i < 5; i++)
    {
        getline(file, line);
        topicsArray[i].topicName = line;
        while (line != "#")
        {
            Questions q1;
            q1.setqNum(num);
            num++;
            getline(file, line);
            if (line == "#")
            {
                break;
            }
            q1.setquestion(line);
            getline(file, line);
            q1.setanswer(line);
            topicsArray[i].Topics.insertLast(q1);
        }
        num = 1;
    }

    cout << "Data Structures Quiz" << endl
         << "Answer the following:" << endl;

    // selecting random 2 questions from each topic & getting users' answers
    int randQuesNum, usedNum = -1, score = 10, x = 0, j = 1;
    string wrongAnswers[10], wrongAnswers2[10], userAns;

    for (int i = 0; i < 5; i++)
    {
        cout << topicsArray[i].topicName << " questions " << endl;
        for (int k = 0; k < 2; k++)
        {
            LLNode<Questions> *ptr;
            Questions q;
            do
            {
                randQuesNum = (rand() % 5) + 1;
            } while (usedNum == randQuesNum);

            q.setqNum(randQuesNum + 1);
            ptr = topicsArray[i].Topics.search(q);
            cout << j << ". " << ptr->data.getquestion() << "(T/F): ";
            cin >> userAns;
            if (ptr->data.getanswer() != userAns)
            {
                wrongAnswers[x] = ptr->data.getquestion();
                wrongAnswers2[x] = ptr->data.getanswer();
                score--;
                x++;
            }
            j++;
            usedNum = randQuesNum;
        }
        cout << endl;
        usedNum = -1;
    }

    // displaying score
    cout << "Your score: " << score << "/10" << endl;

    // displaying user's wrong answered questions and their answers
    cout << "Incorrectly answered questions:" << endl;
    for (int i = 0; i < x; i++)
    {
        cout << endl
             << wrongAnswers[i] << " Correct answer:  " << wrongAnswers2[i] << endl;
    }
}