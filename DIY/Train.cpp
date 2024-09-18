//*****************************************************************************
//<assessment name example : Workshop - #3 (Part - 2)>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP244 NBB
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************

#define _CRT_SECURE_NO_WARNINGS

#include "Train.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds {

	// Constructors
	Train::Train() {
		name = nullptr;
		passengers = -1;
		departureTime = -1;
	}

	Train::Train(const char* trainName, int numOfPassengers, int departure) : Train() {
		set(trainName, numOfPassengers, departure);
	}

	// Destructor
	Train::~Train() {
		finalize();
	}

	// Function for initialization
	void Train::initialize() {
		finalize();
	}

	// Function to check time is valid
	bool Train::validTime(int value) const {
		// If value is between MIN_TIME AND MAX_TIME. End of two number is should be between 0 and 59
		if (value >= MIN_TIME && value <= MAX_TIME && value % 100 <= 59) {
			// Time is valid
			return true;
		}
		else {
			// Time is invalid
			return false;
		}
	}

	// Function to check number of passenger is valid
	bool Train::validNoOfPassengers(int value) const {
		// Number of passengers is more than 0 and equal or less than Maximum number of passengers
		if (value > 0 && value <= MAX_NO_OF_PASSENGERS) {
			return true;
		}
		else {
			return false;
		}
	}

	// Functions to set
	void Train::set(const char* trainName) {
		finalize();
		if (trainName != nullptr && strlen(trainName) > 0) {
			name = new char[strlen(trainName) + 1];
			strcpy(name, trainName);
		}
	}

	void Train::set(int noOfPassengers, int departure) {
		if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
			passengers = noOfPassengers;
			departureTime = departure;
		}
		else {
			passengers = -1;
			departureTime = -1;
		}
	}

	void Train::set(const char* trainName, int noOfPassengers, int departure) {
		set(trainName);
		set(noOfPassengers, departure);
	}

	// Function for finalization
	void Train::finalize() {
		delete[] name;
		name = nullptr;
		passengers = -1;
		departureTime = -1;
	}

	// Function for invalid
	bool Train::isInvalid() const {

		// If name is nullptr or passengers and departure tieme are 01 train is invalid
		if (name == nullptr || passengers == -1 || departureTime == -1) {
			return true;
		}
		else {
			// Train is valid
			return false;
		}
	}

	// Function to get number of passenger
	int Train::noOfPassengers() const {
		return passengers;
	}

	// Function to get name
	const char* Train::getName() const {
		if (name != nullptr) {
			return name;
		}
		else {
			return "Train in an invalid state!";
		}

	}

	// Function to get departure time
	int Train::getDepartureTime() const {
		return departureTime;
	}

	// Function to display
	void Train::display() const {
		if (isInvalid()) {
			cout << "Train in an invalid State!" << endl;
		}
		else {
			cout << "NAME OF THE TRAIN:    " << name << endl;
			cout << "NUMBER OF PASSENGERS: " << passengers << endl;
			cout << "DEPARTURE TIME:       " << departureTime << endl;
		}
	}

	// Function to get number of passengers boarding
	bool Train::load(int& notBoarded) {
		int noOfPassenger;

		cout << "Enter number of passengers boarding:" << endl;
		cout << "> ";
		cin >> noOfPassenger;

		// Check number of passengers is not negative and there is enough space in the train
		if (noOfPassenger >= 0 && passengers + noOfPassenger <= MAX_NO_OF_PASSENGERS) {
			passengers += noOfPassenger;
			notBoarded = 0;
			return true;
		}
		else {
			// If the number of passengers is negative
			if (noOfPassenger < 0) {
				notBoarded = -noOfPassenger;
			}
			else {
				// Calculate how many passengers could not be boarded due to lack of space
				notBoarded = passengers + noOfPassenger - MAX_NO_OF_PASSENGERS;
			}

			return false;
		}
	}


	// Function to update departure time
	bool Train::updateDepartureTime() {
		int newDepartureTime;

		cout << "Enter new departure time:" << endl;
		cout << "> ";
		cin >> newDepartureTime;

		// Check the new departure time is valid or not
		if (validTime(newDepartureTime)) {
			// Return true if the new departure time is valid
			departureTime = newDepartureTime;
			return true;
		}
		else {
			// If invalid, set departure time to -1 and return false
			departureTime = -1;
			return false;
		}
	}

	// Fuction for transfer
	bool Train::transfer(const Train& from) {
		bool flag = false;

		// Check if both trains are valid
		if (!this->isInvalid() && !from.isInvalid()) {

			// Calculate the total length of the names
			size_t thisNameLength = strlen(this->name);
			size_t fromNameLength = strlen(from.name);
			size_t totalNameLength = thisNameLength + strlen(", ") + fromNameLength + 1;

			// Allocate memory for the new name
			char* newName = new char[totalNameLength]; // +1 for null terminator


			// Check if memory allocation was successful
			if (newName != nullptr) {

				// Copy the current train's name to the new buffer
				strcpy(newName, this->name);
				// Concatenate the names using strcat and add ", " in between
				strcat(newName, ", ");
				strcat(newName, from.name);

				// Free the old name and update the pointer with the new name
				delete[] this->name;
				this->name = newName;

				// Update the total number of passengers
				this->passengers += from.passengers;

				if (validNoOfPassengers(this->passengers)) {
					// If the total number of passengers is valid, set transfer flag to true
					flag = true;
				}
				else {
					cout << "Train is full; " << this->passengers - MAX_NO_OF_PASSENGERS << " passengers of " << from.name << " could not be boarded!" << endl;
					this->passengers = MAX_NO_OF_PASSENGERS;
					flag = true;
				}
			}
			else {
				cout << "Memory allocation failed for the new name." << endl;
			}
		}
		return flag;
	}








	//bool Train::transfer(const Train& from) {
	//	bool transfer = false;

	//	if (!this->isInvalid() && !from.isInvalid()) {
	//		// Calculate the combined length of the names
	//		size_t combinedLength = strlen(this->name) + strlen(", ") + strlen(from.name) + 1;

	//		// Dynamically allocate memory for the new name
	//		char* newTName = new char[combinedLength];

	//		// Check if memory allocation was successful
	//		if (newTName != nullptr) {
	//			// Copy the current train's name to the new buffer
	//			strcpy(newTName, this->name);

	//			// Concatenate the names using strcat
	//			strcat(newTName, ", ");
	//			strcat(newTName, from.name);

	//			// Free the old name and update the pointer
	//			delete[] this->name;
	//			this->name = newTName;

	//			this->passengers += from.passengers;
	//			if (validNoOfPassengers(this->passengers)) {
	//				transfer = true;
	//			}
	//			else {
	//				cout << "Train is full; " << this->passengers - MAX_NO_OF_PASSENGERS << " passengers of " << from.name << " could not be boarded!" << endl;
	//				this->passengers = MAX_NO_OF_PASSENGERS;
	//				transfer = true;
	//			}
	//		}
	//		else {
	//			cout << "Memory allocation failed for the new name." << endl;
	//		}
	//	}

	/*	return transfer;
	}*/



}




