#pragma once
#ifndef BASICSUB_H
#define BASICSUB_H
#include "Subscription.h"

//declare the first derived class BasicSubscription ,private members, and public functions
class basicSubscription : public subscription
{
public:
	basicSubscription(); //default constructor
	void print() override;
	//Prints the data cap, user's phone number, and account add-ons
	float generateBill() override;
	//sets the default bill value and generates the total bill if a user has add-ons
	void setHasInsurance(bool);
	//sets if the user has insurance
	void customizePlan() override;
	//Customizes plan and bill so that they have the choice to add add-ons

private:
	bool hasInsurance;
};

#endif // !BASICSUB_H

