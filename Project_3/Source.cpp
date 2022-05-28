#include "Account.h"
#include "PlatSub.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;


/*
Some comments: A few things
1. I couldn't figure out what was wrong with the command to read from a file into a variable
2. We are going to need to save what types of streaming services the premium account users choose, and since platinum users get all of them, we don't need to know what services
Just that they are a platinum user
3. I did part of the saving into a file command, but we need to figure out how users can choose what streaming services they want first, and save that data
and any other data that we might want to put into the file
-Edwin
*/

//Just as a reminder, I made the cost for a basic plan 65 dollars. Premium is going to cost 120, and platinum is 160 
//in the view current plans option for the menu
//This was just arbitrarily decided


//Just as a reminder, I made the cost for a basic plan 65 dollars. Premium is going to cost 120, and platinum is 160 
//in the view current plans option for the menu
//This was just arbitrarily decided

const int NUMOFACCOUNTS = 512; // Make enough spaces of accounts
//I moved the const outside the main - Edwin

/*
<< "6. Customize plan\n"
<< "7. Exit and save\n"
*/
// ↑ These are the current options in the main menu that we need to make still, although I feel like option 7 is a bit redundant with its use
//since we could just have it save once out of the options, so all option 7 would do is close the options, but idk

int readCustomerInfo(account allAccounts[]);

void displayOptions(account allAccounts[], int &numAccounts);

void viewAvaliablePlans();

bool startPlan(account allAccounts[], int &numAccounts);

void closeAccount(account allAccounts[], int numAccounts);

account *accountFinder(account allAccounts[], const int numAccounts);

bool editPlan(account allAccounts[], const int numAccounts);

void SaveChanges(account allAccounts[], const int numAccounts);

void Customize_Plan(account allAccounts[], const int numAccounts); //I Think this works? Not sure tbh

void generateSubBill(account allAccounts[], const int numAccounts);




int main()
{
	account accounts[NUMOFACCOUNTS];
	long test_num;
	subscription *Test = new subscription;


	int numAccounts = readCustomerInfo(accounts);
	cout << endl << endl;
	//Below stuff was me making a test account
	Test->setDataCap(5);
	Test->setPhoneNumber(1234567890);
	Test->setTier(BASIC);
	Test->print();
	accounts[0].setInfo("Test", "Account", 5, 5, 2005, Test);

	srand(time(NULL)); //set random phone number
	displayOptions(accounts,numAccounts);
	system("pause");
	return 0;

}

int readCustomerInfo(account allAccounts[])
{

	fstream accounts("accounts.txt", ios::in);
	
	string line;
	int number_of_accounts = 0;
	int accountCounter = 0;
	while (getline(accounts, line))
	{
		++number_of_accounts;//Count how many accounts there are
	}
	
	accounts.clear();
	accounts.seekg(0); //These two lines reset the file to start reading the file from the top again
	string fName = "";
	string lName = "";
	int aDay = 200;
	int aMonth = 300;
	int aYear = 300;
	string aTier = "PLATINUM";
	long aPhoneNumber = 2;
	subscription *aSub;
	for (int account_counter = 0; account_counter < number_of_accounts; account_counter++)
	{

		getline(accounts, line);
		cout << line << endl; //These are the test lines to show that each portion of the file can actually be read
		//accounts >> fName >> lName >> aDay >> aMonth >> aYear >> aTier >> aPhoneNumber; //<----For some reason this line breaks the code and keeps reading the same line for each account (:()
		if (aTier == "BASIC")
		{
			aSub = new basicSubscription();
			cout << "I am here Base\n";
		}
		else if (aTier == "PREMIUM")
		{
			aSub = new premiumSubscription();
			cout << "I am here Prem\n";
		}
		else if (aTier == "PLATINUM")
		{
			aSub = new platinumSubscription();
			cout << "I am here Plat\n";
		}
		else
		{
			cout << "This is error\n";
			cout << "This is the current tier: " << aTier;
			cout << "ERROR: NO PLAN FOUND\n";
			return -1;
		}
		
		cout << "This is the fname: " << fName << endl;
		cout << "This is the lname: " << lName << endl;
		cout << "This is the bday: " << aDay << endl;
		cout << "This is the bmonth: " << aMonth << endl;
		cout << "This is the bYear: " << aYear << endl;
		cout << "This is the current tier: " << aTier << endl;
		cout << "This is the current phone number: " << aPhoneNumber << endl;
		
		/*
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

			cout << "This is the fname: " << fName << endl;
			cout << "This is the lname: " << lName << endl;
			cout << "This is the bday: " << aDay << endl;
			cout << "This is the bmonth: " << aMonth << endl;
			cout << "This is the bYear: " << aYear << endl;
			cout << "This is the current tier: " << aTier << endl;
			cout << "This is the current phone number: " << aPhoneNumber << endl;

			if (aTier == "BASIC")
			{
				aSub = new basicSubscription();
				cout << "I am here Base\n";
			}
			else if (aTier == "PREMIUM")
			{
				aSub = new premiumSubscription();
				cout << "I am here Prem\n";
			}
			else if(aTier == "PLATINUM")
			{
				aSub = new platinumSubscription();
				cout << "I am here Plat\n";
			}
			else
			{
				cout << "This is error\n";
				cout << "This is the current tier: " << aTier;
				cout << "ERROR: NO PLAN FOUND\n";
				return -1;
			}
			*/

			//create account from read data
		aSub->setPhoneNumber(aPhoneNumber);
		account aCustomerAccount(fName, lName, aDay, aMonth, aYear, aSub);

		allAccounts[account_counter] = aCustomerAccount;
	}
	//}
	cout << "I have run this many times: " << accountCounter << endl;
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

void closeAccount(account allAccounts[], int numAccounts)
{
	int WhichAccount;
	cout << "Which account would you like to close? 1 - " << numAccounts << endl;
	cin >> WhichAccount;
	WhichAccount -= 1; //Subtract one, since account 1 is technically account 0 in the array
	bool test = allAccounts[WhichAccount].getClosed();
	if (test = true)
	{
		cout << "ERROR, ACCOUNT ALREADY CLOSED\n";
	}
	else
	{
		allAccounts[WhichAccount].setClosed();
	}
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

void SaveChanges(account allAccounts[], const int numAccounts)
{
	//This code will save all changes to the file, in stasis rn to make sure nothing in the file is changed, yet
	/*
	ofstream AccountsFile;
	AccountsFile.open("Accounts.txt");
	{
		if (AccountsFile.is_open()) //Check to make sure the file is open
		{
			for (int x = 1; x <= numAccounts; x++)
			{
				AccountsFile << allAccounts[x].getFName() << " " << allAccounts[x].getLName() << " " << allAccounts[x].getBday()
					<< " " << allAccounts[x].getBmonth() << " " << allAccounts[x].getByear() << " " << allAccounts[x].getSub() 
					<< " " << allAccounts[x].getPhoneNumber();
			}
		}
	}
	*/
}

void Customize_Plan(account allAccounts[], const int numAccounts)
{
	int WhichAccount;
	cout << "Which account would you like to change? 1 - " << numAccounts << endl;
	cin >> WhichAccount;
	WhichAccount -= 1; //Subtract one. because account 1 is technically account 0 in the array
	cout << "This is the current info in the account: \n";
	allAccounts[WhichAccount].printInfo();
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
		<< "Please make a selection (1-7) : "; cin >> choice;

	switch (choice)
	{
	case 1:
		startPlan(allAccounts, numAccounts);
		break;
	case 2: 
		editPlan(allAccounts, numAccounts);
		break;
	case 3: 
		viewAvaliablePlans();
		break;
	case 4:
		closeAccount(allAccounts, numAccounts);
		break;
	case 5: 
		
		break;
	case 6: 
		Customize_Plan(allAccounts, numAccounts);
		break;
	case 7: 
		cout << "Thank you for choosing La Verne Phone Company, have a wonderful day!\n";
		break;
	}

}

void viewAvaliablePlans()
{
	cout << "Currently we have these plans open: \n"
		<< "Basic: This plan comes with 4 Gigs of Data only, and costs $60\n"
		<< "Premium: This plan comes with 6 Gigs of Data and two streaming services of your choosing, and costs $120\n"
		<< "Platinim: This plan comes with 8 Gigs of Data and has all of the streaming services, and costs $160\n";
}







