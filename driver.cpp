/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#include "driver.h"
using namespace std;

void Driver::SetDriverID(int driverID) {
	this->driverID = driverID;
}

void Driver::SetDriverFirstName(string driverFirstName) {
	this->driverFirstName = driverFirstName;
}

void Driver::SetDriverLastName(string driverLastName) {
	this->driverLastName = driverLastName;
}

void Driver::SetDriverType(string driverType) {
	this->driverType = driverType;
}

void Driver::SetHandicapped(bool handicapped) {
	this->handicapped = handicapped;
}

void Driver::SetVehicleType(string vehicleType) {
	this->vehicleType = vehicleType;
}

void Driver::SetDriverRating(float driverRating) {
	this->driverRating = driverRating;
}

void Driver::SetAvailable(bool available) {
	this->available = available;
}

void Driver::SetPets(bool pets) {
	this->pets = pets;
}

void Driver::SetNotes(string notes) {
	this->notes = notes;
}

void Driver::PrintInfo() {
	cout << "DRIVER " << driverID << " INFORMATION" << endl;
	cout << "First Name: " << driverFirstName << endl;
	cout << "Last Name: " << driverLastName << endl;
	cout << "ID: " << driverID << endl;
	cout << "Driver Type: " << driverType << endl;
	cout << "Handicapped Capable: " << this->GetHandicapped() << endl;
	cout << "Vehicle Type: " << vehicleType << endl;
	cout << "Driver Rating: " << driverRating << endl;
	cout << "Available: " << this->GetAvailable() << endl;
	cout << "Pets Allowed: " << this->GetPets() << endl;
	cout << "Notes: " << notes << endl;
}
