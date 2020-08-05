/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#include <iostream>
#include <fstream>
#include "drivers.h"
#include "passengers.h"
#include "rides.h"
using namespace std;

void LoadData(Drivers& drivers, Passengers& passengers, Rides& rides);
void StoreData(Drivers drivers, Passengers passengers, Rides rides);

int main() {
	bool status = true;
	char input;

	//setting up class objects and pointers
	Drivers drivers;
	Passengers passengers;
	Drivers* d;
	d = &drivers;
	Passengers* p;
	p = &passengers;
	Rides rides(d, p);

	//basic info
	cout << endl;
	cout << "          MEAN GREEN EAGLELIFT SYSTEM" << endl;
	cout << endl;
	cout << "+----------------------------------------------+" << endl;
	cout << "|       Computer Science and Engineering       |" << endl;
	cout << "|        CSCE 1040 - Computer Science I        |" << endl;
	cout << "|   John Li      jl1081      johnli@my.unt.edu |" << endl;
	cout << "+----------------------------------------------+" << endl;
	cout << endl;
	cout << endl;

	//load data
	LoadData(drivers,passengers,rides);
	
	while (status) {
		cout << "                       MENU" << endl;
		cout << "a - Drivers Menu" << endl;
		cout << "b - Passengers Menu" << endl;
		cout << "c - Rides Menu" << endl;
		cout << "d - Quit Menu" << endl;
		cout << "Enter Respective Letter:" << endl;
		cin >> input;
		cout << endl;
		switch (input) {
		case 'a':

			//drivers menu
			while (status) {
				cout << "                  Drivers Menu" << endl;
				cout << "a - Add Driver" << endl;
				cout << "b - Delete Driver" << endl;
				cout << "c - Edit Driver" << endl;
				cout << "d - Print Information For Specific Driver" << endl;
				cout << "e - Print Information For All Drivers" << endl;
				cout << "f - Return to Main Menu" << endl;
				cout << "Enter Respective Letter:" << endl;
				cin >> input;
				cout << endl;
				switch (input) {
				case 'a':
					drivers.AddDriver();
					StoreData(drivers, passengers, rides);
					break;
				case 'b':
					drivers.DeleteDriver();
					StoreData(drivers, passengers, rides);
					break;
				case 'c':
					drivers.EditDriver();
					StoreData(drivers, passengers, rides);
					break;
				case 'd':
					drivers.PrintDriver();
					break;
				case 'e':
					drivers.PrintAllDrivers();
					break;
				case 'f':
					status = false;
					break;
				default:
					cout << "Option Not Found. Try Again" << endl;
					cout << endl;
					break;
				}
			}

			status = true;
			cout << endl;
			break;
		case 'b':

			//passengers menu
			while (status) {
				cout << "                Passengers Menu" << endl;
				cout << "a - Add Passenger" << endl;
				cout << "b - Delete Passenger" << endl;
				cout << "c - Edit Passenger" << endl;
				cout << "d - Print Information For Specific Passenger" << endl;
				cout << "e - Print Information For All Passengers" << endl;
				cout << "f - Return to Main Menu" << endl;
				cout << "Enter Respective Letter:" << endl;
				cin >> input;
				cout << endl;
				switch (input) {
				case 'a':
					passengers.AddPassenger();
					StoreData(drivers, passengers, rides);
					break;
				case 'b':
					passengers.DeletePassenger();
					StoreData(drivers, passengers, rides);
					break;
				case 'c':
					passengers.EditPassenger();
					StoreData(drivers, passengers, rides);
					break;
				case 'd':
					passengers.PrintPassenger();
					break;
				case 'e':
					passengers.PrintAllPassengers();
					break;
				case 'f':
					status = false;
					break;
				default:
					cout << "Option Not Found. Try Again" << endl;
					cout << endl;
					break;
				}
			}

			status = true;
			cout << endl;
			break;
		case 'c':

			//Rides Menu
			while (status) {
				cout << "                   Rides Menu" << endl;
				cout << "a - Add Ride" << endl;
				cout << "b - Cancel Ride" << endl;
				cout << "c - Edit Ride" << endl;
				cout << "d - Print Information For Specific Ride" << endl;
				cout << "e - Print Information For All Rides" << endl;
				cout << "f - Print All Rides For Specific Passenger" << endl;
				cout << "g - Print All Rides For Specific Driver" << endl;
				cout << "h - Print All Rides For Specific Status" << endl;
				cout << "i - Update Status Of Completed Rides" << endl;
				cout << "j - Delete Cancelled/Finished Rides" << endl;
				cout << "k - Return to Main Menu" << endl;
				cout << "Enter Respective Letter:" << endl;
				cin >> input;
				cout << endl;
				switch (input) {
				case 'a':
					rides.AddRide();
					StoreData(drivers, passengers, rides);
					break;
				case 'b':
					rides.CancelRide();
					StoreData(drivers, passengers, rides);
					break;
				case 'c':
					rides.EditRide();
					StoreData(drivers, passengers, rides);
					break;
				case 'd':
					rides.PrintRide();
					break;
				case 'e':
					rides.PrintAllRides();
					break;
				case 'f':
					rides.PrintAllRidesForPassenger();
					break;
				case 'g':
					rides.PrintAllRidesForDriver();
					break;
				case 'h':
					rides.PrintAllRidesForStatus();
					break;
				case 'i':
					rides.UpdateStatus();
					StoreData(drivers, passengers, rides);
					break;
				case 'j':
					rides.DeleteRides();
					StoreData(drivers, passengers, rides);
					break;
				case 'k':
					status = false;
					break;
				default:
					cout << "Option Not Found. Try Again" << endl;
					cout << endl;
					break;
				}
			}

			status = true;
			cout << endl;
			break;
		case 'd':
			status = false;
			break;
		default:
			cout << "Option Not Found. Try Again" << endl;
			cout << endl;
			break;
		}
	}
	StoreData(drivers, passengers, rides);
	return 0;
}

void LoadData(Drivers& drivers, Passengers& passengers, Rides& rides) {
	drivers.LoadData();
	passengers.LoadData();
	rides.LoadData();
}

void StoreData(Drivers drivers, Passengers passengers, Rides rides) {
	drivers.StoreData();
	passengers.StoreData();
	rides.StoreData();
}