#include "PlatSub.h"
#include <iostream>

using namespace std;

platinumSubscription::platinumSubscription() : premiumSubscription()
{
	setDataCap(8); //platinum subscription gets 6 gigs of data
	setTier(PLATINUM);
}

void platinumSubscription::print()
{
	cout << "Platinum Subscription\n";
	cout << "Gigs of Data: " << getDataCap() << endl;
}