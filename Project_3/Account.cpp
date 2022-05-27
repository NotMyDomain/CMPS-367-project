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

account::~account()
{
	delete sub;
	sub = NULL;
}

subscription *account::getSub()
{
	return sub;
}