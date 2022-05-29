#include "PlatSub.h"
#include <iostream>

using namespace std;

platinumSubscription::platinumSubscription() : premiumSubscription() //default constructor
{
	setDataCap(8); //platinum subscription gets 6 gigs of data
	setTier(PLATINUM); //set tier as platinum with enum type
	set24HrService(true); //Platinum gets all previous add-ons by default
	setStreamingServices(true);
	setTVPackage(true);
}

void platinumSubscription::print() //Prints the data cap, user's phone number, and account add-ons
{
	cout << "Platinum Subscription\n";
	cout << "Gigs of Data: " << getDataCap() << endl;
	cout << "Phone number: " << getPhoneNumber() << endl;
	cout << "Add-ons\n"; //all of the addons are added to default
	cout << "+Insurance\n";
	cout << "+Streaming Services\n";
	cout << "+24-hr Services\n";
	cout << "+TV Package\n";
	
	//see if they have services selected
	if (hasMusicService)
		cout << "+Premium Music Service\n";
	else
		cout << "-Premium Music Service\n";
}

float platinumSubscription::generateBill()
{
	float bill = 160.0f; // $160 base price for platinum plan

	// Platinum gets previous addons for free
	if (hasMusicService) bill += 30.0f; //$30 for music services

	return bill;
}

void platinumSubscription::setMusicService(bool aMusicService) //sets music services
{
	hasMusicService = aMusicService;
}

void platinumSubscription::customizePlan() //Customizes plan and bill so that they have the choice to add add-ons
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
