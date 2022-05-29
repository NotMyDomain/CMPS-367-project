#pragma once
#ifndef PREMSUB_H
#define PREMSUB_H

#include "BasicSub.h"

//declare the second derived class PremiumSubscription from basic ,private members, and public functions
class premiumSubscription : public basicSubscription
{
public:
	premiumSubscription(); //default constructor
	void print() override;
	//Prints the data cap, user's phone number, and account add-ons
	float generateBill() override;
	//sets the default bill value and generates the total bill if a user has add-ons
	void setStreamingServices(bool aStreamingService);
	//Sets streaming services 
	void setTVPackage(bool aTVPackage);
	//Sets TV package
	void set24HrService(bool a24HrService);
	//sets 24hr services
	void customizePlan() override;
	//Customizes plan and bill so that they have the choice to add add-ons
private:
	bool hasStreamingServices;
	bool hasTVPackage;
	bool has24HrService;
};


#endif // PremSub

