#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include "Subscription.h"

class account
{
public:
	account();
	account(std::string fName, std::string lName, int aDay, int aMonth, int aYear, subscription *aSub);
	~account();
	subscription *getSub();


private:
	std::string firstName;
	std::string lastName;
	int day;
	int month;
	int year;
	subscription *sub;
};
#endif // !ACCOUNT_H