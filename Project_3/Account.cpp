#include "Account.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

account::account() //default constructor
{
	firstName = "No First Name";
	lastName = "No Last Name";
	day = 0;
	month = 0;
	year = 0;
	sub = NULL;
}

account::account(string fName, string lName, int aDay, int aMonth, int aYear, subscription *aSub) //constructor
{
	firstName = fName;
	lastName = lName;
	day = aDay;
	month = aMonth;
	year = aYear;
	sub = aSub;
}


string account::getFName() //returns first name
{
	return firstName;
}

string account::getLName() //returns last name
{
	return lastName;
}

void account::setClosed(bool aClosed) //set closed
{
	closed = aClosed;
}

void account::setFullName(string fName, string lName) //set full name
{
	firstName = fName;
	lastName = lName;
}

void account::setBirthday(int aDay, int aMonth, int aYear) //set full birthday
{
	day = aDay;
	month = aMonth;
	year = aYear;
}

void account::setSub(subscription * aSub) //set subsciption tier
{
	sub = aSub;
}

void account::print() //// Prints the full name, full birthday, subscription tier, and if account is closed
{
	cout << endl;
	cout << "First name: " << firstName << endl;
	cout << "Last name: " << lastName << endl;
	cout << "Birthday: " << month << "/" << day << "/" << year << endl;
	sub->print();

	//display account status
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

bool account::getClosed() //get closed value
{
	return closed;
}

int account::getBday()
{
	return day;
}

int account::getBmonth()
{
	return month;
}

int account::getByear()
{
	return year;
}

/*
void account::toEntry(int counter_test) //Enters the private members back into file
{
	ofstream accountsTxt("accounts.txt");
	string tier;
	string line;

	//thier tier corresponds to what will be read to the file
	if (sub->getTier() == BASIC) tier = "BASIC";
	else if (sub->getTier() == PREMIUM) tier = "PREMIUM";
	else if (sub->getTier() == PLATINUM) tier = "PLATINUM";

	//Put the information back into the file in the correct format

	accountsTxt << firstName << " " << lastName << " " << day << " " << month << " " << year << " " << tier << " " << sub->getPhoneNumber() << " " << closed << endl;
	cout << "I am here\n";

	accountsTxt.close();
}
*/

//destructor
account::~account()
{
	delete sub;
	sub = NULL;
}

//returns subscription tier
subscription *account::getSub()
{
	return sub;
}