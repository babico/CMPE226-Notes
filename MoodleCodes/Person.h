/*
 * Person.h
 *
 *  Created on: Nov 25, 2020
 *      Author: ziya
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

namespace std
{

	class Person
	{
	private:
		int id;
		string name, surname;

	public:
		Person(int a = 0, string n = "", string sn = "")
		{
			id = a;
			name = n;
			surname = sn;
		}

		bool operator==(const Person &other)
		{
			return (id == other.id);
		}

		friend ostream &operator<<(ostream &out, const Person &p)
		{
			out << "(" << p.name << " " << p.surname << "," << p.id << ")";
			return out;
		}

		int getId() const
		{
			return id;
		}

		void setId(int age)
		{
			this->id = age;
		}

		const string &getName() const
		{
			return name;
		}

		void setName(const string &name)
		{
			this->name = name;
		}

		const string &getSurname() const
		{
			return surname;
		}

		void setSurname(const string &surname)
		{
			this->surname = surname;
		}
	};

}
#endif /* PERSON_H_ */
