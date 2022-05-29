#pragma once
#ifndef PLATSUB_H
#define PLATSUB_H

#include "PremSub.h"

//declare the third derived class PlatinumSubscription from premium ,private members, and public functions
class platinumSubscription : public premiumSubscription
{
public:
	platinumSubscription();
	//default constructor
	void print() override;
	//Prints the data cap, user's phone number, and account add-ons
	float generateBill() override;
	//Prints the data cap, user's phone number, and account add-ons
	void setMusicService(bool);
	//sets the Music Service
	void customizePlan() override;
	//Customizes plan and bill so that they have the choice to add add-ons
private:
	bool hasMusicService;
};
#endif // !PLATSUB_H

