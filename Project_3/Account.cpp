#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

account::account()
{
	firstName = "No First Name";
	lastName = "No Last Name";
	Bday = 0;
	Bmonth = 0;
	Byear = 0;
	sub = NULL;
	Monthly_bill = 0;
	IsClosed = false;
}

account::account(string fName, string lName, int aDay, int aMonth, int aYear, subscription *aSub)
{
	firstName = fName;
	lastName = lName;
	Bday = aDay;
	Bmonth = aMonth;
	Byear = aYear;
	sub = aSub;
	IsClosed = false;
}

void account::setInfo(std::string fName, std::string lName, int aDay, int aMonth, int aYear, subscription *aSub)
{
	firstName = fName;
	lastName = lName;
	Bday = aDay;
	Bmonth = aMonth;
	Byear = aYear;
	sub = aSub;
	IsClosed = false;
}

string account::getFName()
{

	return firstName;
}

string account::getLName()
{
	return lastName;
}

int account::getBday()
{
	return Bday;
}

int account::getBmonth()
{
	return Bmonth;
}

int account::getByear()
{
	return Byear;
}

void account::setFullName(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
}

void account::setBirthday(int aDay, int aMonth, int aYear)
{
	Bday = aDay;
	Bmonth = aMonth;
	Byear = aYear;
}

void account::setSub(subscription * aSub)
{
	sub = aSub;
}

void account::setClosed()
{
	IsClosed = true;
}

bool account::getClosed()
{
	return IsClosed;
}

int account::getPhoneNumber()
{
	return (*sub).getPhoneNumber();
}

void account::printInfo()
{
	cout << "This is the First name: " << firstName << endl;
	cout << "This is the Last name: " << lastName << endl;
	cout << "This is the Birth date (m/d/y): " << Bmonth << "/" << Bday << "/" << Byear << endl;
	cout << "This is the Subscription: " << account::getSub() << endl;
	cout << "This is the Monthly Bill: " << Monthly_bill << endl;
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
