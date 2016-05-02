//Operates data in data.h
//DataOperator.h
//Hanfei Xu
//May 02 2016

#ifndef DATAOPERATOR_H
#define DATAOPERATOR_H
#include <iostream>
#include <iomanip>
#include "Data.h"
using namespace std;

void initDailySum(double dailySumArr[], int numOfDays);
// calcualte for all elements the whole dailySumArr
void calcDailySum(int dayArr[], double amountArr[], int numOfEntries, double dailySumArr[], int numOfDays);
// update certain day/element in dailySumArr
void updateDailySum(int dailySumArr[], int day);


void initDailySum(double dailySumArr[], int numOfDays){
	for (int i = 0; i < numOfDays; ++i)
		dailySumArr[i] = 0;
}

void calcDailySum(int dayArr[], double amountArr[], int numOfEntries, double dailySumArr[], int numOfDays){
	int date;

	for (int i = 0; i < numOfEntries; ++i){
		date = dayArr[i];
		dailySumArr[date - 1] += amountArr[i];
	}

}

void updateDailySum(int dayArr[], double amountArr[],double dailySumArr[], int day){
	for (int i = 0; i < numOfEntries; ++i){
		if (day == dayArr[i])
			dailySumArr[day - 1] += amountArr[i];
	}
}

void printDailySum(double dailySumArr[], int days){
	cout << "\n\n";
	for (int i = 0; i < days; ++i)
		cout << setw(4) << i + 1 << setw(8) << dailySumArr[i]<<endl;
	cout << "\n";
}

void initCataSum(double catagorySumArr[], int numOfCata){
	for (int i = 0; i < numOfCata; ++i)
		catagorySumArr[i] = 0;
}

void calcCataSum(int cataCodeArr[], double amountArr[], int numOfEntries, double catagorySumArr[], int numOfCatas){
	int code;

	for (int i = 0; i < numOfEntries; ++i){
		code = cataCodeArr[i];
		catagorySumArr[code - 1] += amountArr[i];
	}

}


void printCataSum(double catagorySumArr[], int catas){
	cout << "\n\n";
	for (int i = 0; i < catas; ++i)
		cout << setw(4) << i + 1 << setw(8) << dailySumArr[i] << endl;
	cout << "\n";
}


#endif