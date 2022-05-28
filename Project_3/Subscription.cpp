#include "Subscription.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

subscription::subscription()
{
	int randomNumber = rand() % 8999999 + 1000000; //randomized phone number assinged
	stringstream ss;
	ss << randomNumber;
	phoneNumber = "909" + ss.str();

	dataCap = -1; //not set 
}


string subscription::getPhoneNumber()
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

void subscription::setPhoneNumber(string aPhoneNumber)
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