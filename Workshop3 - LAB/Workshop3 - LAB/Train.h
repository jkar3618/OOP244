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
        // Constructor
        Train();

        Train(const char* trainName, int numOfPassengers, int departure);
        
        // Destructor
        ~Train();

        // Initialization and Validation functions
        void initialize();
        bool validTime(int value) const;
        bool validNoOfPassengers(int value) const;

        // Set function
        void set(const char* name);
        void set(int noOfPassengers, int departure);
        void set(const char* name, int noOfPassengers, int departure);
        
        // Finalization and Invalidation function
        void finalize();
        bool isInvalid() const;
        
        // Getting info fuction
        int noOfPassengers() const;
        const char* getName() const;
        int getDepartureTime() const;
        
        // Display function
        void display() const;


        bool load(int& leftBehind);
        bool updateDepartureTime();
        bool transfer(Train& otherTrain); 

    };

}

#endif // TRAIN_H
