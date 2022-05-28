#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

account::account()
{
	firstName = "No First Name";
	lastName = "No Last Name";
	day = 0;
	month = 0;
	year = 0;
	sub = NULL;
}

account::account(string fName, string lName, int aDay, int aMonth, int aYear, subscription *aSub)
{
	firstName = fName;
	lastName = lName;
	day = aDay;
	month = aMonth;
	year = aYear;
	sub = aSub;
}

string account::getFName()
{

	return firstName;
}

string account::getLName()
{
	return lastName;
}

void account::setClosed(bool aClosed)
{
	closed = aClosed;
}

void account::setFullName(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
}

void account::setBirthday(int aDay, int aMonth, int aYear)
{
	day = aDay;
	month = aMonth;
	year = aYear;
}

void account::setSub(subscription * aSub)
{
	sub = aSub;
}

void account::print()
{
	cout << endl;
	cout << "First name: " << firstName << endl;
	cout << "Last name: " << lastName << endl;
	cout << "Birthday: " << month << "/" << day << "/" << year << endl;
	sub->print();

	if (closed)
	{
		cout << "Account status: Closed" << endl;
	}
	else
	{
		cout << "Account status: Open" << endl;
	}
	cout << endl;
}

bool account::getClosed()
{
	return closed;
}


account::~account()
{
	delete sub;
	sub = NULL;
}

subscription *account::getSub()
{
	return sub;
}