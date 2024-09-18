/*****************************************************************************
//<assessment name example : Workshop - #2 (Part - 2)>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP244 NBB
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
*****************************************************************************/
#ifndef SDDS_POPULATION_H
#define SDDS_POPULATION_H
#define MAX_LENGTH 5

namespace sdds {

    struct PostalCode {
        char* postalCode;
        int population;
    };
    // returns true of the cstring starts with subString
    bool startsWith(const char* cString, const char* subString);

    // Function to sort postalCodes array in ascending order of population
    void sort();

    // Function to search partial postal code in file
    bool partialCode(const char* code);

    // Function to get input
    bool getPostalCode(char* postal_code_prefix);

    // Function to load postal code from file
    bool load(const char* filename, const char* partial_postal_code_prefix);
    
    // Function to display postal code and population
    void display();
    
    // Function to deallocate memory
    void deallocateMemory();
}

#endif // SDDS_POPULATION_H
