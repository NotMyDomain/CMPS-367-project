#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

enum subscriptionLevel{BASIC,PREMIUM,PLATINUM};

class subscription
{
public:
	subscription();
	int getPhoneNumber();
	void setDataCap(int);
	void setTier(subscriptionLevel aTier);
	int getDataCap();
	subscriptionLevel getTier();
	virtual void print(){}
private:
	long phoneNumber;
	int dataCap;
	subscriptionLevel tier;
	
};

class account
{
public:
	account();
	account(string fName, string lName, int aDay, int aMonth, int aYear, subscription *aSub);
	~account();
	subscription *getSub();


private:
	string firstName;
	string lastName;
	int day;
	int month;
	int year;
	subscription *sub;
};

class basicSubscription: public subscription
{
public:
	basicSubscription();
	void print() override;
private:


};

class premiumSubscription: public basicSubscription
{
public:
	premiumSubscription();
	void print() override;
private:
};

class platinumSubscription : public premiumSubscription
{
public:
	platinumSubscription();
	void print() override;
private:
};

void readCustomerInfo();
void displayOptions();
void startPlan();
void editPlan();
void generateSubBill();




int main()
{
	srand(time(NULL)); //set random phone number
	displayOptions();
	system("pause");
	return 0;

}

void readCustomerInfo()
{

}

void displayOptions()
{
	cout << "\t\tA Phone Company\n";
	cout << setfill('-')<< setw(40) << "\n";
	cout << "1. Start a new plan\n"
		<< "2. Edit current plan\n"
		<< "3. View Availble plans & bundles\n"
		<< "4. Cancel plan\n"
		<< "5. Save current changes\n"
		<< "6. Generate monthly bill\n"
		<< "7. Exit and save\n";

	int choice;

	cout << "How can we help you today?\n"
		<< "Please make a selection (1-7) : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	case 6: break;
	case 7: 
		cout << "Thank you for choosing A Phone Company, have a wonderful day!\n";
		break;


	}

}

subscription::subscription()
{

	phoneNumber = rand()% 8999999999+1000000000; //randomized phone number assinged
	dataCap = -1; //not set 
}


int subscription::getPhoneNumber()
{
	return phoneNumber;
}

void subscription::setDataCap(int aDataCap)
{
	dataCap = aDataCap;
}

void subscription::setTier(subscriptionLevel aTier)
{
	tier = aTier;
}

int subscription::getDataCap()
{
	return dataCap;
}

subscriptionLevel subscription::getTier()
{
	return tier;
}

account::account()
{
	firstName = "No First Name";
	lastName = "No Last Name";
	day = 0;
	month = 0;
	year = 0;
	sub = NULL;
}

account::account(string fName, string lName, int aDay, int aMonth, int aYear, subscription *aSub)
{
	firstName = fName;
	lastName = lName;
	day = aDay;
	month = aMonth;
	year = aYear;
	sub = aSub;
}

account::~account()
{
	delete sub;
	sub = NULL;
}

subscription *account::getSub()
{
	return sub;
}

basicSubscription::basicSubscription() : subscription()
{
	setDataCap(4); //basic subscription gets 4 gigs of data
	setTier(BASIC);
}

void basicSubscription::print()
{
	cout << "Basic Subscription\n";
	cout << "Gigs of data: " << getDataCap() << endl;
}

premiumSubscription::premiumSubscription(): basicSubscription()
{
	setDataCap(6); //premium subscription gets 6 gigs of data
	setTier(PREMIUM);
}

void premiumSubscription::print()
{
	cout << "Premium Subscription\n";
	cout << "Gigs of Data: " << getDataCap() << endl;
}

platinumSubscription::platinumSubscription(): premiumSubscription()
{
	setDataCap(8); //platinum subscription gets 6 gigs of data
	setTier(PLATINUM);
}

void platinumSubscription::print()
{
	cout << "Platinum Subscription\n";
	cout << "Gigs of Data: " << getDataCap() << endl;
}
