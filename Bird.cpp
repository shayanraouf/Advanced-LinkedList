
#include "stdafx.h"
#include "Bird.h"
#include <string>
#include <iostream>

using namespace std;
Bird::Bird()
{
	name = "";
	ID = -1;
}
//constructor
Bird::Bird(string name, int ID) 
{
	setName(name);
	setID(ID);
}
//copy constructor
Bird::Bird(const Bird& rhs)
{
	*this = rhs;
}
//destructor 
Bird::~Bird()
{
}
void Bird::setName(string name)
{
	this->name = name;
}
void Bird::setID(int ID)
{
	this->ID = ID;
}

int Bird::getID() const
{
	return ID;
}
string Bird::getName() const
{
	return name;
}

bool Bird::operator>(const Bird& rhs) const
{
	return ID > rhs.ID;
}

bool Bird::operator<(const Bird& rhs) const
{
	return ID < rhs.ID;
}
bool Bird::operator>=(const Bird& rhs) const
{
	return ID >= rhs.ID;
}
bool Bird::operator<=(const Bird& rhs) const
{
	return ID <= rhs.ID;
}
bool Bird::operator==(const Bird& rhs) const
{
	return (ID == rhs.ID) && (name == rhs.name);
}
bool Bird::operator!=(const Bird& rhs) const
{
	return (ID != rhs.ID) || (name != rhs.name);
}

const Bird& Bird::operator=(const Bird& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	name = rhs.name;
	ID = rhs.ID;
}

ostream& operator<<(ostream& os, const Bird& rhs)
{
	os << rhs.getName() << rhs.getID();
	return os;
}

istream& operator>>(istream& istr, Bird& rhs)
{
	istr >> rhs.name >> rhs.ID;
	return istr;
}

