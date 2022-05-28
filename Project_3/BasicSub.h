#pragma once
#ifndef BASICSUB_H
#define BASICSUB_H

#include "Subscription.h"

class basicSubscription : public subscription
{
public:
	basicSubscription();
	void print() override;
	float generateBill() override;
	void setHasInsurance(bool);
	void customizePlan() override;

private:
	bool hasInsurance;
};

#endif // !BASICSUB_H

