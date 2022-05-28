#include "PremSub.h"
#include <iostream>
using namespace std;

premiumSubscription::premiumSubscription() : basicSubscription()
{
	setDataCap(6); //premium subscription gets 6 gigs of data
	setTier(PREMIUM);
}

void premiumSubscription::print()
{
	cout << "Premium Subscription\n";
	cout << "Gigs of Data: " << getDataCap() << endl;
	cout << "Phone number: " << getPhoneNumber() << endl;
}