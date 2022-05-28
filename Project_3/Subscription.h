#pragma once
#ifndef  SUBSCRIPTION_H
#define SUBSCRIPTION_H
#include <iostream>
#include <string>

enum subscriptionLevel { BASIC, PREMIUM, PLATINUM };

class subscription
{
public:
	subscription();
	void setDataCap(int);
	void setTier(subscriptionLevel aTier);
	void setPhoneNumber(std::string);
	int getDataCap();
	std::string getPhoneNumber();
	subscriptionLevel getTier();
	virtual void print() {}
private:
	std::string phoneNumber;
	int dataCap;
	subscriptionLevel tier;

};

#endif // ! SUBSCRIPTION_H
