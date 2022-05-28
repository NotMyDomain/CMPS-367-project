#include "BasicSub.h"
#include <iostream>

using namespace std;

basicSubscription::basicSubscription() : subscription()
{
	setDataCap(4); //basic subscription gets 4 gigs of data
	setTier(BASIC);
}

void basicSubscription::print()
{
	cout << "Basic Subscription\n";
	cout << "Gigs of data: " << getDataCap() << endl;
	cout << "Phone number: " << getPhoneNumber() << endl;
}