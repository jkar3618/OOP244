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


#include <iostream>
#include "Train.h"
using namespace std;
using namespace sdds;
void transfer(Train& to, const Train& from);
int main() {
	int i{};
	int notBoarded;
	Train A, B, C, D;
	A.initialize();
	B.initialize();
	C.initialize();
	D.initialize();
	A.set("Seneca Express A", 500, 300);
	B.set("Seneca Express B", 600, 1455);
	C.set("Seneca Express C", 450, 2255);
	D.set("Seneca Espress D", 560, 1022);
	cout << "----------------------------------------" << endl;
	cout << "1. Testing the load function." << endl;
	cout << "----------------------------------------" << endl;
	for (i = 0; i < 2; i++) {
		if (B.load(notBoarded)) {
			cout << "Boarding Complete..." << endl;
		}
		else {
			cout << "Train is full, " << notBoarded << " passengers could not be boarded." << endl;
		}
	}
	cout << "----------------------------------------" << endl;
	cout << "2. Testing the updateDepartureTime function." << endl;
	cout << "----------------------------------------" << endl;
	cout << "Departure time is " << B.getDepartureTime() << endl;
	do {
		if (!B.updateDepartureTime()) {
			cout << "Invalid departure time, valid times are between " << MIN_TIME << " and " << MAX_TIME << "!" << endl;
		}
	} while (B.isInvalid());
	cout << "New departuer time is " << B.getDepartureTime() << endl;
	cout << "----------------------------------------" << endl;
	cout << "3. Testing the transfer function." << endl;
	cout << "----------------------------------------" << endl;
	transfer(C, A);
	transfer(A, C);
	A.set(50, 2200);
	transfer(C, A);
	transfer(D, C);
	A.finalize();
	B.finalize();
	C.finalize();
	D.finalize();
	return 0;
}
void transfer(Train& to, const Train& from) {

	cout << "TRANSFERING\n   FROM: " << endl;
	from.display();
	cout << "   TO:" << endl;
	to.display();
	cout << "---->" << endl;
	if (!to.transfer(from)) {
		cout << "Transfer Failed!" << endl << endl;
	}
	else {
		cout << "Transfer Complete:" << endl;
		to.display();
		cout << endl;
	}
}