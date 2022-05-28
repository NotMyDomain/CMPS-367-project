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
	cout << "Add-ons\n";
	if (hasInsurance)
		cout << "+Insurance" << endl;
}

float basicSubscription::generateBill()
{
	float bill = 65.0f; // $65 base price for basic plan
	if (hasInsurance) bill += 5; // add $5 for insurance
	return bill;
}

void basicSubscription::setHasInsurance(bool anInsurance)
{
	hasInsurance = anInsurance;
}

void basicSubscription::customizePlan()
{
	char choice;
	cout << "Would you like to add-on Insurance for $5.00?(Y/N): "; cin >> choice;

	if (choice == 'Y'|| choice == 'y')
	{
		hasInsurance = true;
	}
	else
	{
		hasInsurance = false;
	}
}
