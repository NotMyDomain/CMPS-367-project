#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include "Subscription.h"

//declare account class,private members, and public functions
class account
{
public:
	account(); //default constructor
	account(std::string fName, std::string lName, int aDay, int aMonth, int aYear, subscription *aSub); 
	//constructor
    std::string getFName();
	//Return first name
	std::string getLName();
	//Return last name
	void setClosed(bool closed);
	//set account as closed
	void setFullName(std::string fName, std::string lName);
	//Set full name
	void setBirthday(int aDay, int aMonth, int aYear); 
	//set full birthday
	void setSub(subscription *aSub); 
	//set subscription tier
	void print();
	// Prints the full name, full birthday, subscription tier, and if account is closed
	bool getClosed(); 
	//get closed status
	std::string toEntry(); //Enters the private members back into file
	~account();
	//destructor
	subscription *getSub();
	//gets subscription tier


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