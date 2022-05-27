#pragma once
#ifndef PLATSUB_H
#define PLATSUB_H

#include "PremSub.h"

class platinumSubscription : public premiumSubscription
{
public:
	platinumSubscription();
	void print() override;
private:
};
#endif // !PLATSUB_H

