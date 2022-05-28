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
	void setInfo(std::string fName, std::string lName, int aDay, int aMonth, int aYear, subscription *aSub);
    std::string getFName();
	std::string getLName();
	int getBday();
	int getBmonth();
	int getByear();
	void setFullName(std::string fName, std::string lName);
	void setBirthday(int aDay, int aMonth, int aYear);
	void setSub(subscription *aSub);
	//void setMonthlyBill(subscription *aSub);
	int getPhoneNumber();
	void setClosed();
	bool getClosed();
	~account();
	void printInfo();
	subscription *getSub();


private:
	std::string firstName;
	std::string lastName;
	int Bday;
	int Bmonth;
	int Byear;
	subscription *sub;
	int Monthly_bill;
	bool IsClosed;
};
#endif // !ACCOUNT_H