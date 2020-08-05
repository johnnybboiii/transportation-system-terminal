/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#include "rides.h"
using namespace std;
Rides::Rides(Drivers* d, Passengers* p) {
	this->passengers = p;
	this->drivers = d;
}

//add function
void Rides::AddRide() {
	Ride ride;
	vector <Passenger> passengerList; //to access passenger class
	passengerList = (passengers->GetVector());
	vector <Driver*> driverList; //to access driver class
	driverList = (drivers->GetVector());

	string str;
	char c;
	bool status;
	int num;
	float num1;

	//set ride ID
	num = 10000000;
	status = true;
	while (status) {
		status = false;
		for (int i = 0; i < rideList.size(); ++i) {
			if (rideList[i].GetRideID() == num) {
				num += 1;
				status = true;
				break;
			}
		}
		if (!status) {
			ride.SetRideID(num);
		}
	}
	
	//set passenger ID
	do {
		status = false;
		cout << "Enter Passenger ID Of Passenger Ordering Ride:" << endl;
		cin >> num;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		for (int i = 0; i < passengerList.size(); ++i) {
			if (passengerList[i].GetPassengerID() == num) {
				ride.SetPassengerID(passengerList[i].GetPassengerID());
				status = true;
				break;
			}
		}
		if (!status) {
			cout << "ID of Passenger Not Found. Try Again" << endl;
			cout << endl;
			status = true;
		}
		else {
			break;
		}
	} while (status);

	//set ride pickup location
	cout << "Enter Ride Pickup Location:" << endl;
	cin.ignore();
	getline(cin, str);
	ride.SetPickupLocation(str);
	
	//set ride pickup time
	do
	{
		status = false;
		cout << "Enter How Many Minutes Until Ride Pickup:" << endl;
		cin >> num;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	num *= 60;
	time_t pickup = time(0);
	pickup += num;
	ride.SetPickupTime(pickup);

	//set ride dropoff location
	cout << "Enter Ride Dropoff Location:" << endl;
	cin.ignore();
	getline(cin, str);
	ride.SetDropoffLocation(str);
	
	//set ride dropoff time
	do
	{
		status = false;
		cout << "Enter How Many Minutes Ride Will Take:" << endl;
		cin >> num;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	num *= 60;
	time_t dropoff = ride.GetPickupTimeSeconds();
	dropoff += num;
	ride.SetDropoffTime(dropoff);

	//set ride party size
	do
	{
		status = false;
		cout << "Enter Party Size of Ride:" << endl;
		cin >> num;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	ride.SetPartySize(num);

	//set if ride has pets
	status = true;
	while (status) {
		cout << "Enter If There Are Pets On The Ride (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			ride.SetPets(true);
			status = false;
			break;
		case 'n':
			ride.SetPets(false);
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}

	//set if handicapped capable
	status = true;
	while (status) {
		cout << "Enter If Ride Is Handicapped Capable (y or n):" << endl;
		cin >> c;
		switch (c) {
		case 'y':
			ride.SetHandicapped(true);
			status = false;
			break;
		case 'n':
			ride.SetHandicapped(false);
			status = false;
			break;
		default:
			cout << "Error, Invalid Entry.\n\n";
			break;
		}
	}

	//set driver ID
	bool found = false;
	char pets = ride.GetPets();
	char handicapped = ride.GetHandicapped();

	float ratingRequired = passengerList[passengers->FindPassenger(ride.GetPassengerID())].GetRatingRequired();

	int partySize = ride.GetPartySize();

	for (int i = 0; i < driverList.size(); ++i) {
		status = true;
		num = driverList[i]->GetDriverID();
		for (int h = 0; h < rideList.size(); ++h) {
			if (rideList[h].GetDriverID() == num) {
				if (ride.GetPickupTimeSeconds() <= rideList[h].GetDropoffTimeSeconds()){
					if (ride.GetDropoffTimeSeconds() >= rideList[h].GetPickupTimeSeconds()) {
						status = false;
						break;
					}
				}
			}
			
		}
		if (status) {
			num = drivers->FindDriver(i,pets, handicapped, ratingRequired, partySize);
			if (num == 1) {
				ride.SetDriverID(driverList[i]->GetDriverID());
				found = true;
				break;
			}
		}
	}
	if (!found) {
		cout << "Driver Not Found For Given Conditions. Deleting Ride" << endl;
		cout << endl;
		return;
	}
	
	//set status
	ride.SetStatus("Active");

	//set rating by customer
	do
	{
		status = false;
		cout << "Enter Customer Rating Of Ride:" << endl;
		cin >> num;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	ride.SetRating(num);

	//add ride to list
	rideList.push_back(ride);
	cout << "Ride Successfully Added. Ride ID is: " << ride.GetRideID() << endl;
	cout << endl;
}

//delete function
void Rides::CancelRide() {
	bool status;
	int id;
	int index;

	//getting ID
	do
	{
		status = false;
		cout << "Enter Ride ID:" << endl;
		cin >> id;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	for (int i = 0; i < rideList.size(); ++i) {
		if (rideList[i].GetRideID() == id) {
			status = true;
			index = i;
		}
	}
	if (!status) {
		cout << "Ride Not Found" << endl;
		cout << endl;
		return;
	}
	else {
		cout << "Ride Successfully Cancelled" << endl;
		cout << endl;
	}

	//cancel ride
	rideList[index].SetStatus("Cancelled");
	cout << endl;
}

//edit function
void Rides::EditRide() {
	char option;
	bool status;
	int id;
	int index;
	time_t t = time(0);

	//getting ID
	do
	{
		status = false;
		cout << "Enter Ride ID:" << endl;
		cin >> id;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	for (int i = 0; i < rideList.size(); ++i) {
		if (rideList[i].GetRideID() == id) {
			if (rideList[i].GetPickupTimeSeconds() <= t) {
				cout << "Ride Has Started Already Or Has Finished. Cannot Edit Ride" << endl;
				cout << endl;
				return;
			}
			else {
				status = true;
				index = i;
			}
		}
	}
	if (!status) {
		cout << "Ride Not Found" << endl;
		cout << endl;
		return;
	}


	//edit ride information
	while (true) {
		cout << "Choose Desired Data Type To Change:" << endl;
		cout << "a - Pickup Location" << endl;
		cout << "b - Minutes Until Pickup" << endl;
		cout << "c - Dropoff Location" << endl;
		cout << "d - Duration Of Ride" << endl;
		cout << "e - Size Of Party" << endl;
		cout << "f - Pets" << endl;
		cout << "g - Handicapped Capable" << endl;
		cout << "h - Rating By Customer" << endl;
		cout << "i - Quit" << endl;
		cout << "Enter Respective Letter:" << endl;
		cin >> option;
		cout << endl;
		switch (option) {

		//edit pickup location
		case 'a':
		{
			string pickupLocation;
			cout << "Enter What You Would Like To Change Pickup Location To:" << endl;
			cin.ignore();
			getline(cin, pickupLocation);
			rideList[index].SetPickupLocation(pickupLocation);
			break;
		}

		//edit pickup time
		case 'b':
		{
			float pickupTime;
			bool error;
			int num;
			do
			{
				error = false;
				cout << "Enter What You Would Like To Change Minutes Until Pickup To:" << endl;
				cin >> pickupTime;
				if (cin.fail())
				{
					error = true;
					cout << "Error, Invalid Entry.\n\n";
				}
				cin.clear();
				cin.ignore(1000, '\n');
			} while (error);
			pickupTime *= 60;
			num = rideList[index].GetDropoffTimeSeconds() - rideList[index].GetPickupTimeSeconds();
			pickupTime += time(0);
			rideList[index].SetPickupTime(pickupTime);
			num += pickupTime;
			rideList[index].SetDropoffTime(num);
			break;
		}

		//edit dropoff location
		case 'c':
		{
			string dropoffLocation;
			cout << "Enter What You Would Like To Change Dropoff Location To:" << endl;
			cin.ignore();
			getline(cin, dropoffLocation);
			rideList[index].SetDropoffLocation(dropoffLocation);
			break;
		}

		//edit dropoff time
		case 'd':
		{
			int dropoffTime;
			bool error;
			do
			{
				error = false;
				cout << "Enter What You Would Like To Change Duration (In Minutes) Of Ride To:" << endl;
				cin >> dropoffTime;
				if (cin.fail())
				{
					error = true;
					cout << "Error, Invalid Entry\n\n";
				}
				cin.clear();
				cin.ignore(1000, '\n');
			} while (error);
			dropoffTime *= 60;
			dropoffTime += rideList[index].GetPickupTimeSeconds();
			rideList[index].SetDropoffTime(dropoffTime);
			break;
		}

		//edit size of party
		case 'e':
		{
			int size;
			bool error;
			do
			{
				error = false;
				cout << "Enter What You Would Like To Change Size of Party To:" << endl;
				cin >> size;
				if (cin.fail())
				{
					error = true;
					cout << "Error, Invalid Entry.\n\n";
				}
				cin.clear();
				cin.ignore(1000, '\n');
			} while (error);
			rideList[index].SetPartySize(size);
			break;
		}

		//edit pets
		case 'f':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Would Like To Change If There Are Pets To (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					rideList[index].SetPets(true);
					test = false;
					break;
				case 'n':
					rideList[index].SetPets(false);
					test = false;
					break;
				default:
					cout << "Error, Invalid Entry.\n\n";
					break;
				}
			}
			break;
		}

		//edit handicapped
		case 'g':
		{
			bool test = true;
			char answer;
			while (test) {
				cout << "Enter What You Would Like To Change If Ride Is Handicapped Capable To (y or n):" << endl;
				cin >> answer;
				switch (answer) {
				case 'y':
					rideList[index].SetHandicapped(true);
					test = false;
					break;
				case 'n':
					rideList[index].SetHandicapped(false);
					test = false;
					break;
				default:
					cout << "Error, Invalid Entry.\n\n";
					break;
				}
			}
			break;
		}

		//edit rating by customer
		case 'h':
		{
			float rating;
			bool error;
			do
			{
				error = false;
				cout << "Enter What You Would Like To Change Rating Of Ride To:" << endl;
				cin >> rating;
				if (cin.fail())
				{
					error = true;
					cout << "Error, Invalid Entry.\n\n";
				}
				cin.clear();
				cin.ignore(1000, '\n');
			} while (error);
			rideList[index].SetRating(rating);
			break;
		}

		//quit
		case 'i':
			return;

		//error in input
		default:
			cout << "Option Not Found. Try Again" << endl;
			break;
		}

		cout << endl;
	}
}

//find function
int Rides::FindRide(int id) {
	for (int i = 0; i < rideList.size(); ++i) {
		if (rideList[i].GetRideID() == id) {
			return i;
		}
	}
}


//print specific ride function
void Rides::PrintRide() {
	bool status;
	int id;
	int index;

	//getting ID
	do
	{
		status = false;
		cout << "Enter Ride ID:" << endl;
		cin >> id;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	for (int i = 0; i < rideList.size(); ++i) {
		if (rideList[i].GetRideID() == id) {
			status = true;
			index = i;
		}
	}
	if (!status) {
		cout << "Ride Not Found" << endl;
		cout << endl;
		return;
	}

	//printing ride information
	cout << endl;
	cout << "RIDE " << rideList[index].GetRideID() << " INFORMATION" << endl;
	cout << "Ride ID: " << rideList[index].GetRideID() << endl;
	cout << "Driver ID: " << rideList[index].GetPassengerID() << endl;
	cout << "Passenger ID: " << rideList[index].GetDriverID() << endl;
	cout << "Pickup Location: " << rideList[index].GetPickupLocation() << endl;
	cout << "Pickup Time: " << rideList[index].GetPickupTime();
	cout << "Dropoff Location: " << rideList[index].GetDropoffLocation() << endl;
	cout << "Dropoff Time: " << rideList[index].GetDropoffTime();
	cout << "Size Of Party: " << rideList[index].GetPartySize() << endl;
	cout << "Pets: " << rideList[index].GetPets() << endl;
	cout << "Handicapped Capable: " << rideList[index].GetHandicapped() << endl;
	cout << "Status: " << rideList[index].GetStatus() << endl;
	cout << "Rating By Customer: " << rideList[index].GetRating() << endl;
	cout << endl;
}


//print all rides function
void Rides::PrintAllRides() {

	if (rideList.size() == 0) {
		cout << "No Rides Found" << endl;
		cout << endl;
	}

	for (int i = 0; i < rideList.size(); i++) {

		//printing ride information
		cout << "RIDE " << rideList[i].GetRideID() << " INFORMATION" << endl;
		cout << "Ride ID: " << rideList[i].GetRideID() << endl;
		cout << "Driver ID: " << rideList[i].GetPassengerID() << endl;
		cout << "Passenger ID: " << rideList[i].GetDriverID() << endl;
		cout << "Pickup Location: " << rideList[i].GetPickupLocation() << endl;
		cout << "Pickup Time: " << rideList[i].GetPickupTime();
		cout << "Dropoff Location: " << rideList[i].GetDropoffLocation() << endl;
		cout << "Dropoff Time: " << rideList[i].GetDropoffTime();
		cout << "Size Of Party: " << rideList[i].GetPartySize() << endl;
		cout << "Pets: " << rideList[i].GetPets() << endl;
		cout << "Handicapped Capable: " << rideList[i].GetHandicapped() << endl;
		cout << "Status: " << rideList[i].GetStatus() << endl;
		cout << "Rating By Customer: " << rideList[i].GetRating() << endl;
		cout << endl;
	}
}

//print all rides based on status function
void Rides::PrintAllRidesForStatus() {
	string status;
	bool test = false;

	//getting status
	cout << "Enter Desired Status:" << endl;
	cin.ignore();
	getline(cin, status);
	cout << endl;

	//output
	for (int i = 0; i < rideList.size(); ++i) {
		if (rideList[i].GetStatus() == status) {
			test = true;
			cout << "RIDE " << rideList[i].GetRideID() << " INFORMATION" << endl;
			cout << "Ride ID: " << rideList[i].GetRideID() << endl;
			cout << "Driver ID: " << rideList[i].GetPassengerID() << endl;
			cout << "Passenger ID: " << rideList[i].GetDriverID() << endl;
			cout << "Pickup Location: " << rideList[i].GetPickupLocation() << endl;
			cout << "Pickup Time: " << rideList[i].GetPickupTime();
			cout << "Dropoff Location: " << rideList[i].GetDropoffLocation() << endl;
			cout << "Dropoff Time: " << rideList[i].GetDropoffTime();
			cout << "Size Of Party: " << rideList[i].GetPartySize() << endl;
			cout << "Pets: " << rideList[i].GetPets() << endl;
			cout << "Handicapped Capable: " << rideList[i].GetHandicapped() << endl;
			cout << "Status: " << rideList[i].GetStatus() << endl;
			cout << "Rating By Customer: " << rideList[i].GetRating() << endl;
			cout << endl;
		}
	}

	//no rides with status
	if (!test) {
		cout << "No Rides With Status Found" << endl;
		cout << endl;
	}
}


//print all rides based on driver function
void Rides::PrintAllRidesForDriver() {
	int driverID;
	bool status;

	//getting ID
	do
	{
		status = false;
		cout << "Enter Driver ID:" << endl;
		cin >> driverID;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	cout << endl;

	//output
	status = false;
	for (int i = 0; i < rideList.size(); ++i) {
		if (rideList[i].GetDriverID() == driverID) {
			status = true;
			cout << "RIDE " << rideList[i].GetRideID() << " INFORMATION" << endl;
			cout << "Ride ID: " << rideList[i].GetRideID() << endl;
			cout << "Driver ID: " << rideList[i].GetPassengerID() << endl;
			cout << "Passenger ID: " << rideList[i].GetDriverID() << endl;
			cout << "Pickup Location: " << rideList[i].GetPickupLocation() << endl;
			cout << "Pickup Time: " << rideList[i].GetPickupTime();
			cout << "Dropoff Location: " << rideList[i].GetDropoffLocation() << endl;
			cout << "Dropoff Time: " << rideList[i].GetDropoffTime();
			cout << "Size Of Party: " << rideList[i].GetPartySize() << endl;
			cout << "Pets: " << rideList[i].GetPets() << endl;
			cout << "Handicapped Capable: " << rideList[i].GetHandicapped() << endl;
			cout << "Status: " << rideList[i].GetStatus() << endl;
			cout << "Rating By Customer: " << rideList[i].GetRating() << endl;
			cout << endl;
		}
	}

	//no rides
	if (!status) {
		cout << "No Rides Found" << endl;
		cout << endl;
	}
}

//print all rides based on passenger function
void Rides::PrintAllRidesForPassenger() {
	int passengerID;
	bool status;

	//getting ID
	do
	{
		status = false;
		cout << "Enter Passenger ID:" << endl;
		cin >> passengerID;
		if (cin.fail())
		{
			status = true;
			cout << "Error, Invalid Entry.\n\n";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	} while (status);
	cout << endl;

	//output
	status = false;
	for (int i = 0; i < rideList.size(); ++i) {
		if (rideList[i].GetPassengerID() == passengerID) {
			status = true;
			cout << "RIDE " << rideList[i].GetRideID() << " INFORMATION" << endl;
			cout << "Ride ID: " << rideList[i].GetRideID() << endl;
			cout << "Driver ID: " << rideList[i].GetPassengerID() << endl;
			cout << "Passenger ID: " << rideList[i].GetDriverID() << endl;
			cout << "Pickup Location: " << rideList[i].GetPickupLocation() << endl;
			cout << "Pickup Time: " << rideList[i].GetPickupTime();
			cout << "Dropoff Location: " << rideList[i].GetDropoffLocation() << endl;
			cout << "Dropoff Time: " << rideList[i].GetDropoffTime();
			cout << "Size Of Party: " << rideList[i].GetPartySize() << endl;
			cout << "Pets: " << rideList[i].GetPets() << endl;
			cout << "Handicapped Capable: " << rideList[i].GetHandicapped() << endl;
			cout << "Status: " << rideList[i].GetStatus() << endl;
			cout << "Rating By Customer: " << rideList[i].GetRating() << endl;
			cout << endl;
		}
	}

	//no rides
	if (!status) {
		cout << "No Rides Found" << endl;
		cout << endl;
	}
}

//update status function
void Rides::UpdateStatus() {
	time_t t = time(0);
	for (int i = 0; i < rideList.size(); ++i) {
		if (rideList[i].GetDropoffTimeSeconds() <= t) {
			rideList[i].SetStatus("Completed");
		}
	}
	cout << "Updated Status Of All Completed Rides" << endl;
	cout << endl;

}

void Rides::DeleteRides() {
	for (int i = 0; i < rideList.size(); ++i) {
		if ((rideList[i].GetStatus() == "Completed") || (rideList[i].GetStatus() == "Cancelled")) {
			rideList.erase(rideList.begin() + i);
		}
	}
	cout << "Delted All Cancelled And Completed Rides" << endl;
	cout << endl;
}

//store data function
void Rides::StoreData() {
	ofstream outFS;
	outFS.open("ridesdata.txt");

	outFS << rideList.size() << endl;
	for (int i = 0; i < rideList.size(); ++i) {
		outFS << rideList[i].GetRideID() << endl;
		outFS << rideList[i].GetPassengerID() << endl;
		outFS << rideList[i].GetDriverID() << endl;
		outFS << rideList[i].GetPickupLocation() << endl;
		outFS << rideList[i].GetPickupTimeSeconds() << endl;
		outFS << rideList[i].GetDropoffLocation() << endl;
		outFS << rideList[i].GetDropoffTimeSeconds() << endl;
		outFS << rideList[i].GetPartySize() << endl;
		outFS << rideList[i].GetPets() << endl;
		outFS << rideList[i].GetHandicapped() << endl;
		outFS << rideList[i].GetStatus() << endl;
		outFS << rideList[i].GetRating() << endl;
		outFS << endl;
	}
	outFS.close();
}

//load data function
void Rides::LoadData() {
	ifstream inFS;
	inFS.open("ridesdata.txt");
	if (inFS.is_open()) {
		int num;
		string s;
		int j;
		float f;
		time_t t;
		char c;

		//input data
		inFS >> num;
		for (int i = 0; i < num; ++i) {
			Ride ride;

			inFS >> j;
			ride.SetRideID(j);
			inFS >> j;
			ride.SetPassengerID(j);
			inFS >> j;
			ride.SetDriverID(j);
			inFS.ignore();
			getline(inFS, s);
			ride.SetPickupLocation(s);
			inFS >> t;
			ride.SetPickupTime(t);
			inFS.ignore();
			getline(inFS, s);
			ride.SetDropoffLocation(s);
			inFS >> t;
			ride.SetDropoffTime(t);
			inFS >> j;
			ride.SetPartySize(j);
			inFS >> c;
			if (c == 'y') {
				ride.SetPets(true);
			}
			else {
				ride.SetPets(false);
			}
			inFS >> c;
			if (c == 'y') {
				ride.SetHandicapped(true);
			}
			else {
				ride.SetHandicapped(false);
			}
			inFS.ignore();
			getline(inFS, s);
			ride.SetStatus(s);
			inFS >> f;
			ride.SetRating(f);

			rideList.push_back(ride);
		}
		inFS.close();
	}
}