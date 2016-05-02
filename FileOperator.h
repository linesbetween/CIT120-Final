//Load, write files
//FileOperator.h
//Hanfei Xu
//May 02 2016

#ifndef FILEOPERATOR_H
#define FILEOPERATOR_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Data.h"
using namespace std;

//file exists
int loadMonthData(ifstream& file, double &budget, int day[], int cataCode[], double amount[], int arraySize){
	int actualSize;

	file >> monthBudget;
	for (int i = 0; i < arraySize && !file.fail(); ++i){
		file.ignore(80, '#');
		file >> day[i] >> cataCode[i] >> amount[i];
		actualSize = i;
	}

	return actualSize;
}
//return logical size of arrays

void printMonthDataArrays(const double budget, const int day[], const int cataCode[], const double amount[], int size, ostream &Os){
	const int
		WID = 4,
		WID_NUM = 8;

	cout << left << "\n\n\nData of month\n";
	cout << "Budget: " << budget << "\n";
	for (int i = 0; i < size; ++i){
		Os
			<< setw(WID) << day[i]
			<< setw(WID) << cataCode[i]
			<< setw(WID_NUM) << amount[i]
			<< "\n";

	}
}

#endif