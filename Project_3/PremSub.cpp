#include "PremSub.h"
#include <iostream>
using namespace std;

premiumSubscription::premiumSubscription() : basicSubscription()
{
	setDataCap(6); //premium subscription gets 6 gigs of data
	setTier(PREMIUM);

	setHasInsurance(true); // premium gets insurance by default
}

void premiumSubscription::print()
{
	cout << "Premium Subscription\n";
	cout << "Gigs of Data: " << getDataCap() << endl;
	cout << "Phone number: " << getPhoneNumber() << endl;
}

float premiumSubscription::generateBill()
{
	float bill = 120.0f; // $120 base price for basic plan
	// premium gets insurance for free
	if (hasStreamingServices) bill += 10.0f;
	if (hasTVPackage)bill += 20.0f;
	if (has24HrService) bill += 15.0f;
	return bill;
}

void premiumSubscription::setStreamingServices(bool aStreamingService)
{
	hasStreamingServices = aStreamingService;
}

void premiumSubscription::setTVPackage(bool aTVPackage)
{
	hasTVPackage = aTVPackage;
}

void premiumSubscription::set24HrService(bool a24HrService)
{
	has24HrService = a24HrService;
}
