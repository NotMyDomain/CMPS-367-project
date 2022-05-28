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
	cout << "Add-ons\n";
	cout << "+Insurance\n";
	
	if (hasStreamingServices)
		cout << "+Streaming Services\n";

	if (has24HrService)
		cout << "+24-hr Services\n";

	if (hasTVPackage)
		cout << "+TV Package\n";
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

void premiumSubscription::customizePlan()
{
	char choice;
	cout << "Would you like to add-on the Video Streaming package for $10.00?(Y/N): "; cin >> choice;

	if (choice == 'Y' || choice == 'y')
		hasStreamingServices = true;
	else
		hasStreamingServices = false;

	cout << "Would you like to add-on the 24-Hr Service for $15.00?(Y/N): "; cin >> choice;

	if (choice == 'Y' || choice == 'y')
		has24HrService = true;
	else
		has24HrService = false;

	cout << "Would you like to add-on the TV package for $20.00?(Y/N): "; cin >> choice;

	if (choice == 'Y' || choice == 'y')
		hasTVPackage = true;
	else
		hasTVPackage = false;
}
