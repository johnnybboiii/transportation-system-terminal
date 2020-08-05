/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#include "group.h"

void Group::SetVehicleCapacity(int vehicleCapacity) {
	this->vehicleCapacity = vehicleCapacity;
}

void Group::SetCargoCapacity(int cargoCapacity) {
	this->cargoCapacity = cargoCapacity;
}

void Group::PrintInfo() {
	Driver::PrintInfo();
	cout << "Vehicle Capacity: " << vehicleCapacity << endl;
	cout << "Cargo Capacity: " << cargoCapacity << endl;
	cout << "Oversized Luggage Allowed: " << this->GetOversizedLuggage() << endl;
	cout << "Food Allowed: " << this->GetFood() << endl;
	cout << endl;
}

void Group::SetOversizedLuggage(bool oversizedLuggage) {
	this->oversizedLuggage = oversizedLuggage;
}

void Group::SetFood(bool food) {
	this->food = food;
}

void Group::AddInfo() {
	int num;
	char c;
	bool status;

	//set vehicle capacity
	do
	{
		status = false;
		cout << "Enter Vehicle Capacity (5-7 Passengers):" << endl;
		cin >> num;
		if (cin.fail() || num > 7 || num < 5)
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	vehicleCapacity = num;

	//set cargo capacity
	do
	{
		status = false;
		cout << "Enter Cargo Capacity (10 Bags Or Less):" << endl;
		cin >> num;
		if (cin.fail() || num > 10 || num < 0)
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	vehicleCapacity = num;

	//set driver oversized baggage capable
	status = true;
	while (status) {
		cout << "Enter If Driver Allows Oversized Luggage (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			oversizedLuggage = true;
			status = false;
			break;
		case 'n':
			oversizedLuggage = false;
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}

	//set driver food capable
	status = true;
	while (status) {
		cout << "Enter If Driver Allows Food (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			food = true;
			status = false;
			break;
		case 'n':
			food = false;
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}
}

void Group::StoreData(ofstream& outFS) {
	outFS << vehicleCapacity << endl;
	outFS << cargoCapacity << endl;
	outFS << oversizedLuggage << endl;
	outFS << food << endl;
}

void Group::LoadData(ifstream& inFS) {
	int n;
	bool b;

	inFS >> n;
	vehicleCapacity = n;
	inFS >> n;
	cargoCapacity = n;
	inFS >> b;
	oversizedLuggage = b;
	inFS >> b;
	food = b;
}

void Group::EditDriver() {
	char option;

	while (true) {
		cout << "Choose Desired Data Type To Change:" << endl;
		cout << "a - Driver First Name" << endl;
		cout << "b - Driver Last Name" << endl;
		cout << "c - Handicapped capable" << endl;
		cout << "d - Vehicle Type" << endl;
		cout << "e - Driver Rating" << endl;
		cout << "f - Available" << endl;
		cout << "g - Pets Allowed" << endl;
		cout << "h - Notes" << endl;
		cout << "i - Vehicle Capacity" << endl;
		cout << "j - Cargo Capacity" << endl;
		cout << "k - Oversized Luggage Allowed" << endl;
		cout << "l - Food Allowed" << endl;
		cout << "m - Quit" << endl;
		cout << "Enter Respective Letter:" << endl;
		cin >> option;
		cout << endl;
		switch (option) {

			//edit driver first name
		case 'a':
		{
			string firstName;
			cout << "Enter What You Would Like To Change Driver First Name To:" << endl;
			cin.ignore();
			getline(cin, firstName);
			this->driverFirstName = firstName;
			break;
		}

		//edit driver last name
		case 'b':
		{
			string lastName;
			cout << "Enter What You Would Like To Change Driver Last Name To:" << endl;
			cin.ignore();
			getline(cin, lastName);
			this->driverLastName = lastName;
			break;
		}

		//edit if driver handicapped capable
		case 'c':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Woud Like To Change If Driver Can Drive Handicapped To (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					this->handicapped = true;
					test = false;
					break;
				case 'n':
					this->handicapped = false;
					test = false;
					break;
				default:
					cout << "Error, Invalid Entry.\n\n";
					break;
				}
			}
			break;
		}

		//edit driver vehicle
		case 'd':
		{
			string vehicleType;
			cout << "What You Would Like To Change Driver Vehicle Type To:" << endl;
			cin.ignore();
			getline(cin, vehicleType);
			this->vehicleType = vehicleType;
			break;
		}

		//edit driver rating
		case 'e':
		{
			float driverRating;
			bool error;
			do
			{
				error = false;
				cout << "Enter What You Would Like To Change Driver Rating To:" << endl;
				cin >> driverRating;
				if (cin.fail())
				{
					error = true;
					cout << "Error, Invalid Entry.\n\n";
				}
				cin.clear();
				cin.ignore(1000, '\n');
			} while (error);
			this->driverRating = driverRating;
			break;
		}

		//edit if driver available
		case 'f':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Would Like To Change If Driver Is Available To (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					this->available = true;
					test = false;
					break;
				case 'n':
					this->available = false;
					test = false;
					break;
				default:
					cout << "Error, Invalid Entry.\n\n";
					break;
				}
			}
			break;
		}

		//edit if driver allows pets
		case 'g':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Would Like To Change If Driver Allows Pets To (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					this->pets = true;
					test = false;
					break;
				case 'n':
					this->pets = false;
					test = false;
					break;
				default:
					cout << "Error, Invalid Entry.\n\n";
					break;
				}
			}
			break;
		}

		//edit driver notes
		case 'h':
		{
			string notes;
			cout << "Enter What You Woud Like To Change Driver Notes To:" << endl;
			cin.ignore();
			getline(cin, notes);
			this->notes = notes;
			break;
		}

		//edit vehicle capacity
		case 'i':
		{
			int vehicleCapacity;
			bool error;
			do
			{
				error = false;
				cout << "Enter What You Would Like To Change Vehicle Capacity To (5-7 Passengers):" << endl;
				cin >> vehicleCapacity;
				if (cin.fail() || vehicleCapacity > 7 || vehicleCapacity < 5)
				{
					error = true;
					cout << "Error, Invalid Entry.\n\n";
				}
				cin.clear();
				cin.ignore(1000, '\n');
			} while (error);
			this->vehicleCapacity = vehicleCapacity;
			break;
		}

		//edit vehicle capacity
		case 'j':
		{
			int cargoCapacity;
			bool error;
			do
			{
				error = false;
				cout << "Enter What You Would Like To Change Cargo Capacity To (10 Bags Or Less):" << endl;
				cin >> cargoCapacity;
				if (cin.fail() || cargoCapacity > 10 || cargoCapacity < 0)
				{
					error = true;
					cout << "Error, Invalid Entry.\n\n";
				}
				cin.clear();
				cin.ignore(1000, '\n');
			} while (error);
			this->cargoCapacity = cargoCapacity;
			break;
		}

		//edit if driver allows oversized luggage
		case 'k':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Would Like To Change If Driver Allows Oversized Luggage To (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					this->oversizedLuggage = true;
					test = false;
					break;
				case 'n':
					this->oversizedLuggage = false;
					test = false;
					break;
				default:
					cout << "Error, Invalid Entry.\n\n";
					break;
				}
			}
			break;
		}

		//edit if driver allows food
		case 'l':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Would Like To Change If Driver Allows Food (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					this->food = true;
					test = false;
					break;
				case 'n':
					this->food = false;
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
		case 'm':
			return;

			//error in input
		default:
			cout << "Option Not Found. Try Again" << endl;
			break;
		}
		cout << endl;
	}
}