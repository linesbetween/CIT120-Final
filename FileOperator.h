//Load, write files
//FileOperator.h
//Hanfei Xu
//May 02 2016

#ifndef FILEOPERATOR_H
#define FILEOPERATOR_H
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int loadMonthData(fstream& file, double &budget, int day[], int cataCode[], double amount[], int arraySize);
void writeMonthData(fstream& file, double &budget, const int day[], const int cataCode[], const double amount[], int arraySize);
void printMonthDataArrays(double budget, const int day[], const int cataCode[], const double amount[], int size, ostream &Os);
void loadDailySpend(fstream& file, double dailySpend[], int size); //TODO test
void writeDailySpend(fstream& file, const double dailySpend[], int size); //TODO test

//file exists
int loadMonthData(fstream& file, double &budget, int day[], int cataCode[], double amount[], int arraySize){
	int actualSize = 0;

	file >> budget;
	for (int i = 0; i < arraySize && !file.fail(); ++i){ //TODO Too many entrie error file not exist error
		file.ignore(80, '#');
		file >> day[i] >> cataCode[i] >> amount[i];
		actualSize = i;
	}

	return actualSize;
}
//return logical size of arrays

void writeMonthData(fstream& file, double budget, const int day[], const int cataCode[], const double amount[], int actualSize){
	file << budget << "\n";
	
	for (int i = 0; i < actualSize; ++i)
		file << "#" << day[i] <<" "<< cataCode[i] <<" "<< amount[i] <<"\n";
}

void printMonthDataArrays(double budget, const int day[], const int cataCode[], const double amount[], int size, ostream &Os){
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

void loadDailySpend(fstream& file, double dailySpend[], int size){
	for (int i = 0; i < size; ++i)
		file >> dailySpend[i];
}

void writeDailySpend(fstream& file, const double dailySpend[], int size){
	for (int i = 0; i < size; ++i)
		file << dailySpend[i] << " ";
}

#endif