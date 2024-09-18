//*****************************************************************************
//<assessment name example : Workshop - #3 (Part - 1)>
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
    // Constructor
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

    void Train::initialize() {
        finalize();
    }

    // Check valid Time
    bool Train::validTime(int value) const {
        return (value >= MIN_TIME && value <= MAX_TIME && value % 100 <= 59);
    }

    // Check valid number of passengers
    bool Train::validNoOfPassengers(int value) const {
        return (value > 0 && value <= MAX_NO_OF_PASSENGERS);
    }

    // Set name of train
    void Train::set(const char* trainName) {
        finalize();
        if (trainName != nullptr && strlen(trainName) > 0) {
            name = new char[strlen(trainName) + 1];
            strcpy(name, trainName);
        }
    }

    // Set name of number of passengers and departure time if they are valid
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

    // Set name of train, number of passengers and departure time
    void Train::set(const char* trainName, int noOfPassengers, int departure) {
        set(trainName);
        set(noOfPassengers, departure);
    }

    // Deallocate memory
    void Train::finalize() {
        delete[] name;
        name = nullptr;
        passengers = -1;
        departureTime = -1;
    }

    // Checks if any condition is invalid
    bool Train::isInvalid() const {
        return (name == nullptr || passengers == -1 || departureTime == -1);
    }

    // Getting number of passengers
    int Train::noOfPassengers() const {
        return passengers;
    }

    // Getting name of train
    const char* Train::getName() const {
        return (name != nullptr) ? name : "Train in an invalid State!";
    }

    // Getting departure time
    int Train::getDepartureTime() const {
        return departureTime;
    }

    // Display information
    void Train::display() const {
        
        if (isInvalid()) {
            cout << "Train in an invalid State!" << endl;
        }
        else {
            cout << "NAME OF THE TRAIN:    " << name << endl;
            cout << "NUMBER OF PASSENGERS:" << setw(4) << passengers << endl;
            cout << "DEPARTURE TIME:       " << setw(4) << departureTime << endl;
        }
    }

    // Get number of passenger boarding
    bool Train::load(int& leftBehind) {
        int noOfPassengers;
        
        cout << "Enter number of passengers boarding:" << endl;
        cin >> noOfPassengers;
        
        if (noOfPassengers > MAX_NO_OF_PASSENGERS) {
            leftBehind = noOfPassengers - MAX_NO_OF_PASSENGERS;
            passengers = MAX_NO_OF_PASSENGERS;
        }
        else {
            leftBehind = 0;
            passengers = noOfPassengers;
        }
        
        return (leftBehind == 0);
    }

    // Get departure time
    bool Train::updateDepartureTime() {

        int newDepartureTime;
        
        cout << "Enter new departure time:" << endl;
        cin >> newDepartureTime;
        
        if (validTime(newDepartureTime)) {
            departureTime = newDepartureTime;
            return true;
        }
        else {
            departureTime = -1;
            return false;
        }
    }

    // Transfer passenger from another train
    bool Train::transfer(Train& otherTrain) {
        
        char* fullName = new char[strlen(name) + strlen(otherTrain.name) + 3];
        int leftBehind;


        if (isInvalid() || otherTrain.isInvalid()) {
            return false;
        }
        strcpy(fullName, name);
        strcat(fullName, ", ");
        strcat(fullName, otherTrain.name);

        if (otherTrain.load(leftBehind)) {
            passengers += otherTrain.noOfPassengers();
            finalize();
            name = fullName;
            return true;
        }
        else {
            cout << "Train is full; " << leftBehind << " passengers of " << fullName << " could not be boarded!" << endl;
            delete[] fullName;
            return false;
        }
    }

}