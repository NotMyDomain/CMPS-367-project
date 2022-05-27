#include "Account.h"
#include "PlatSub.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;


int readCustomerInfo(account allAccounts[]);
void displayOptions(account allAccounts[], int &numAccounts);
bool startPlan(account allAccounts[], int &numAccounts);
account *accountFinder(account allAccounts[], const int numAccounts);
bool editPlan(account allAccounts[], const int numAccounts);
void generateSubBill();




int main()
{
	const int numOfAccounts = 512; // Make enough spaces of accounts
	account accounts[numOfAccounts];

	int numAccounts = readCustomerInfo(accounts);

	srand(time(NULL)); //set random phone number
	displayOptions(accounts,numAccounts);
	system("pause");
	return 0;

}

int readCustomerInfo(account allAccounts[])
{

	fstream accounts("accounts.txt", ios::in);
	accounts.open;
	
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
		long aPhoneNumber;
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
		account aCustomerAccount(fName, lName, aDay, aMonth, aYear,aSub);

		allAccounts[accountCounter] = aCustomerAccount;

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

	
	account newAccount(fName, lName, aDay, aMonth, aYear, aSub);

	allAccounts[numAccounts] = newAccount;

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

bool editPlan(account allAccounts[], const int numAccounts)
{

	account* acct=accountFinder(allAccounts, numAccounts);

	cout << "What changes would you like to make?\n"
		<< "1. Edit Name\n"
		<< "2. Edit Birthday\n"
		<< "3. Request New number\n"
		<< "4. Edit plan\n";

	int editChoice;

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
		long newPhoneNumber = rand() % 8999999999 + 1000000000;
		cout << "Here is your new number: " << newPhoneNumber << endl;
		acct->getSub()->setPhoneNumber(newPhoneNumber);
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
		<< "7. Exit and save\n";

	int choice;

	cout << "How can we help you today?\n"
		<< "Please make a selection (1-7) : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		startPlan(allAccounts, numAccounts);
		break;
	case 2: 
		editPlan()
		break;
	case 3: break;
	case 4: break;
	case 5: break;
	case 6: break;
	case 7: 
		cout << "Thank you for choosing A Phone Company, have a wonderful day!\n";
		break;


	}

}







