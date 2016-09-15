#ifndef BIRD_H_ 
#define BIRD2_H_ 

#pragma once
#include <string>
#include <iostream>
using namespace std;
class Bird
{

	friend ostream& operator<<(ostream& os, const Bird& rhs);
	friend istream& operator>>(istream& istr, Bird& rhs);
public:
	Bird();
	Bird(string name, int ID);
	Bird(const Bird& rhs);
	~Bird();

	void setName(string name);
	void setID(int ID);

	int getID() const;
	string getName() const;

	bool operator>(const Bird& rhs) const;
	bool operator<(const Bird& rhs) const;
	bool operator>=(const Bird& rhs) const;
	bool operator<=(const Bird& rhs) const;
	bool operator==(const Bird& rhs) const;
	bool operator!=(const Bird& rhs) const;

	const Bird& operator=(const Bird& rhs);

private:
	string name;
	int ID;

};

#endif