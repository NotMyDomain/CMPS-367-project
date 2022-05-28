#pragma once
#ifndef PLATSUB_H
#define PLATSUB_H

#include "PremSub.h"

class platinumSubscription : public premiumSubscription
{
public:
	platinumSubscription();
	void print() override;
	float generateBill() override;
	void setMusicService(bool);
	void customizePlan() override;
private:
	bool hasMusicService;
};
#endif // !PLATSUB_H

