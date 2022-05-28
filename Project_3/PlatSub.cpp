#include "PlatSub.h"
#include <iostream>

using namespace std;

platinumSubscription::platinumSubscription() : premiumSubscription()
{
	setDataCap(8); //platinum subscription gets 6 gigs of data
	setTier(PLATINUM);
	set24HrService(true);
	setStreamingServices(true);
	setTVPackage(true);
}

void platinumSubscription::print()
{
	cout << "Platinum Subscription\n";
	cout << "Gigs of Data: " << getDataCap() << endl;
	cout << "Phone number: " << getPhoneNumber() << endl;
	cout << "Add-ons\n";
	cout << "+Insurance\n";
	cout << "+Streaming Services\n";
	cout << "+24-hr Services\n";
	cout << "+TV Package\n";
	
	if (hasMusicService)
		cout << "+Premium Music Service\n";
}

float platinumSubscription::generateBill()
{
	float bill = 160.0f; // $160 base price for platinum plan

	// Platinum gets previous addons for free
	if (hasMusicService) bill += 30.0f;

	return bill;
}

void platinumSubscription::setMusicService(bool aMusicService)
{
	hasMusicService = aMusicService;
}

void platinumSubscription::customizePlan()
{
	char choice;
	cout << "Would you like to add-on a Premium Music service for $30.00?(Y/N): "; cin >> choice;

	if (choice == 'Y' || choice == 'y')
	{
		hasMusicService = true;
	}
	else
	{
		hasMusicService = false;
	}

}
