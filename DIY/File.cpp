//*****************************************************************************
//<assessment name example : Workshop - #2 (Part - 2)>
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

#include <iostream>
#include <fstream>
#include <cstring>
#include "File.h"

using namespace std;

namespace sdds {
    FILE* fptr;

    // Function to open file
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // Function to close file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // Function to read data from file
    bool read(char* letter, int& number) {
        int noOfRead = 2;

        if (fscanf(fptr, "%3s,%d\n", letter, &number) == noOfRead) {
            return true;
        }
        return false;
    }

}
