//Operates data loaded from file or generated during running
//DataOperator.h
//Hanfei Xu
//May 02 2016

#ifndef DATAOPERATOR_H
#define DATAOPERATOR_H
#include <iostream>
#include <iomanip>

using namespace std;

//void initialMonthData(fstream& file, double &budget, int day[], int cataCode[], double amount[], int arraySize);

// add user input entry into parallel arrays
void addEntry(int dayArr[], int cataCodeArr[], double amountArr[], int& actualSize, int CAP, int day, int code, double amount);

void changeBudget(double& oldB, double newB){
	oldB = newB;
}

// set daily spending to 0 when start a new month
void initDailySum(double dailySumArr[], int numOfDays);

// calcualte for all elements the whole dailySumArr
void calcDailySum(const int dayArr[], const double amountArr[], int numOfEntries, double dailySumArr[], int numOfDays);

// update certain day/element in dailySumArr
void updateDailySum(int dailySumArr[], int day);

void printDailySum(double dailySumArr[], int days);

double calcTotalSpending(const double dailySumArr[], int numOfDays);

void calcCataSum(const int cataCodeArr[], const double amountArr[], int numOfEntries, double catagorySumArr[], int numOfCatas);

void printCataSum(const double catagorySumArr[], int catas);


void addEntry(int dayArr[], int cataCodeArr[], double amountArr[], int& actualSize, int CAP, int day, int code, double amount){
	if (actualSize < CAP){ //TODO deal with too many entires
		dayArr[actualSize] = day;
		cataCodeArr[actualSize] = code;
		amountArr[actualSize] = amount;
		++actualSize;
	}
}


void initDailySum(double dailySumArr[], int numOfDays){
	for (int i = 0; i < numOfDays; ++i)
		dailySumArr[i] = 0;
}

void calcDailySum(const int dayArr[], const double amountArr[], int numOfEntries, double dailySumArr[], int numOfDays){
	int date;

	for (int i = 0; i < numOfEntries; ++i){
		date = dayArr[i];
		dailySumArr[date - 1] += amountArr[i];
	}

}

void updateDailySum(int dayArr[], double amountArr[], double dailySumArr[], int numOfEntries, int day){
	for (int i = 0; i < numOfEntries; ++i){
		if (day == dayArr[i])
			dailySumArr[day - 1] += amountArr[i];
	}
}

double calcTotalSpending(const double dailySumArr[], int numOfDays){
	double total = 0;

	for (int i = 0; i < numOfDays; ++i){
		total += dailySumArr[i];
	}

	return total;
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

void calcCataSum(const int cataCodeArr[], const double amountArr[], int numOfEntries, double catagorySumArr[], int numOfCatas){
	int code;

	for (int i = 0; i < numOfEntries; ++i){
		code = cataCodeArr[i];
		catagorySumArr[code - 1] += amountArr[i];
	}

}


void printCataSum(const double catagorySumArr[], int catas){
	cout << "\n\n";
	for (int i = 0; i < catas; ++i)
		cout << setw(4) << i + 1 << setw(8) << catagorySumArr[i] << endl;
	cout << "\n";
}


#endif