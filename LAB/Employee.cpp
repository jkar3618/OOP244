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
#include <iostream>
#include "Employee.h"
#include "File.h"
#include <cstring>

using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& employees) {
        bool ok = false;
        // return the combined success result of the three read functions. These read 
        // functions should set the properties of the reference argument of the load function
        ok = read(employees.m_empNo);
        ok = read(employees.m_salary);
        ok = read(employees.m_name);

        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
// Implementation of the 0 arg load function
    bool load() {
        bool ok = false;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (int i = 0; i < noOfEmployees; i++) {
                if (!load(employees[i])) {
                    cerr << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                    delete[] employees;
                    employees = nullptr;
                    noOfEmployees = 0;
                    ok = false; // Set ok to false if there's an issue
                }
            }
            closeFile();
            ok = true; // Set ok to true after successfully loading all records
        }
        return ok;
    }

    //Display Record with right form
    void displayRecord(const Employee& employees) {
            cout << employees.m_empNo << ": " << employees.m_name << ", $" << (int)employees.m_salary << endl;
    }

    // TODO: Implementation for the display functions go here
    void display() {
        sort();
        displayHeader();
        for (int i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            displayRecord(employees[i]);
        }
    };

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() {
        int i;
        if (employees != NULL) {
            for (i = 0; i < noOfEmployees; i++) {
                delete[] employees[i].m_name;
            }
            delete[] employees;
            employees = NULL;
        }
    };


    //Display Header
    void displayHeader() {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
    };


}