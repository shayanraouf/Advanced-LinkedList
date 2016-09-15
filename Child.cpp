
#include "stdafx.h"
#include "Child.h"
#include <iostream>
#include <string>

using namespace std;

Child::Child()
{
	firstName = "";
	lastName = "";
	age = 0;
}

Child::Child(string firstName, string lastName, int age)
{
	setName(firstName, lastName);
	setAge(age);
}

Child::~Child()
{
}

Child::Child(const Child& rhs)
{
	*this = rhs;
}

const Child& Child::operator=(const Child& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	this->firstName = rhs.firstName;
	this->lastName = rhs.lastName;
	this->age = rhs.age;
	return *this;
}

bool Child::operator==(const Child& rhs) const
{
	return (firstName == rhs.firstName) && (lastName == rhs.lastName) && (age == rhs.age);
}

bool Child::operator!=(const Child& rhs) const
{
	return (firstName != rhs.firstName) || (lastName != rhs.lastName) || (age != rhs.age);
}

void Child::setName(string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
}

void Child::setAge(int age)
{
	this->age = age;
}
string Child::getFirstName() const
{
	return firstName;
}

string Child::getLastName() const
{
	return lastName;
}

int Child::getAge() const
{
	return age;
}


ostream& operator<<(ostream& os, const Child& rhs)
{
	os << rhs.getFirstName() << rhs.getLastName() << rhs.getAge();
	return os;
}

istream& operator>>(istream& istream, Child& rhs)
{
	istream >> rhs.firstName >> rhs.lastName >> rhs.age;
	return istream;
}

bool Child::operator<(const Child& rhs) const
{
	if (lastName == rhs.lastName)
	{
		if (firstName < rhs.firstName)
		{
			return true;
		}
	}

	else if (lastName < rhs.lastName)
	{
		return true;
	}

	return false;
}

bool Child::operator<=(const Child& rhs) const
{
	if (lastName == rhs.lastName)
	{
		if (firstName <= rhs.firstName)
		{
			return true;
		}
	}

	else if (lastName <= rhs.lastName)
	{
		return true;
	}

	return false;
}

bool Child::operator>(const Child& rhs) const
{
	if (lastName == rhs.lastName)
	{
		if (firstName > rhs.firstName)
		{
			return true;
		}
	}

	else if (lastName > rhs.lastName)
	{
		return true;
	}

	return false;
}

bool Child::operator>=(const Child& rhs) const
{
	if (lastName == rhs.lastName)
	{
		if (firstName <= rhs.lastName)
		{
			return true;
		}
	}

	else if (lastName <= rhs.lastName)
	{
		return true;
	}

	return false;
}
