/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#ifndef RIDE_H
#define RIDE_H
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Ride {
public:
	//set and get ride ID
	void SetRideID(int rideID);
	int GetRideID() const { return rideID; }

	//set and get driver ID
	void SetDriverID(int driverID);
	int GetDriverID() const { return driverID; }

	//set and get passenger ID
	void SetPassengerID(int passengerID);
	int GetPassengerID() const { return passengerID; }

	//set and get pickup location
	void SetPickupLocation(string pickupLocation);
	string GetPickupLocation() const { return pickupLocation; }

	//set and get dropoff location
	void SetDropoffLocation(string dropoffLocation);
	string GetDropoffLocation() const { return dropoffLocation; }

	//set and get pickup time
	void SetPickupTime(time_t pickupTime);
	string GetPickupTime() const {
		char* time = ctime(&pickupTime);
		return time;
	}
	time_t GetPickupTimeSeconds() const { return pickupTime; }

	//set and get dropoff time
	void SetDropoffTime(time_t dropoffTime);
	string GetDropoffTime() const {
		char* time = ctime(&dropoffTime);
		return time;
	}
	time_t GetDropoffTimeSeconds() const { return dropoffTime; }

	//set and get party size
	void SetPartySize(int partySize);
	int GetPartySize() const { return partySize; }

	//set and get ride rating
	void SetRating(float rating);
	float GetRating() const { return rating; }

	//set and get pets on ride
	void SetPets(bool pets);
	char GetPets() const {
		switch (pets) {
		case true:
			return 'y';
		case false:
			return 'n';
		}
	}

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

	//set and get ride status
	void SetStatus(string status);
	string GetStatus() const { return status; }

private:
	int rideID;
	int passengerID;
	int driverID;
	string pickupLocation;
	time_t pickupTime;
	string dropoffLocation;
	time_t dropoffTime;
	int partySize;
	bool pets;
	bool handicapped;
	string status;
	float rating;
};

#endif