/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#ifndef RIDES_H
#define RIDES_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "ride.h"
#include "passengers.h"
#include "drivers.h"
using namespace std;

class Rides {
public:
	Rides(Drivers* d, Passengers* p); //setting pointer
	void AddRide();
	void CancelRide();
	void EditRide();
	int FindRide(int id);
	void PrintRide();
	void PrintAllRides();
	void PrintAllRidesForPassenger();
	void PrintAllRidesForDriver();
	void PrintAllRidesForStatus();
	void UpdateStatus();
	void DeleteRides();
	void StoreData();
	void LoadData();

private:
	vector <Ride> rideList;
	Passengers* passengers; //passengers class pointer
	Drivers* drivers; //drivers class pointer
};

#endif