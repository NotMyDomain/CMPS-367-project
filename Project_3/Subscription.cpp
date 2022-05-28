#include "Subscription.h"
#include <cstdlib>
#include <iostream>

using namespace std;

subscription::subscription()
{
	phoneNumber = rand() % 8999999999 + 1000000000; //randomized phone number assinged
	dataCap = -1; //not set 
}


int subscription::getPhoneNumber()
{
	return phoneNumber;
}

void subscription::setDataCap(int aDataCap)
{
	dataCap = aDataCap;
}

void subscription::setTier(subscriptionLevel aTier)
{
	tier = aTier;
}

void subscription::setPhoneNumber(long aPhoneNumber)
{
	phoneNumber = aPhoneNumber;
}

int subscription::getDataCap()
{
	return dataCap;
}

subscriptionLevel subscription::getTier()
{
	return tier;
}

void subscription::print()
{
	cout << "This is the phone Number: " << phoneNumber << endl;
	cout << "This is the data cap: " << dataCap << endl;
	switch (tier)
	{
	case 0:
		cout << "This account has a Basic plan\n";
		break;
	case 1: 
		cout << "This account has a Premium plan\n";
		break;
	case 2:
		cout << "This account has a platinum plan\t";
		break;
	}
}