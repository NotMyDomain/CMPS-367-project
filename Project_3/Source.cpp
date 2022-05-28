#include "Account.h"
#include "PlatSub.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;


int readCustomerInfo(account allAccounts[]);
void displayOptions(account allAccounts[], int &numAccounts);
bool startPlan(account allAccounts[], int &numAccounts);
account *accountFinder(account allAccounts[], const int numAccounts);
bool editAccountAndPlan(account allAccounts[], const int numAccounts);
void generateSubBill();




int main()
{
	srand(time(NULL)); //set random phone number
	const int numOfAccounts = 512; // Make enough spaces of accounts
	account accounts[numOfAccounts];

	int numAccounts = readCustomerInfo(accounts);
	displayOptions(accounts,numAccounts);
	system("pause");
	return 0;

}

int readCustomerInfo(account allAccounts[])
{

	fstream accounts("accounts.txt", ios::in);
	
	int accountCounter = 0;

	while (!accounts.eof())
	{
		

		//Data elemets entires in file
		string fName;
		string lName;
		int aDay;
		int aMonth;
		int aYear;
		string aTier;
		string aPhoneNumber;
		subscription *aSub;

		//read elements from file
		accounts >> fName >> lName >> aDay >> aMonth >> aYear >> aTier >> aPhoneNumber;

		if (aTier == "BASIC")
		{
			aSub = new basicSubscription();
		}
		else if (aTier == "PREMIUM")
		{
			aSub = new premiumSubscription();
		}
		else if(aTier == "PLATINUM")
		{
			aSub = new platinumSubscription();
		}
		else
		{
			cout << "ERROR: NO PLAN FOUND\n";
			return -1;
		}

		//create account from read data
		aSub->setPhoneNumber(aPhoneNumber);
		account *aCustomerAccount = new account(fName, lName, aDay, aMonth, aYear,aSub);
		allAccounts[accountCounter] = *aCustomerAccount;

		accountCounter++;
	}

	return accountCounter;
}

bool startPlan(account allAccounts[], int &numAccounts)
{
	string fName;
	string lName;
	int aDay;
	int aMonth;
	int aYear;
	string aTier;
	long aPhoneNumber;
	subscription *aSub;

	cout << "First name: "; cin >> fName;
	cout << "Last name: "; cin >> lName;
	cout << "Birthday (dd mm yyyy): "; cin >> aDay >> aMonth >> aYear;

	cout << "\tPlans\n";
	cout << "Basic\tPremium\tPlatinum\n";
	cout << "Which plan would you like?: "; cin >> aTier;

	if (aTier == "Basic")
	{
		aSub = new basicSubscription();
	}
	else if (aTier == "Premium")
	{
		aSub = new premiumSubscription();
	}
	else if (aTier == "Platinum")
	{
		aSub = new platinumSubscription();
	}
	else
	{
		cout << "ERROR: PLEASE CHOOSE FROM LIST OF PLANS\n";
		return false;
	}

	cout << "Your randomly assigned phone number: " << aSub->getPhoneNumber() << endl;

	
	account *newAccount = new account(fName, lName, aDay, aMonth, aYear, aSub);
	allAccounts[numAccounts] = *newAccount;

	numAccounts++;

	return true;
}

account * accountFinder(account allAccounts[], const int numAccounts)
{
	string fName;
	string lName;
	cout << "Please enter full name: "; cin >> fName >> lName;

	for (int i = 0; i < numAccounts; i++)
	{
		if (fName == allAccounts[i].getFName() && lName== allAccounts[i].getLName())
		{
			return &(allAccounts[i]);
		}
	}

	//returns ERROR message if account is not found
	cout << "ERROR: Unable to find account by the name: " << fName<< " " << lName << endl;

	return nullptr;
}

bool editAccountAndPlan(account allAccounts[], const int numAccounts)
{

	account* acct=accountFinder(allAccounts, numAccounts);

		cout << "1. Edit Name\n"
		<< "2. Edit Birthday\n"
		<< "3. Request New number\n"
		<< "4. Edit plan\n";

	int editChoice;

	cout << "What changes would you like to make?: "; cin >> editChoice;

	switch (editChoice)
	{
	case 1:
	{
		string fName;
		string lName;
		cout << "Please edit name: "; cin >> fName >> lName;
		acct->setFullName(fName, lName);
		break;
	}
	case 2:
	{
		int aDay;
		int aMonth;
		int aYear;

		cout << "Please edit birthday: "; cin >> aDay >> aMonth >> aYear;
		acct->setBirthday(aDay, aMonth, aYear);
		break;
	}
	case 3:
	{
		int randomNumber = rand() % 8999999 + 1000000; //randomized phone number assinged
		stringstream ss;
		ss << randomNumber;
		string aPhoneNumber = "909" + ss.str();
		cout << "Here is your new number: " << aPhoneNumber << endl;
		acct->getSub()->setPhoneNumber(aPhoneNumber);
		break;
	}
	case 4:
	{
		delete acct->getSub();

		subscription *aSub;
		string newTier;

		cout << "\tPlans\n";
		cout << "Basic\tPremium\tPlatinum\n";
		cout << "Which plan would you like to change to?: "; cin >> newTier;

		if (newTier == "Basic")
		{
			aSub = new basicSubscription();
		}
		else if (newTier == "Premium")
		{
			aSub = new premiumSubscription();
		}
		else if (newTier == "Platinum")
		{
			aSub = new platinumSubscription();
		}
		else
		{
			cout << "ERROR: PLEASE CHOOSE FROM LIST OF PLANS\n";
			return false;
		}

		acct->setSub(aSub);
		break;
	}
	default:
		cout << "ERROR: UNRECOGNIZED SELECTION\n";
		return false;

		break;
	}

	return true;

}

void displayOptions(account allAccounts[], int &numAccounts)
{
	cout << "\t\tA Phone Company\n";
	cout << setfill('-')<< setw(40) << "\n";
	cout << "1. Start a new plan\n"
		<< "2. Edit account & current plan\n"
		<< "3. View Availble plans & bundles\n"
		<< "4. Cancel plan\n"
		<< "5. Save current changes\n"
		<< "6. Customize plan\n"
		<< "7. Exit and save\n"
		<< "8. DEBUG DELETE LATER: Print all accounts";

	int choice;

	cout << "How can we help you today?\n"
		<< "Please make a selection (1-7) : "; cin >> choice;

	switch (choice)
	{
	case 1:
		startPlan(allAccounts, numAccounts);
		break;
	case 2: 
		editAccountAndPlan(allAccounts, numAccounts);
		break;
	case 3: break;
	case 4: break;
	case 5: break;
	case 6: break;
	case 7: 
		cout << "Thank you for choosing A Phone Company, have a wonderful day!\n";
		break;
	case 8:
		for (int i = 0; i < numAccounts; i++)
		{
			allAccounts[i].print();
		}
	}

}







