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
    std::string getFName();
	std::string getLName();
	void setClosed(bool closed);
	void setFullName(std::string fName, std::string lName);
	void setBirthday(int aDay, int aMonth, int aYear);
	void setSub(subscription *aSub);
	void print();
	bool getClosed();
	~account();

	subscription *getSub();


private:
	std::string firstName;
	std::string lastName;
	int day;
	int month;
	int year;
	subscription *sub;
	bool closed;
};
#endif // !ACCOUNT_H