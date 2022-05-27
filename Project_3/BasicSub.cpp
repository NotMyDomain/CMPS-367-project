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
	cout << "GB of data: " << getDataCap() << endl;
}