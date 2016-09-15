#ifndef CHILD_H_ 
#define CHILD_H_ 

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
class Child
{
	friend ostream& operator<<(ostream& os, const Child& rhs);
	friend istream& operator>>(istream& istr, Child& rhs);
public:
	Child();
	Child(string firstName, string lastName, int age);
	Child(const Child& rhs);
	~Child();

	//accesors/mutators
	void setName(string firstName, string lastName);
	void setAge(int age);

	string getFirstName() const;
	string getLastName() const;
	int getAge() const;

	bool operator>(const Child& rhs) const;
	bool operator<(const Child& rhs) const;
	bool operator>=(const Child& rhs) const;
	bool operator<=(const Child& rhs) const;
	bool operator==(const Child& rhs) const;
	bool operator!=(const Child& rhs) const;

	const Child& operator=(const Child& rhs);

private:
	string firstName;
	string lastName;
	int age;
};

#endif