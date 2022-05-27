#pragma once
#ifndef  SUBSCRIPTION_H
#define SUBSCRIPTION_H

enum subscriptionLevel { BASIC, PREMIUM, PLATINUM };

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
	virtual void print() {}
private:
	long phoneNumber;
	int dataCap;
	subscriptionLevel tier;

};

#endif // ! SUBSCRIPTION_H
