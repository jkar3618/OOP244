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


#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Train.h"
using namespace sdds;

int main() {
	int i;
	Train trains[7];
	char st[] = "Seneca Express A";
	for (i = 0; i < 7; i++) {
		trains[i].initialize();
	}
	trains[0].set(nullptr, 100, 945);;
	trains[1].set("", 100, 945);
	trains[2].set("VIA Rail Abitibi", -100, 945);
	trains[3].set("VIA Rail Abitibi", 100, 645);
	trains[4].set("VIA Rail Abitibi", 100, 2355);
	trains[5].set("Seneca Express", -1, -1);
	trains[6].set("VIA Rail Abitibi", 333, 2055);

	cout << "----------------------------------------" << endl;
	cout << "1. Testing the validation logic." << endl;
	cout << "(only trains[6] should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (i = 0; i < 7; ++i)
	{
		cout << "trains[" << i << "]: "
			<< (trains[i].isInvalid() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	//
	cout << "----------------------------------------" << endl;
	cout << "2. Testing the display function." << endl;
	cout << "----------------------------------------" << endl;
	for (i = 0; i < 7; ++i)
	{
		trains[i].display();
	}
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "3. Testing the member functions." << endl;
	cout << "----------------------------------------" << endl;
	for (i = 0; i < 7; i++) {
		trains[i].set(st);
		trains[i].set(100 + i * 155, 630 + i * 100 + i * 6);
		st[15]++;
		cout << (i + 1) << ": ";
		if (trains[i].isInvalid()) {
			cout << "*************" << endl;
		}
		else {
			cout << trains[i].getName() << " leaves at " << trains[i].getDepartureTime() << " with " << trains[i].noOfPassengers() << " passengers." << endl;
		}
	}
	cout << "----------------------------------------" << endl << endl;
	for (i = 0; i < 7; i++) {
		trains[i].finalize();
	}
	return 0;
}