#include <iostream>
#include <fstream>
#include <string>

#include <ctime>
#include <cstdlib>

#include "Hw1Exam.h"
#include "HeaderFiles/LinkedList.h"

using namespace std;

struct TitleNode
{
	string title;
	LinkedList<Exam> questions;
};

int main()
{

	// variable definition and initialization
	bool titlepicker = true; // boolean variable to pick first data of each topic

	string UserAnswer = " ";		   // variable to get user answer
	string PickedQuestion[2];		   // variable to assign randomly picked 2 questions each topic
	LLNode<Exam> *QuestionSearcher[2]; // temporary variable to assign randomly picked 2 questions each topic
	string DataWriter1 = " ";		   // question reader from .txt file
	string DataWriter2 = " ";		   // answer reader from .txt file
	int questioncounter = 0;		   // question number assigner

	int TrueCounter = 0;	 // Calculates the user's scroe
	string WrongData2[5][2]; // gets info of wrong answer's question
	string WrongData3[5][2]; // gets info of wrong answer's correct answer

	for (int i = 0; i < 5; i++) // initialization of string array
	{
		for (int j = 0; j < 2; j++)
		{
			WrongData2[i][j] = "";
			WrongData3[i][j] = "";
		}
	}

	TitleNode MidtermTopics[5]; // Array of LinkedList definition

	ifstream fin; // define .txt file
	string line;  // define variable to read lines from .txt file

	srand(time(0));			  // seed of random function
	int RndNum1, RndNum2 = 0; // initialization of random numbers
	int MinRnd = 1;			  // minimum limit of random numbers
	int SizeRnd = 1;		  // maximum limit of random numbers

	fin.open("Hw1TextFile.txt "); // open .txt file to read

	for (int i = 0; i < 5; i++) // read for each title (5 title)
	{
		getline(fin, line);
		while (line != "#") // read until "#"
		{
			if (titlepicker) // if it is the first element of group
			{				 // assignt title name
				MidtermTopics[i].title = line;
				titlepicker = false; // set first element detection to false
			}
			else
			{ // write question and answer
				DataWriter1 = line;
				getline(fin, line);
				DataWriter2 = line;

				MidtermTopics[i].questions.insertLast(Exam(questioncounter, DataWriter1, DataWriter2));
			}
			questioncounter++;
			getline(fin, line);
		}
		questioncounter = 0; // reseting variables
		titlepicker = true;	 // reseting titlepicker
	}

	fin.close(); // closing file after data is written

	cout << "Data Structures Quiz" << endl;
	cout << "Answer the following:" << endl;

	for (int j = 0; j < 5; j++)
	{
		SizeRnd = MidtermTopics[j].questions.length(); // get the question number to define max. size of random number
		do
		{ // do it until two random numbers are not equal
			RndNum1 = MinRnd + rand() % SizeRnd;
			RndNum2 = MinRnd + rand() % SizeRnd;
		} while (RndNum1 == RndNum2);

		// pick the questions
		QuestionSearcher[0] = MidtermTopics[j].questions.search(Exam(RndNum1));
		QuestionSearcher[1] = MidtermTopics[j].questions.search(Exam(RndNum2));

		// write picked questions
		PickedQuestion[0] = QuestionSearcher[0]->data.getQuestion();
		PickedQuestion[1] = QuestionSearcher[1]->data.getQuestion();

		// start the exam
		cout << MidtermTopics[j].title << "Questions" << endl;

		for (int x = 0; x < 2; x++)
		{
			cout << x + 1 << ". " << PickedQuestion[x] << " (T/F): ";
			cin >> UserAnswer;

			while ((UserAnswer != "T") && (UserAnswer != "F")) // check the validity of user answer
			{
				cout << endl;
				cout << "Wrong Answer Type Entered. " << endl;
				cout << "Please Enter \"T\" or \"F\" as answer. It is case sensitive. " << endl;
				cout << "Your Answer (T/F): ";
				cin >> UserAnswer;
			}

			if (UserAnswer == QuestionSearcher[x]->data.getAnswer()) // check if the answer is correct
			{
				TrueCounter++;
			}
			else
			{ // get data of wrong answer (questions and correct answer)
				WrongData2[j][x] = PickedQuestion[x];
				WrongData3[j][x] = QuestionSearcher[x]->data.getAnswer();
			}
		}
		cout << endl;
	}

	cout << "Your Score:  " << TrueCounter << "/10" << endl; // display score

	if (TrueCounter != 10) // check if the all answers were correct
	{
		cout << "Incorrectly answered questions: " << endl;
		; // display wrong answers for each title.

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << WrongData2[i][j] << " " << WrongData3[i][j] << endl;
			}
		}
	}

	return 0;
}
