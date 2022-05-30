#pragma once
#ifndef  SUBSCRIPTION_H
#define SUBSCRIPTION_H
#include <iostream>
#include <string>

enum subscriptionLevel { BASIC, PREMIUM, PLATINUM };
//Declare subscription tiers as  an enum type

//decalre the Base class Subscription,private members, and public functions
class subscription
{
public:
	subscription(); // default constructor
	void setDataCap(int);
	//sets Data limit for subscriptions
	void setTier(subscriptionLevel aTier);
	// set subscription tier
	void setPhoneNumber(std::string);
	//set customer's phone number
	int getDataCap();
	//returns Data cap
	std::string getPhoneNumber();
	//get customer's phone number
	subscriptionLevel getTier();
	//get subscription level tier
	virtual void print() {}
	//virtual print function that correlates to each tier
	virtual float generateBill() { return 0; }
	//virtual function to generate bill for each customer
	virtual void customizePlan() {}
	//virtual function to customize plans for each customer
private:
	std::string phoneNumber;
	int dataCap;
	subscriptionLevel tier;
};

#endif // ! SUBSCRIPTION_H
