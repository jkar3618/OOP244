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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "cStrTools.h"
#include "Phone.h"

using namespace std;

namespace sdds {

	void phoneDir(const char* programTitle, const char* fileName) {

		phoneBook phone;
		string fullName;
		char name[MAX_LENGTH + 1];
		bool validValue = true; // Flag
		const char* filePointer = 0; // Initialize a search pointer within the file.

		// Call the function to display the header.
		displayHeader(programTitle);

		// Open the file in read mode
		FILE* fptr = fopen(fileName, "r");

		if (fptr != NULL) { // Check the file is opened successfully
			do {
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
				cout << "> ";
				cin >> name;
				toLowerCaseAndCopy(name, name); // Convert typed uppercase to lowercase

				if (strCmp(name, "!") == 0)	{
					cout << "Thank you for using " << programTitle << " directory." << endl;
					validValue = false; // Exit the loop if input is '!'
				}
				else {
					while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", phone.name, phone.areaCode, phone.prefix, phone.number) != EOF)	{
						fullName = phone.name;
						toLowerCaseAndCopy(phone.name, phone.name); // Convert the read name uppercase to lowercase
						filePointer = strStr(phone.name, name); // Search for parts of a string

						if (filePointer != NULL)
						{
						// Display with accurate formatting
						cout << fullName << ": (" << phone.areaCode << ") " << phone.prefix << "-" << phone.number << endl;
						}
					}
					fseek(fptr, 0, SEEK_SET); // Reset the file pointer to the beginning of the file.
				}
			} while (validValue);

			fclose(fptr); // Close the file.
		}
		else {
			invalidFile(programTitle, fileName); // Call if file opening fails
		}
	}

	// Function to display the program header
	void displayHeader(const char* programTitle) {
		cout << programTitle << " phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;
	}

	//Function when file opening is unsuccessful
	void invalidFile(const char* programTitle, const char* fileName) {
		cout << fileName << " file not found!" << endl;
		cout << "Thank you for using " << programTitle << " directory." << endl;
	}
}
