/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#ifndef PASSENGERS_H
#define PASSENGERS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "passenger.h"
using namespace std;

class Passengers {
public:
	void AddPassenger();
	void DeletePassenger();
	void EditPassenger();
	int FindPassenger(int id);
	void PrintPassenger();
	void PrintAllPassengers();
	void LoadData();
	void StoreData();
	vector <Passenger> GetVector() const { return passengerList; } //for using passenger class pointer

private:
	vector <Passenger> passengerList;
};

#endif