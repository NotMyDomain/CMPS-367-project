#pragma once
#ifndef PREMSUB_H
#define PREMSUB_H

#include "BasicSub.h"

class premiumSubscription : public basicSubscription
{
public:
	premiumSubscription();
	void print() override;
	float generateBill() override;
	void setStreamingServices(bool aStreamingService);
	void setTVPackage(bool aTVPackage);
	void set24HrService(bool a24HrService);
private:
	bool hasStreamingServices;
	bool hasTVPackage;
	bool has24HrService;
};


#endif // PremSub

