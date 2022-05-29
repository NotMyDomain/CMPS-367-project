#include "BasicSub.h"
#include <iostream>

using namespace std;


basicSubscription::basicSubscription() : subscription() //default constructor
{
	setDataCap(4); //basic subscription gets 4 gigs of data
	setTier(BASIC);
}

void basicSubscription::print() //Prints the data cap, user's phone number, and account add-ons
{
	cout << "Basic Subscription\n";
	cout << "Gigs of data: " << getDataCap() << endl;
	cout << "Phone number: " << getPhoneNumber() << endl;
	cout << "Add-ons\n";

	//If they have insurance it will display if they do or do not
	if (hasInsurance)
		cout << "+Insurance" << endl;
	else
		cout << "-Insurance" << endl;
}

float basicSubscription::generateBill() //sets the default bill value and generates the total bill if a user has add-ons
{
	float bill = 65.0f; // $65 base price for basic plan
	if (hasInsurance) bill += 5; // add $5 for insurance
	return bill;
}

void basicSubscription::setHasInsurance(bool anInsurance) //set has insurance
{
	hasInsurance = anInsurance;
}

void basicSubscription::customizePlan() //Customizes plan and bill so that they have the choice to add add-ons
{
	char choice; //subscription choice

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
