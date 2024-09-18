//*****************************************************************************
//<assessment name example : Workshop - #2 (Part - 1)>
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
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
	FILE* fptr;
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	void closeFile() {
		if (fptr) fclose(fptr);
	}
	//TODO: read functions go here
	bool read(int& employeeNum) {
		if (fscanf(fptr, "%d,", &employeeNum) == 1) {
			return true;
		}
		return false;
	}
	bool read(double& salary) {
		if (fscanf(fptr, "%lf,", &salary) == 1) {
			return true;
		}
		return false;
	}
	bool read(char*& employeeName) {
		char name[128];
		if (fscanf(fptr, "%127[^,\n]\n", name) == 1) {
			employeeName = new char[strlen(name) + 1];
			strcpy(employeeName, name);
			return true;
		}
		return false;
	}

}