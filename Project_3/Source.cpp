#include "Account.h"
#include "PlatSub.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;


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







