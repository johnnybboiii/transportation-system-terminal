/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include <string>
using namespace std;

class Driver {
public:
	//set and get driver ID
	void SetDriverID(int driverID);
	int GetDriverID() const { return driverID; }

	//set and get driver first name
	void SetDriverFirstName(string driverFirstName);
	string GetDriverFirstName() const { return driverFirstName; }

	//set and get driver type
	void SetDriverType(string type);
	string GetDriverType() const { return driverType; }

	//set and get driver last name
	void SetDriverLastName(string driverLastName);
	string GetDriverLastName() const { return driverLastName; }

	//set and get if handicapped capable
	void SetHandicapped(bool handicapped);
	char GetHandicapped() const {
		switch (handicapped) {
		case true:
			return 'y';
		case false:
			return 'n';
		}
	}

	//set and get vehicle type
	void SetVehicleType(string vehicleType);
	string GetVehicleType() const { return vehicleType; }

	//set and get rating
	void SetDriverRating(float driverRating);
	float GetDriverRating() const { return driverRating; }

	//set and get if available
	void SetAvailable(bool available);
	char GetAvailable() const {
		switch (available) {
		case true:
			return 'y';
		case false:
			return 'n';
		}
	}

	//set and get if pets allowed
	void SetPets(bool pets);
	char GetPets() const {
		switch (pets) {
		case true:
			return 'y';
		case false:
			return 'n';
		}
	}

	//set and get driver notes
	void SetNotes(string notes);
	string GetNotes() const { return notes; }

	//virtual function to print driver information
	virtual void PrintInfo();

	//virtual function to add addition information
	virtual void AddInfo() = 0;

	//virtual function to get vehicle capacity
	virtual void SetVehicleCapacity(int capacity) {};
	virtual int GetVehicleCapacity() const { return 0; }

	//virtual function to store data
	virtual void StoreData(ofstream& outFS) {};

	//virtual function to load data
	virtual void LoadData(ifstream& inFS) {};

	//virtual function to edit driver
	virtual void EditDriver() {};

protected:
	int driverID;
	string driverFirstName;
	string driverLastName;
	string driverType;
	bool handicapped;
	string vehicleType;
	float driverRating;
	bool available;
	bool pets;
	string notes;
};

#endif