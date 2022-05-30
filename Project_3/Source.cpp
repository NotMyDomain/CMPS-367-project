/*---------------------------------------------------------------------
Name:			Lauren Lazos,Edwin Navarro, & Erik McAtee
Assignment:					  Project 3
Date:						 May 29, 2022
Description: This program manages a Phone Company's customer data
		base and helps manage customers profile's, edit plans, and 
							view accounts. 
---------------------------------------------------------------------*/
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
//Reads customer info from file
void displayOptions(account allAccounts[], int &numAccounts);
//Displays options that customers can choose from
bool startPlan(account allAccounts[], int &numAccounts);
//starts a new plan for a new customer
account *accountFinder(account allAccounts[], const int numAccounts);
//finds account and determines if it exists
bool editAccountAndPlan(account allAccounts[], const int numAccounts);
//Displays options that a user can choose from to edit account

int main()
{
	srand(time(NULL)); //set random phone number

	const int numOfAccounts = 1000; // Make enough spaces for accounts
	
	account accounts[numOfAccounts];

	int numAccounts = readCustomerInfo(accounts); //read from file

	if (numAccounts < 0) return -1; // Quit if we get an error from readCustomerInfo
	
	displayOptions(accounts,numAccounts); //display options to choose from
	system("pause");
	return 0;

}

//Reads from "accounts.txt" and sets variables
int readCustomerInfo(account allAccounts[])
{

	fstream accounts("accounts.txt", ios::in);
	
	//set counter to track num of accounts
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
		bool aClosed;

		//read elements from file
		accounts >> fName >> lName >> aDay >> aMonth >> aYear >> aTier >> aPhoneNumber >> aClosed;

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

		//creates account from data read
		aSub->setPhoneNumber(aPhoneNumber);
		account *aCustomerAccount = new account(fName, lName, aDay, aMonth, aYear,aSub);
		aCustomerAccount->setClosed(aClosed);
		allAccounts[accountCounter] = *aCustomerAccount;

		accountCounter++;
	}

	accounts.close();
	return accountCounter;
}

//Starts new account and plan for a new customer
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

	//Prompts user to input their basic info
	cout << "First name: "; cin >> fName;
	cout << "Last name: "; cin >> lName;
	cout << "Birthday (dd mm yyyy): "; cin >> aDay >> aMonth >> aYear;

	cout << "Plans:\n"
		<< "\tBasic" << setfill('.') << setw(18) << "$65.00\n"
		<< "\tPremium" << setfill('.') << setw(18) << "$120.00\n"
		<< "\tPlatinum" << setfill('.') << setw(19) << "$160.00\n";
	cout << "Which plan would you like?: "; cin >> aTier;

	//creates a customer's subcription 
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

	//creates new accout with given information
	account *newAccount = new account(fName, lName, aDay, aMonth, aYear, aSub);
	allAccounts[numAccounts] = *newAccount;

	numAccounts++;

	return true;
}

account * accountFinder(account allAccounts[], const int numAccounts) //Finds an existing user or returns an error
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

bool editAccountAndPlan(account allAccounts[], const int numAccounts) //Edits the name, birthday, phone number, and plan when prompted
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
	case 1: //Edit Full name
	{
		string fName;
		string lName;
		cout << "Please edit name: "; cin >> fName >> lName;
		acct->setFullName(fName, lName);
		break;
	}
	case 2: //Edit birthday
	{
		int aDay;
		int aMonth;
		int aYear;

		cout << "Please edit birthday: "; cin >> aDay >> aMonth >> aYear;
		acct->setBirthday(aDay, aMonth, aYear);
		break;
	}
	case 3://Assigns a user a new random number
	{
		int randomNumber = rand() % 8999999 + 1000000; //randomized phone number assinged
		stringstream ss;
		ss << randomNumber;
		string aPhoneNumber = "909" + ss.str();
		cout << "Here is your new number: " << aPhoneNumber << endl;
		acct->getSub()->setPhoneNumber(aPhoneNumber);
		break;
	}
	case 4: //change accout plan
	{
		delete acct->getSub();

		subscription *aSub;
		string newTier;

		cout << "Plans:\n"
			<< "\tBasic" << setfill('.') << setw(18) << "$65.00\n"
			<< "\tPremium" << setfill('.') << setw(18) << "$120.00\n"
			<< "\tPlatinum" << setfill('.') << setw(19) << "$160.00\n";

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

	default: //return error message
		cout << "ERROR: UNRECOGNIZED SELECTION\n";
		return false;

		break;
	}

	return true;

}

void displayOptions(account allAccounts[], int &numAccounts) //Displays options that customers can choose from
{
	bool cont = true;
	while (cont)
	{
		cout << "\n\tA Phone Company\n";
		cout << setfill('-') << setw(40) << "\n";
		cout << "1. Start a new plan\n"
			<< "2. Edit account & current plan\n"
			<< "3. View available plans & add-ons\n"
			<< "4. Cancel plan\n"
			<< "5. Print all accounts\n"
			<< "6. Customize plan\n"
			<< "7. Print account bill\n"
			<< "8. Exit and save\n";

		int choice;

		cout << "\nHow can we help you today?\n"
			<< "Please make a selection (1-8) : "; cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1: //Start a new plan
			startPlan(allAccounts, numAccounts);
			break;
		case 2: //Edit account and current plan
			editAccountAndPlan(allAccounts, numAccounts);
			break;
		case 3: //View available plans and addons
			cout << endl;
			cout << "\t\t\tPlans & Bundles\n";
			cout << setfill('-') << setw(60) << "\n";
			cout << "Plans:\n"
				<< "\tBasic" << setfill('.') << setw(18) << "$65.00\n"
				<< "\tPremium" << setfill('.') << setw(18) << "$120.00\n"
				<< "\tPlatinum" << setfill('.') << setw(19) << "$160.00\n"
				<< "Add-ons:\n"
				<< "\tInsurance" << setfill('.') << setw(19) << "$5.00\n"
				<< "\tVideo Streaming Service" << setfill('.') << setw(18) << "$10.00\n"
				<< "\t24-Hr Help Services" << setfill('.') << setw(18) << "$15.00\n"
				<< "\tTV Package" << setfill('.') << setw(19) << "$20.00\n"
				<< "\tPremium Music service" << setfill('.') << setw(18) << "$30.00\n";
			cout << endl;
			break;
		case 4: //cancel plan
		{
			account *acct = accountFinder(allAccounts, numAccounts);
			acct->setClosed(true);
			cout << "\nAccount is now closed, Thank you for choosing us!\n";
			break;
		}
		case 5://print all account's and info
			for (int i = 0; i < numAccounts; i++)
			{
				allAccounts[i].print();
			}
			break;
		case 6: //customize plan 
		{
			account *acct = accountFinder(allAccounts, numAccounts);
			acct->getSub()->customizePlan();
			acct->print();
		}
			break;
		case 7: //print account bill
		{
			account *acct = accountFinder(allAccounts, numAccounts);
			cout << "Your bill is: $" << acct->getSub()->generateBill() << endl;
			break;
		}
		case 8: //Save and quit
		{
			// Clear and reopen accounts file
			fstream accountsTxt("accounts.txt", fstream::out | fstream::trunc);

			// Write accounts to file
			for (int i = 0; i < numAccounts; i++)
			{
				accountsTxt << allAccounts[i].toEntry();
				if (i < numAccounts - 1) // Don't print extra new line at the end
					accountsTxt << endl;
			}
	
			accountsTxt.close();

			cout << "Thank you for choosing A Phone Company, have a wonderful day!\n";
			cont = false;
			break;
		}

		default:
			cout << "\nERROR: PLEASE MAKE A VALID SELECTION\n";
			break;
		}
	}
}