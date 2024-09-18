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

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds {
    // Function to open file
    bool openFile(const char filename[]);

    // Function to close file
    void closeFile();

    // Function to read data from file
    bool read(char* letter, int& number);

}

#endif // SDDS_FILE_H
