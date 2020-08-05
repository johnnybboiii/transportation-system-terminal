/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include <string>
using namespace std;

class Passenger {
public:
	//set and get passenger ID
	void SetPassengerID(int passengerID);
	int GetPassengerID() const { return passengerID; }

	//set and get passenger first name
	void SetPassengerFirstName(string passengerFirstName);
	string GetPassengerFirstName() const { return passengerFirstName; }

	//set and get passenger last name
	void SetPassengerLastName(string passengerLastName);
	string GetPassengerLastName() const { return passengerLastName; }

	//set and get payment preference
	void SetPaymentPreference(string paymentPreference);
	string GetPaymentPreference() const { return paymentPreference; }

	//set and get if handicapped
	void SetHandicapped(bool handicapped);
	char GetHandicapped() const {
		switch (handicapped) {
		case true:
			return 'y';
		case false:
			return 'n';
		}
	}

	//set and get rating required
	void SetRatingRequired(float ratingRequired);
	float GetRatingRequired() const { return ratingRequired; }

	//set and get if passenger has pets
	void SetHasPets(bool hasPets);
	char GetHasPets() const {
		switch (hasPets) {
		case true:
			return 'y';
		case false:
			return 'n';
		}
	}

private:
	int passengerID;
	string passengerFirstName;
	string passengerLastName;
	string paymentPreference;
	bool handicapped;
	float ratingRequired;
	bool hasPets;
};

#endif