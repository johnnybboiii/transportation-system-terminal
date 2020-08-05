/* Name: John Li
   Email: johnli@my.unt.edu
   Description:	system to schedule drivers and passengers for rides in the Mean Green EagleLift System
*/

#include <iostream>
#include <string>
using namespace std;

#include "ride.h"

void Ride::SetDriverID(int driverID) {
	this->driverID = driverID;
}

void Ride::SetPassengerID(int passengerID) {
	this->passengerID = passengerID;
}

void Ride::SetRideID(int rideID) {
	this->rideID = rideID;
}

void Ride::SetPickupLocation(string pickupLocation) {
	this->pickupLocation = pickupLocation;
}

void Ride::SetDropoffLocation(string dropoffLocation) {
	this->dropoffLocation = dropoffLocation;
}

void Ride::SetPickupTime(time_t pickupTime) {
	this->pickupTime = pickupTime;
}

void Ride::SetDropoffTime(time_t dropoffTime) {
	this->dropoffTime = dropoffTime;
}

void Ride::SetPartySize(int partySize) {
	this->partySize = partySize;
}

void Ride::SetRating(float rating) {
	this->rating = rating;
}

void Ride::SetHandicapped(bool handicapped) {
	this->handicapped = handicapped;
}

void Ride::SetPets(bool pets) {
	this->pets = pets;
}

void Ride::SetStatus(string status) {
	this->status = status;
}
