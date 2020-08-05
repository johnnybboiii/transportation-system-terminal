/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <string>
#include <fstream>
#include "driver.h"
using namespace std;

class Group : public Driver {
public:

	//set and get vehicle capacity
	void SetVehicleCapacity(int vehicleCapacity) override;
	int GetVehicleCapacity() const override { return vehicleCapacity; }

	//set and get cargo capacity
	void SetCargoCapacity(int cargoCapacity);
	int GetCargoCapacity() const { return cargoCapacity; }

	//override function to print driver information
	void PrintInfo() override;

	//override function to add driver information
	void AddInfo() override;

	//set and get if oversized luggage capable
	void SetOversizedLuggage(bool oversizedLuggage);
	char GetOversizedLuggage() const {
		switch (oversizedLuggage) {
		case true:
			return 'y';
		case false:
			return 'n';
		}
	}

	//set and get if food allowed
	void SetFood(bool food);
	char GetFood() const {
		switch (food) {
		case true:
			return 'y';
		case false:
			return 'n';
		}
	}

	//store data
	void StoreData(ofstream& outFS) override;

	//load data
	void LoadData(ifstream& inFS) override;

	//edit driver
	void EditDriver() override;

private:
	int vehicleCapacity;
	int cargoCapacity;
	bool oversizedLuggage;
	bool food;

};

#endif