/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#include "luxury.h"

void Luxury::SetVehicleCapacity(int vehicleCapacity) {
	this->vehicleCapacity = vehicleCapacity;
}

void Luxury::SetCargoCapacity(int cargoCapacity) {
	this->cargoCapacity = cargoCapacity;
}

void Luxury::PrintInfo() {
	Driver::PrintInfo();
	cout << "Vehicle Capacity: " << vehicleCapacity << endl;
	cout << "Cargo Capacity: " << cargoCapacity << endl;
	cout << "Oversized Luggage Allowed: " << this->GetOversizedLuggage() << endl;
	cout << "Amenities Available: " << amenities << endl;
	cout << endl;
}

void Luxury::SetOversizedLuggage(bool oversizedLuggage) {
	this->oversizedLuggage = oversizedLuggage;
}

void Luxury::SetAmenities(string amenities) {
	this->amenities = amenities;
}

void Luxury::AddInfo() {
	int num;
	string str;
	char c;
	bool status;

	//set vehicle capacity
	do
	{
		status = false;
		cout << "Enter Vehicle Capacity:" << endl;
		cin >> num;
		if (cin.fail() || num < 1)
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
		cout << "Enter Cargo Capacity:" << endl;
		cin >> num;
		if (cin.fail() || num < 0)
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	vehicleCapacity = num;

	//set driver over sized baggage capable
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

	//set driver amenities
	cout << "Enter Driver Amenities:" << endl;
	cin.ignore();
	getline(cin, str);
	amenities = str;
}

void Luxury::StoreData(ofstream& outFS) {
	outFS << vehicleCapacity << endl;
	outFS << cargoCapacity << endl;
	outFS << oversizedLuggage << endl;
	outFS << amenities << endl;
}

void Luxury::LoadData(ifstream& inFS) {
	int n;
	bool b;
	string s;

	inFS >> n;
	vehicleCapacity = n;
	inFS >> n;
	cargoCapacity = n;
	inFS >> b;
	oversizedLuggage = b;
	inFS.ignore();
	getline(inFS, s);
	amenities = s;

}

void Luxury::EditDriver() {
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
		cout << "k - Amenities Available" << endl;
		cout << "l - Oversized Luggage Allowed" << endl;
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
				cout << "Enter What You Would Like To Change Vehicle Capacity To:" << endl;
				cin >> vehicleCapacity;
				if (cin.fail() || vehicleCapacity < 1)
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
				cout << "Enter What You Would Like To Change Cargo Capacity To:" << endl;
				cin >> cargoCapacity;
				if (cin.fail() || cargoCapacity < 0)
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

		//edit amenities available
		case 'k':
		{
			string amenities;
			cout << "Enter What You Woud Like To Change Amenities Allowed To:" << endl;
			cin.ignore();
			getline(cin, amenities);
			this->amenities = amenities;
			break;
		}

		//edit if driver allows oversized luggage
		case 'l':
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