/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#include "economy.h"

void Economy::SetVehicleCapacity(int vehicleCapacity) {
	this->vehicleCapacity = vehicleCapacity;
}

void Economy::SetCargoCapacity(int cargoCapacity) {
	this->cargoCapacity = cargoCapacity;
}

void Economy::PrintInfo() {
	Driver::PrintInfo();
	cout << "Vehicle Capacity: " << vehicleCapacity << endl;
	cout << "Cargo Capacity: " << cargoCapacity << endl;
	cout << "Music Allowed: " << this->GetMusic() << endl;
	cout << "Air Conditioning Available: " << this->GetAC() << endl;
	cout << endl;
}

void Economy::SetMusic(bool music) {
	this->music = music;
}

void Economy::SetAC(bool AC) {
	this->AC = AC;
}

void Economy::AddInfo() {
	int num;
	char c;
	bool status;

	//set vehicle capacity
	do
	{
		status = false;
		cout << "Enter Vehicle Capacity (2 Or Less Passengers):" << endl;
		cin >> num;
		if (cin.fail() || num > 2 || num < 1)
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
		cout << "Enter Cargo Capacity (1 Bag Or less):" << endl;
		cin >> num;
		if (cin.fail() || num > 1 || num < 0)
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	vehicleCapacity = num;

	//set driver music capable
	status = true;
	while (status) {
		cout << "Enter If Driver Allows Music (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			music = true;
			status = false;
			break;
		case 'n':
			music = false;
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}

	//set driver AC capable
	status = true;
	while (status) {
		cout << "Enter If Driver Has Air Conditioning (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			AC = true;
			status = false;
			break;
		case 'n':
			AC = false;
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}
}

void Economy::StoreData(ofstream& outFS) {
	outFS << vehicleCapacity << endl;
	outFS << cargoCapacity << endl;
	outFS << music << endl;
	outFS << AC << endl;
}

void Economy::LoadData(ifstream& inFS) {
	int n;
	bool b;

	inFS >> n;
	vehicleCapacity = n;
	inFS >> n;
	cargoCapacity = n;
	inFS >> b;
	music = b;
	inFS >> b;
	AC = b;
}

void Economy::EditDriver() {
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
		cout << "k - Air Conditioning Available" << endl;
		cout << "l - Music Allowed" << endl;
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
				cout << "Enter What You Would Like To Change Vehicle Capacity To (2 Or Less Passengers):" << endl;
				cin >> vehicleCapacity;
				if (cin.fail() || vehicleCapacity > 2 || vehicleCapacity < 1)
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
				cout << "Enter What You Would Like To Change Cargo Capacity To (1 Bags Or Less):" << endl;
				cin >> cargoCapacity;
				if (cin.fail() || cargoCapacity > 1 || cargoCapacity < 0)
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

		//edit if driver has AC
		case 'k':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Would Like To Change If Driver Has Air Conditioning To (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					this->AC = true;
					test = false;
					break;
				case 'n':
					this->AC = false;
					test = false;
					break;
				default:
					cout << "Error, Invalid Entry.\n\n";
					break;
				}
			}
			break;
		}

		//edit if driver alllows music
		case 'l':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Would Like To Change If Driver Allows Music To (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					this->music = true;
					test = false;
					break;
				case 'n':
					this->music = false;
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