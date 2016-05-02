#include "Utility.h"
#include "FileOperator.h"
#include "DataOperator.h"
#include "HistogramH.h"
#include "Data.h"
#include <fstream>
void main(){

	/*
	// initialize test numbers in 
	ofstream file;
	file.open("RecordTrack.txt", ios::out | ios::trunc);

	for (int i = 1; i <=91; ++i){
		file << 0 <<" ";
	}

	for (int i = 92; i <= 118; ++i){
		file << 1 << " ";
	}

	for (int i = 119; i <= 366; ++i){
		file << 0 << " ";
	}

	file.close();
	*/

	ifstream tracker;
	tracker.open("DailyChecker.txt", ios::in);

	for (int i = 0; i < 366; ++i){
		tracker >> calendarDay[i];
	}

	tracker.close();

	printMontlyCalendar(3);
	printMontlyCalendar(4);
	printMontlyCalendar(5);

	ifstream dataFile;
	dataFile.open(dataFileNameArr[3]);
	numOfEntries = loadMonthData(dataFile, monthBudget, dayArr, cataCodeArr, amountArr, CAP);
	printMonthDataArrays(monthBudget, dayArr, cataCodeArr, amountArr, numOfEntries, cout);
	dataFile.close();

	initDailySum(dailySumArr, MAX_DAYS_IN_MONTH);
	calcDailySum(dayArr, amountArr, numOfEntries, dailySumArr, MAX_DAYS_IN_MONTH);
	printDailySum(dailySumArr, numOfDaysInMonth[3]);

	initCataSum(catagorySumArr, NUM_OF_CATAGORY);
	calcCataSum(cataCodeArr, amountArr, numOfEntries, catagorySumArr, NUM_OF_CATAGORY);
	printDailySum(catagorySumArr, NUM_OF_CATAGORY);

	printHistogramH(catagorySumArr, 4, 10);

	cout << "\n\n";
	system("pause");

}