/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#include "passenger.h"
using namespace std;

void Passenger::SetPassengerID(int passengerID) {
	this->passengerID = passengerID;
}

void Passenger::SetPassengerFirstName(string passengerFirstName) {
	this->passengerFirstName = passengerFirstName;
}

void Passenger::SetPassengerLastName(string passengerLastName) {
	this->passengerLastName = passengerLastName;
}

void Passenger::SetHandicapped(bool handicapped) {
	this->handicapped = handicapped;
}

void Passenger::SetPaymentPreference(string paymentPreference) {
	this->paymentPreference = paymentPreference;
}

void Passenger::SetRatingRequired(float ratingRequired) {
	this->ratingRequired = ratingRequired;
}

void Passenger::SetHasPets(bool hasPets) {
	this->hasPets = hasPets;
}
