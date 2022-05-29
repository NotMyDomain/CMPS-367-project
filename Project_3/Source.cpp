#include "Account.h"
#include "PlatSub.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

const int numOfAccounts = 512;

int readCustomerInfo(account allAccounts[]);
void displayOptions(account allAccounts[], int &numAccounts);
bool startPlan(account allAccounts[], int &numAccounts);
account *accountFinder(account allAccounts[], const int numAccounts);
bool editAccountAndPlan(account allAccounts[], const int numAccounts);
account *accountcopier(account allAccounts[], const int numAccounts);

int main()
{
	srand(time(NULL)); //set random phone number
	// Make enough spaces of accounts
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

		//create account from read data
		aSub->setPhoneNumber(aPhoneNumber);
		account *aCustomerAccount = new account(fName, lName, aDay, aMonth, aYear,aSub);
		aCustomerAccount->setClosed(aClosed);
		allAccounts[accountCounter] = *aCustomerAccount;

		accountCounter++;
	}
	accounts.close();
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

	default:
		cout << "ERROR: UNRECOGNIZED SELECTION\n";
		return false;

		break;
	}

	return true;

}

void displayOptions(account allAccounts[], int &numAccounts)
{
	bool cont = true;
	while (cont)
	{
		cout << "\n\tA Phone Company\n";
		cout << setfill('-') << setw(40) << "\n";
		cout << "1. Start a new plan\n"
			<< "2. Edit account & current plan\n"
			<< "3. View Available plans & add-ons\n"
			<< "4. Cancel plan\n"
			<< "5. Print All Accounts\n"
			<< "6. Customize plan\n"
			<< "7. Print Account Bill\n"
			<< "8. Exit and save\n";

		int choice;

		cout << "How can we help you today?\n"
			<< "Please make a selection (1-8) : "; cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			startPlan(allAccounts, numAccounts);
			break;
		case 2:
			editAccountAndPlan(allAccounts, numAccounts);
			break;
		case 3: 
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
		case 4:
		{
			account *acct = accountFinder(allAccounts, numAccounts);
			acct->setClosed(true);
			cout << "\nAccount is now closed, Thank you for choosing us!\n";
			break;
		}
		case 5:
			for (int i = 0; i < numAccounts; i++)
			{
				allAccounts[i].print();
			}
			break;
		case 6: 
		{
			account *acct = accountFinder(allAccounts, numAccounts);
			acct->getSub()->customizePlan();
			acct->print();
		}
			break;
		case 7: 
		{
			account *acct = accountFinder(allAccounts, numAccounts);
			cout << "Your bill is: $" << acct->getSub()->generateBill() << endl;
			break;
		}
		case 8:
		{
			ofstream accountsTxt("accounts.txt");
			int test = 0;
			// Write accounts to file
			for (int i = 0; i < numAccounts; i++)
			{
				account *acct = accountcopier(allAccounts, i);
				string tier;
				string line;

				//thier tier corresponds to what will be read to the file
				if (acct->getSub()->getTier() == BASIC) tier = "BASIC";
				else if (acct->getSub()->getTier() == PREMIUM) tier = "PREMIUM";
				else if (acct->getSub()->getTier() == PLATINUM) tier = "PLATINUM";

				//Put the information back into the file in the correct format

				accountsTxt << allAccounts[i].getFName() << " " << allAccounts[i].getLName() << " " << allAccounts[i].getBday() << " " << allAccounts[i].getBmonth() << " " << allAccounts[i].getByear() << " " << tier << " " << acct->getSub()->getPhoneNumber() << " " << allAccounts[i].getClosed();
				if (i != numAccounts - 1)
				{
					accountsTxt << endl;
				}
				cout << "I am here\n";
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
account *accountcopier(account allAccounts[], const int test_counter)
{
	return &(allAccounts[test_counter]);
}