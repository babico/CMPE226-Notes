
#ifndef Exam_H_
#define Exam_H_
#endif

#include <iostream>
#include <string>

namespace std{

class Exam {
private:
	int id;
	string question, answer;
public:
	Exam(int a=0, string n="", string sn="" ){
		id = a;
		question = n;
		answer = sn;
	}

	bool operator==(const Exam &other){
		return (id == other.id);
	}

	friend ostream& operator<<(ostream &out, const Exam &p){
		out << "(" << p.question << " " << p.answer <<","<< p.id <<")";
		return out;
	}

	int getId() const {
		return id;
	}

	void setId(int age) {
		this->id = age;
	}

	const string& getQuestion() const {
		return question;
	}

	void setQuestion(const string &question) {
		this->question =question;
	}

	const string& getAnswer() const {
		return answer;
	}

	void setAnswer(const string &answer) {
		this->answer = answer;
	}
};

}
