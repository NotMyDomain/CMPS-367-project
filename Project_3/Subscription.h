#pragma once
#ifndef  SUBSCRIPTION_H
#define SUBSCRIPTION_H

enum subscriptionLevel { BASIC, PREMIUM, PLATINUM }; //From what I understand, Basic is now set to the value 0, Premium is set to the value of 1, and Platinum is 2

class subscription
{
public:
	subscription();
	int getPhoneNumber();
	void setDataCap(int);
	void setTier(subscriptionLevel aTier);
	void setPhoneNumber(long);
	int getDataCap();
	subscriptionLevel getTier();
	void print();
private:
	long phoneNumber;
	int dataCap;
	subscriptionLevel tier;

};

#endif // ! SUBSCRIPTION_H
