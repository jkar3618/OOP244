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


#ifndef TRAIN_H
#define TRAIN_H

#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

namespace sdds {


    class Train {
    private:
        char* name;
        int passengers;
        int departureTime;

    public:
        // Constructors and Destructor
        Train();
        Train(const char* trainName, int numOfPassengers, int departure);
        ~Train();

        // Function for initialization
        void initialize();

        // Function to check time is valid
        bool validTime(int value) const;

        // Function to check number of passenger is valid
        bool validNoOfPassengers(int value) const;

        // Set functions
        void set(const char* name);
        void set(int noOfPassengers, int departure);
        void set(const char* name, int noOfPassengers, int departure);

        // Function for finalization
        void finalize();

        // Function for invalid
        bool isInvalid() const;

        // Function to get number of passenger
        int noOfPassengers() const;

        // Function to get name
        const char* getName() const;

        // Function to get departure time
        int getDepartureTime() const;

        // Display function
        void display() const;

        // Function to get number of passengers boarding
        bool load(int& notBoarded);

        // Function to update departure time
        bool updateDepartureTime();

        // Fuction for transfer
        bool transfer(const Train& from);
    };

}

#endif // TRAIN_H
