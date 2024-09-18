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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"

using namespace std;

namespace sdds {

	PostalCode* postalCodes;
	int noOfPostalCode = 0;

	bool startsWith(const char* cstring, const char* subString) {
		return std::strstr(cstring, subString) == cstring;
	}

	// Function to sort postalCodes array in ascending order of population
	void sort() {
		int i, j;
		PostalCode temp;
		for (i = noOfPostalCode - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (postalCodes[j].population > postalCodes[j + 1].population) {
					temp = postalCodes[j];
					postalCodes[j] = postalCodes[j + 1];
					postalCodes[j + 1] = temp;
				}
			}
		}
	}

	// Function to search partial postal code in file
	bool partialCode(const char* code) {

		char postalCode[MAX_LENGTH];
		int number;

		while (read(postalCode, number) != false) {
			if (startsWith(postalCode, code)) {
				return true;
			}
		}
		return false;
	}

	// Function to get input
	bool getPostalCode(char* postalCode) {

		cout << "Population Report" << endl;
		cout << "-----------------" << endl;
		cout << "Enter postal code:" << endl;
		cout << "> ";
		cin.getline(postalCode, MAX_LENGTH);

		if (strcmp(postalCode, "!") == 0) {
			return false;
		}

		return true;
	}

	// Function to load postal code from file
	bool load(const char* filename, const char* partialPostalCode) {

		int number, i;
		char postalCode[MAX_LENGTH];

		if (!openFile(filename)) {
			return false;
		}

		while (read(postalCode, number)) {
			if (startsWith(postalCode, partialPostalCode) || strcmp(partialPostalCode, "all") == 0) {
				PostalCode* temp = new PostalCode[noOfPostalCode + 1];
				for (i = 0; i < noOfPostalCode; i++) {
					temp[i] = postalCodes[i];
				}
				temp[noOfPostalCode].postalCode = new char[strlen(postalCode) + 1];
				strcpy(temp[noOfPostalCode].postalCode, postalCode);
				temp[noOfPostalCode].population = number;
				delete[] postalCodes;
				postalCodes = temp;
				noOfPostalCode++;
			}
		}

		closeFile();
		return true;
	}

	// Function to display postal code and population in ascending order of population
	void display() {
		int Population = 0;

		// Sort postalCodes array by population (ascending order)
		sort();

		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;

		for (int i = 0; i < noOfPostalCode; i++) {
			cout << i + 1 << "- " << postalCodes[i].postalCode << ":  " << postalCodes[i].population << endl;
			Population += postalCodes[i].population;
		}

		cout << "-------------------------" << endl;
		cout << "Population of the listed areas: " << Population << endl;
		cout << endl;
	}


	// Function to deallocate memory
	void deallocateMemory() {
		for (int i = 0; i < noOfPostalCode; i++) {
			delete[] postalCodes[i].postalCode;
		}
		delete[] postalCodes;
		postalCodes = nullptr;
		noOfPostalCode = 0;
	}
}
