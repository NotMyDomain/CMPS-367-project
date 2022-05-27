#include "Subscription.h"
#include <cstdlib>

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

int subscription::getDataCap()
{
	return dataCap;
}

subscriptionLevel subscription::getTier()
{
	return tier;
}