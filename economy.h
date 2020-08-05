/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
#include <string>
#include <fstream>
#include "driver.h"
using namespace std;

class Economy : public Driver {
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

	//set and get if music capable
	void SetMusic(bool music);
	char GetMusic() const {
		switch (music) {
		case true:
			return 'y';
		case false:
			return 'n';
		}
	}

	//set and get if AC capable
	void SetAC(bool AC);
	char GetAC() const {
		switch (AC) {
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
	bool music;
	bool AC;

};

#endif