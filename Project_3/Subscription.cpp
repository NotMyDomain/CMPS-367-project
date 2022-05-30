#include "Subscription.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

subscription::subscription() //default constructor
{
	int randomNumber = rand() % 8999999 + 1000000; //randomized phone number assinged
	stringstream ss;
	ss << randomNumber;
	phoneNumber = "909" + ss.str(); //default area code since we work in the 909 area + string of random numbers

	dataCap = -1; //not set 
}


string subscription::getPhoneNumber() //returns user's phone number
{
	return phoneNumber;
}

void subscription::setDataCap(int aDataCap) //sets data cap
{
	dataCap = aDataCap;
}

void subscription::setTier(subscriptionLevel aTier) //set subscription tier
{
	tier = aTier;
}

void subscription::setPhoneNumber(string aPhoneNumber) //set customer's phone number
{
	phoneNumber = aPhoneNumber;
}

int subscription::getDataCap() //returns Data cap
{
	return dataCap;
}

subscriptionLevel subscription::getTier() //get subscription level tier
{
	return tier;
}