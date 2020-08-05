/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#include "passengers.h"
using namespace std;

//add function
void Passengers::AddPassenger() {
	Passenger passenger;
	string str;
	char c;
	int num;
	float num1;
	bool status;

	//set passenger first name
	cout << "Enter Passenger First Name:" << endl;
	cin.ignore();
	getline(cin, str);
	passenger.SetPassengerFirstName(str);

	//set passenger last name
	cout << "Enter Passenger Last Name:" << endl;
	getline(cin, str);
	passenger.SetPassengerLastName(str);

	//set passenger ID
	num = 100000;
	status = true;
	while (status) {
		status = false;
		for (int i = 0; i < passengerList.size(); ++i) {
			if (passengerList[i].GetPassengerID() == num) {
				num += 1;
				status = true;
				break;
			}
		}
		if (!status) {
			passenger.SetPassengerID(num);
		}
	}

	//set passenger payment preference
	cout << "Enter Passenger Payment Preference:" << endl;
	getline(cin, str);
	passenger.SetPaymentPreference(str);

	//set if passenger handicapped
	status = true;
	while (status) {
		cout << "Enter If Passenger Is Handicapped (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			passenger.SetHandicapped(true);
			status = false;
			break;
		case 'n':
			passenger.SetHandicapped(false);
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}

	//set passenger rating
	do
	{
		status = false;
		cout << "Enter Required Rating:" << endl;
		cin >> num1;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	passenger.SetRatingRequired(num1);

	//set if passenger has pets
	status = true;
	while (status) {
		cout << "Enter If Passenger Has Pets (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			passenger.SetHasPets(true);
			status = false;
			break;
		case 'n':
			passenger.SetHasPets(false);
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}

	//add passenger to list
	passengerList.push_back(passenger);
	cout << "Passenger successfully added. Passenger ID is: " << passenger.GetPassengerID() << endl;
	cout << endl;
}

//delete function
void Passengers::DeletePassenger() {
	bool status;
	int id;
	int index;
	
	//getting ID
	do
	{
		status = false;
		cout << "Enter Passenger ID:" << endl;
		cin >> id;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	for (int i = 0; i < passengerList.size(); ++i) {
		if (passengerList[i].GetPassengerID() == id) {
			status = true;
			index = i;
		}
	}
	if (!status) {
		cout << "Passenger Not Found" << endl;
		cout << endl;
		return;
	}

	//delete passenger
	passengerList.erase(passengerList.begin() + index);
	cout << "Passenger Successfully Deleted" << endl;
	cout << endl;
}

//edit function
void Passengers::EditPassenger() {
	char option;
	bool status;
	int id;
	int index;

	//getting ID
	do
	{
		status = false;
		cout << "Enter Passenger ID:" << endl;
		cin >> id;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	for (int i = 0; i < passengerList.size(); ++i) {
		if (passengerList[i].GetPassengerID() == id) {
			status = true;
			index = i;
		}
	}
	if (!status) {
		cout << "Passenger Not Found" << endl;
		cout << endl;
		return;
	}

	//editing passenger information
	while (true) {
		cout << "Choose Desired Data Type To Change:" << endl;
		cout << "a - Passenger First Name" << endl;
		cout << "b - Passenger Last Name" << endl;
		cout << "c - Payment Preference" << endl;
		cout << "d - Handicapped" << endl;
		cout << "e - Rating Required" << endl;
		cout << "f - Has Pets" << endl;
		cout << "g - Quit" << endl;
		cout << "Enter Respective Letter:" << endl;
		cin >> option;
		cout << endl;
		switch (option) {

		//edit passenger first name
		case 'a':
		{
			string firstName;
			cout << "Enter What You Would Like To Change Passenger First Name To:" << endl;			
			cin.ignore();
			getline(cin, firstName);
			passengerList[index].SetPassengerFirstName(firstName);
			break;
		}

		//edit passenger last name
		case 'b':
		{
			string lastName;
			cout << "Enter What You Would Like To Change Passenger Last Name To:" << endl;
			cin.ignore();
			getline(cin, lastName);
			passengerList[index].SetPassengerLastName(lastName);
			break;
		}

		//edit passenger payment preference
		case 'c':
		{
			string paymentPreference;
			cout << "Enter What You Would Like To Change Passenger Payment Preference To:" << endl;
			cin.ignore();
			getline(cin, paymentPreference);
			passengerList[index].SetPaymentPreference(paymentPreference);
			break;
		}

		//edit if passenger handicapped
		case 'd':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Would Like To Change If The Passenger Is Handicapped To (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					passengerList[index].SetHandicapped(true);
					test = false;
					break;
				case 'n':
					passengerList[index].SetHandicapped(false);
					test = false;
					break;
				default:
					cout << "Error, Invalid Entry.\n\n";
					break;
				}
			}
			break;
		}

		//edit passenger required rating
		case 'e':
		{
			float ratingRequired;
			bool error;
			do
			{
				error = false;
				cout << "Enter What You Would Like To Change Passenger Required Rating To:" << endl;
				cin >> ratingRequired;
				if (cin.fail())
				{
					error = true;
					cout << "Error, Invalid Entry.\n\n";
				}
				cin.clear();
				cin.ignore(1000, '\n');
			} while (error);
			passengerList[index].SetRatingRequired(ratingRequired);
			break;
		}

		//edit if passenger has pets
		case 'f':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Would Like To Change If The Passenger Has Pets To (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					passengerList[index].SetHasPets(true);
					test = false;
					break;
				case 'n':
					passengerList[index].SetHasPets(false);
					test = false;
					break;
				default:
					cout << "Error, Invalid Entry.\n\n";
					break;
				}
			}
			break;
		}

		//quit
		case 'g':
			return;

		//error in input
		default:
			cout << "Option Not Found. Try Again" << endl;
			break;
		}
		cout << endl;
	}
}

int Passengers::FindPassenger(int id) {
	for (int i = 0; i < passengerList.size(); ++i) {
		if (passengerList[i].GetPassengerID() == id) {
			return i;
		}
	}
}

//print specific passenger function
void Passengers::PrintPassenger() {
	bool status;
	int id;
	int index;

	//getting ID
	do
	{
		status = false;
		cout << "Enter Passenger ID:" << endl;
		cin >> id;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	for (int i = 0; i < passengerList.size(); ++i) {
		if (passengerList[i].GetPassengerID() == id) {
			status = true;
			index = i;
		}
	}
	if (!status) {
		cout << "Passenger Not Found" << endl;
		cout << endl;
		return;
	}

	//printing passenger information
	cout << endl;
	cout << "PASSENGER " << passengerList[index].GetPassengerID() << " INFORMATION" << endl;
	cout << "ID: " << passengerList[index].GetPassengerID() << endl;
	cout << "First Name: " << passengerList[index].GetPassengerFirstName() << endl;
	cout << "Last Name: " << passengerList[index].GetPassengerLastName() << endl;
	cout << "Payment Preference: " << passengerList[index].GetPaymentPreference() << endl;
	cout << "Handicapped: " << passengerList[index].GetHandicapped() << endl;
	cout << "Rating Required: " << passengerList[index].GetRatingRequired() << endl;
	cout << "Has Pets: " << passengerList[index].GetHasPets() << endl;
	cout << endl;
}

//print all passengers function
void Passengers::PrintAllPassengers() {

	if (passengerList.size() == 0) {
		cout << "No Passengers Found" << endl;
		cout << endl;
	}

	for (int i = 0; i < passengerList.size(); i++) {

		//printing driver information
		cout << "PASSENGER " << passengerList[i].GetPassengerID() << " INFORMATION" << endl;
		cout << "ID: " << passengerList[i].GetPassengerID() << endl;
		cout << "First Name: " << passengerList[i].GetPassengerFirstName() << endl;
		cout << "Last Name: " << passengerList[i].GetPassengerLastName() << endl;
		cout << "Payment Preference: " << passengerList[i].GetPaymentPreference() << endl;
		cout << "Handicapped: " << passengerList[i].GetHandicapped() << endl;
		cout << "Rating Required: " << passengerList[i].GetRatingRequired() << endl;
		cout << "Has Pets: " << passengerList[i].GetHasPets() << endl;
		cout << endl;
	}
}

//store data function
void Passengers::StoreData() {
	ofstream outFS;
	outFS.open("passengersdata.txt");

	outFS << passengerList.size() << endl;
	for (int i = 0; i < passengerList.size(); ++i) {
		outFS << passengerList[i].GetPassengerID() << endl;
		outFS << passengerList[i].GetPassengerFirstName() << endl;
		outFS << passengerList[i].GetPassengerLastName() << endl;
		outFS << passengerList[i].GetPaymentPreference() << endl;
		outFS << passengerList[i].GetHandicapped() << endl;
		outFS << passengerList[i].GetRatingRequired() << endl;
		outFS << passengerList[i].GetHasPets() << endl;
		outFS << endl;
	}
	outFS.close();
}

//load data function
void Passengers::LoadData() {
	ifstream inFS;
	inFS.open("passengersdata.txt");
	if (inFS.is_open()) {
		int num;
		string s;
		char c;
		int j;
		float f;

		//input data
		inFS >> num;
		for (int i = 0; i < num; ++i) {
			Passenger passenger;

			inFS >> j;
			passenger.SetPassengerID(j);
			inFS.ignore();
			getline(inFS, s);
			passenger.SetPassengerFirstName(s);
			getline(inFS, s);
			passenger.SetPassengerLastName(s);
			getline(inFS, s);
			passenger.SetPaymentPreference(s);
			inFS >> c;
			if (c == 'y') {
				passenger.SetHandicapped(true);
			}
			else {
				passenger.SetHandicapped(false);
			}
			inFS >> f;
			passenger.SetRatingRequired(f);
			inFS >> c;
			if (c == 'y') {
				passenger.SetHasPets(true);
			}
			else {
				passenger.SetHasPets(false);
			}

			passengerList.push_back(passenger);
		}
		inFS.close();
	}
}