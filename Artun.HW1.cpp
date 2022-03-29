

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "HeaderFiles/LinkedList.h"

using namespace std;

const int topicC = 6;
const int totqa = 5;
const int countRandomQuest = 2;
static int points;
static int wrongCounter;

void printWrongs(LLNode<LinkedList<string>> wrongs[totqa * countRandomQuest])
{

    cout << "Incorrectly answered questions:\n\n";
    for (int i = 0; i < wrongCounter; i++)
    {
        cout << wrongs[i].data.front();
    }

    cout << "\n\nYour score is (" << points << "/" << totqa * countRandomQuest << ")" << endl;
}

void game(LLNode<LinkedList<string>> answers[topicC][totqa], LLNode<LinkedList<string>> questions[topicC][totqa], LLNode<LinkedList<string>> xcopy[totqa], LLNode<LinkedList<string>> wrongs[totqa * countRandomQuest])
{

    // int topicCount = 0;

    int randomNum[countRandomQuest];
    int controlFlag = 0;
    int control = 0;

    int count = 1;
    int doesCorrect = 0;
    string node;
    string input = " default ";
    string copy;

    for (int i = 0; i < countRandomQuest; i++)
    {
        if (i != 0)
        {

            while (control == 0)
            {
                while (controlFlag == 0)
                {
                    randomNum[i] = rand() % totqa;
                    for (int j = 1; j <= i; j++)
                    {
                        if (randomNum[j - 1] == randomNum[i])
                        {
                            controlFlag = 0;
                            break;
                        }
                        else
                        {
                            controlFlag = 1;
                        }
                    }
                }

                if (controlFlag == 1)
                {
                    // cout << "Value " << i + 1 << " is : " << randomNum[i] << endl;
                    control = 1;
                    controlFlag = 0;
                }
            }
        }
        else
        {
            randomNum[i] = rand() % totqa;
            // cout << "Value " << i + 1 << " is : " << randomNum[i] << endl;
        }
        control = 0;
    }

    cout << "\nData Structures Quiz\nAnswer the following :\n"
         << endl;

    int flag = 0;
    while (flag < totqa)
    {
        cout << xcopy[flag].data.back() << " Questions:" << endl;
        int i = 0;
        for (int j = 0; j < countRandomQuest; j++)
        {
            while (doesCorrect == 0)
            {
                cout << "  " << count << ".  " << questions[flag][randomNum[i]].data.back() << "(T/F): ";
                cin >> input;

                if (input == "F" || input == "T")
                {
                    copy = questions[flag][randomNum[i]].data.back();
                    copy = copy + input;
                    if (xcopy[flag].data.search(copy))
                    {
                        points++;
                    }
                    else
                    {
                        if (input == "T")
                        {
                            copy = "\n";
                            copy = copy + questions[flag][randomNum[i]].data.back();
                            copy = copy + "Correct Answer: False";
                            wrongs[wrongCounter].data.insertFirst(copy);
                            wrongCounter++;
                        }
                        else
                        {
                            copy = "\n";
                            copy = copy + questions[flag][randomNum[i]].data.back();
                            copy = copy + "Correct Answer: True";
                            wrongs[wrongCounter].data.insertFirst(copy);
                            wrongCounter++;
                        }
                    }
                    i++;
                    count++;
                    doesCorrect = 1;
                }
                else
                {
                    cout << "Invalid input try again" << endl;
                }
            }
            doesCorrect = 0;
        }

        doesCorrect = 0;
        flag++;
    }
}

int main()
{

    LLNode<LinkedList<string>> questions[topicC][totqa];
    LLNode<LinkedList<string>> answers[topicC][totqa];
    LLNode<LinkedList<string>> wrongs[totqa * countRandomQuest];
    LLNode<LinkedList<string>> head[totqa];

    string myText;
    string copy;
    int points = 0;

    // Read from the text file
    ifstream MyReadFile("Hw1TextFile.txt");

    // read the file line by line
    int answersCounter = 0;
    int questionCounter = 0;
    int topicCounter = 0;
    int counter = 0;

    while (getline(MyReadFile, myText))
    {

        if (counter == 0)
        {
            head[topicCounter].data.insertFirst(myText);
            counter++;
        }
        else if (myText == "T" || myText == "F")
        {

            copy = copy + myText;
            head[topicCounter].data.insertFirst(copy);
            answers[topicCounter][answersCounter].data.insertFirst(myText);
            answersCounter++;
        }
        else if (myText == "#")
        {
            topicCounter++;
            questionCounter = 0;
            answersCounter = 0;
            counter = 0;
        }
        else
        {
            copy = myText;
            questions[topicCounter][questionCounter].data.insertFirst(myText);
            questionCounter++;
        }
    }

    srand(time(0));
    game(answers, questions, head, wrongs);
    cout << "\n\n";
    printWrongs(wrongs);
    cout << "\n\n";

    MyReadFile.close();
}
