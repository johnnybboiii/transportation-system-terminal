/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#include "drivers.h"
#include "economy.h"
#include "group.h"
#include "basic.h"
#include "luxury.h"
using namespace std;

//add function
void Drivers::AddDriver() {
	Driver* driver;
	string str;
	char c;
	int num;
	float num1;
	bool status;

	//set driver type
	status = true;
	while (status) {
		cout << "Enter Letter For Respective Driver Type (E = Economy, B = Basic, G = Group, L = Luxury): " << endl;
		cin >> c;
		switch (c) {
		case 'E':
			driver = new Economy();
			driver->SetDriverType("Economy");
			status = false;
			break;
		case 'B':
			driver = new Basic();
			driver->SetDriverType("Basic");
			status = false;
			break;
		case 'G':
			driver = new Group();
			driver->SetDriverType("Group");
			status = false;
			break;
		case 'L':
			driver = new Luxury();
			driver->SetDriverType("Luxury");
			status = false;
			break;
		default:
			cout << "Option Not Found. Try Again" << endl;
			cout << endl;
		}
	}

	//set driver first name
	cout << "Enter Driver First Name:" << endl;
	cin.ignore();
	getline(cin, str);
	driver->SetDriverFirstName(str);

	//set driver last name
	cout << "Enter Driver Last Name:" << endl;
	getline(cin, str);
	driver->SetDriverLastName(str);

	//set driver ID
	num = 100000;
	status = true;
	while (status) {
		status = false;
		for (int i = 0; i < driverList.size(); ++i) {
			if (driverList[i]->GetDriverID() == num) {
				num += 1;
				status = true;
				break;
			}
		}
		if (!status) {
			driver->SetDriverID(num);
		}
	}

	//set driver handicapped capable
	status = true;
	while (status) {
		cout << "Enter If Driver Can Drive Handicapped (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			driver->SetHandicapped(true);
			status = false;
			break;
		case 'n':
			driver->SetHandicapped(false);
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}

	//set driver vehicle type
	cout << "Enter Driver Vehicle Type:" << endl;
	cin.ignore();
	getline(cin, str);
	driver->SetVehicleType(str);

	//set driver rating
	do
	{
		status = false;
		cout << "Enter Driver Rating:" << endl;
		cin >> num1;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	driver->SetDriverRating(num1);

	//set driver available
	status = true;
	while (status) {
		cout << "Enter If Driver Is Available (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			driver->SetAvailable(true);
			status = false;
			break;
		case 'n':
			driver->SetAvailable(false);
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}

	//set pets allowed
	status = true;
	while (status) {
		cout << "Enter If Driver Allows Pets (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			driver->SetPets(true);
			status = false;
			break;
		case 'n':
			driver->SetPets(false);
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}

	//set driver notes
	cout << "Enter Driver Notes:" << endl;
	cin.ignore();
	getline(cin, str);
	driver->SetNotes(str);

	//add additional information
	driver->AddInfo();

	//add to list
	driverList.push_back(driver);
	cout << "Driver Successfully Added. Driver ID is: " << driver->GetDriverID() << endl;
	cout << endl;
}

//delete function
void Drivers::DeleteDriver() {
	int index;
	int id;
	bool status;

	//getting ID
	do
	{
		status = false;
		cout << "Enter Driver ID:" << endl;
		cin >> id;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	for (int i = 0; i < driverList.size(); ++i) {
		if (driverList[i]->GetDriverID() == id) {
			status = true;
			index = i;
		}
	}
	if (!status) {
		cout << "Driver Not Found" << endl;
		cout << endl;
		return;
	}

	//deleting driver
	delete driverList[index];
	driverList.erase(driverList.begin() + index);
	cout << "Driver Successfully Deleted" << endl;
	cout << endl;
}

//edit function
void Drivers::EditDriver() {
	char option;
	int index;
	int id;
	bool status;

	//getting ID
	do
	{
		status = false;
		cout << "Enter Driver ID:" << endl;
		cin >> id;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	for (int i = 0; i < driverList.size(); ++i) {
		if (driverList[i]->GetDriverID() == id) {
			status = true;
			index = i;
		}
	}
	if (!status) {
		cout << "Driver Not Found" << endl;
		cout << endl;
		return;
	}

	//editing driver information
	driverList[index]->EditDriver();
}

int Drivers::FindDriver(int index, char pets, char handicapped, float ratingRequired, int partySize) {
	if (!(driverList[index]->GetAvailable() == 'y')) {
		return 0;
	}
	if (pets == 'y') {
		if (!(driverList[index]->GetPets() == 'y')) {
			return 0;
		}
	}
	if (handicapped == 'y') {
		if (!(driverList[index]->GetHandicapped() == 'y')) {
			return 0;
		}
	}
	if (!(driverList[index]->GetDriverRating() >= ratingRequired)) {
		return 0;
	}
	if (!(driverList[index]->GetVehicleCapacity() >= partySize)) {
		return 0;
	}
	return 1;
}

//print specific driver function
void Drivers::PrintDriver() {
	int index;
	int id;
	bool status;

	//getting ID
	do
	{
		status = false;
		cout << "Enter Driver ID:" << endl;
		cin >> id;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	for (int i = 0; i < driverList.size(); ++i) {
		if (driverList[i]->GetDriverID() == id) {
			status = true;
			index = i;
		}
	}
	if (!status) {
		cout << "Driver Not Found" << endl;
		cout << endl;
		return;
	}

	//printing driver information
	cout << endl;
	driverList[index]->PrintInfo();
}

//print all drivers function
void Drivers::PrintAllDrivers() {
	if (driverList.size() == 0) {
		cout << "No Drivers Found" << endl;
		cout << endl;
	}

	for (int i = 0; i < driverList.size(); i++) {

		//printing driver information
		driverList[i]->PrintInfo();
	}
}

//store data function
void Drivers::StoreData() {
	ofstream outFS;
	outFS.open("driversdata.txt");

	outFS << driverList.size() << endl;
	for (int i = 0; i < driverList.size(); ++i) {
		outFS << driverList[i]->GetDriverType() << endl;
		outFS << driverList[i]->GetDriverID() << endl;
		outFS << driverList[i]->GetDriverFirstName() << endl;
		outFS << driverList[i]->GetDriverLastName() << endl;
		outFS << driverList[i]->GetVehicleCapacity() << endl;
		outFS << driverList[i]->GetHandicapped() << endl;
		outFS << driverList[i]->GetVehicleType() << endl;
		outFS << driverList[i]->GetDriverRating() << endl;
		outFS << driverList[i]->GetAvailable() << endl;
		outFS << driverList[i]->GetPets() << endl;
		outFS << driverList[i]->GetNotes() << endl;
		driverList[i]->StoreData(outFS);
		outFS << endl;
	}
	outFS.close();
}

//load data function
void Drivers::LoadData() {
	ifstream inFS;
	inFS.open("driversdata.txt");
	if (inFS.is_open()) {
		int num;
		string s;
		int j = 10;
		float f;
		char trash;
		char c;


		//input data
		inFS >> num;
		for (int i = 0; i < num; ++i) {
			Driver* driver;
			inFS >> s;

			if (s == "Luxury") {
				driver = new Luxury();
			}
			else if (s == "Basic") {
				driver = new Basic();
			}
			else if (s == "Economy") {
				driver = new Economy();
			}
			else {
				driver = new Group();
			}
			
			driver->SetDriverType(s);
			inFS >> j;
			driver->SetDriverID(j);
			inFS.get(trash);
			getline(inFS, s);
			driver->SetDriverFirstName(s);
			getline(inFS, s);
			driver->SetDriverLastName(s);
			inFS >> j;
			driver->SetVehicleCapacity(j);
			inFS >> c;
			if (c == 'y') {
				driver->SetHandicapped(true);
			}
			else {
				driver->SetHandicapped(false);
			}
			inFS.get(trash);
			getline(inFS, s);
			driver->SetVehicleType(s);
			inFS >> f;
			driver->SetDriverRating(f);
			inFS >> c;
			if (c == 'y') {
				driver->SetAvailable(true);
			}
			else {
				driver->SetAvailable(false);
			}
			inFS >> c;
			if (c == 'y') {
				driver->SetPets(true);
			}
			else {
				driver->SetPets(false);
			}
			inFS.get(trash);
			getline(inFS, s);
			driver->SetNotes(s);
			driver->LoadData(inFS);

			driverList.push_back(driver);
		}
		inFS.close();
	}
}