/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#ifndef DRIVERS_H
#define DRIVERS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "driver.h"
using namespace std;

class Drivers {
public:
	void AddDriver();
	void DeleteDriver();
	void EditDriver();
	int FindDriver(int index, char pets,char handicapped, float ratingRequired, int partySize);
	void PrintDriver();
	void PrintAllDrivers();
	void StoreData();
	void LoadData();
	vector <Driver*> GetVector() const { return driverList; } //for using driver class pointer

private:
	vector <Driver*> driverList;
};

#endif