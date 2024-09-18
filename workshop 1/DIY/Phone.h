//*****************************************************************************
//<assessment name example : Workshop - #1 (Part - 2)>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP244 NBB
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************

#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
#define MAX_LENGTH 20

struct phoneBook {
	char name[MAX_LENGTH + 1];
	char areaCode[MAX_LENGTH + 1];
	char prefix[MAX_LENGTH + 1];
	char number[MAX_LENGTH + 1];
};

namespace sdds {
	// runs the phone directory application
	void phoneDir(const char* programTitle, const char* fileName);
	
	// Function to display the program header
	void displayHeader(const char* programTitle);
	
	//Function when file opening is unsuccessful
	void invalidFile(const char* programTitle, const char* fileName);
}

#endif // !SDDS_PHONE_H

