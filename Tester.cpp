#include "Calendar2016.h"
#include "FileOperator.h"
#include "DataOperator.h"
#include "HistogramH.h"
#include "InputValidation.h"
#include "Data.h"    // const declarations
#include <fstream>


void initialDailySpendFile();

void main(){

	//initialDailySpendFile();
	fstream file;
	file.open("DailySpend.txt", ios::in);
	loadDailySpend(file, dailySpend, DAY366);
	file.close();

	printMontlyCalendar(3,dailySpend);
	printMontlyCalendar(4, dailySpend);
	printMontlyCalendar(5, dailySpend);

	//load entries from file
	ifstream dataFile;
	dataFile.open(DATA_FILE_NAME[3]);
	numOfEntries = loadMonthData(dataFile, monthBudget, dayArr, cataCodeArr, amountArr, CAP);
	cout << "\n\n Num of entries " << numOfEntries << "\n";
	printMonthDataArrays(monthBudget, dayArr, cataCodeArr, amountArr, numOfEntries, cout);
	dataFile.close();

	//add an entrie
	addEntry(dayArr, cataCodeArr, amountArr, numOfEntries, CAP, 29, 1, 10);
	printMonthDataArrays(monthBudget, dayArr, cataCodeArr, amountArr, numOfEntries, cout);


	// calculate daily spend
	initDailySum(dailySumArr, MAX_DAYS_IN_MONTH);
	calcDailySum(dayArr, amountArr, numOfEntries, dailySumArr, MAX_DAYS_IN_MONTH);
	printDailySum(dailySumArr, NUM_OF_DAYS_MONTH[3]);

	//update dailyspend array 
	firstDayOfMonthYearIndex = firstDayOfMonthInYear(4);
	for (int i = firstDayOfMonthYearIndex; i < firstDayOfMonthYearIndex + NUM_OF_DAYS_MONTH[3]; ++i){
		dailySpend[i] = dailySumArr[i - firstDayOfMonthYearIndex];
	}

	//update dailyspend file
	fstream dailySpendfile;
	dailySpendfile.open("DailySpend.txt", ios::out);
	writeDailySpend(dailySpendfile, dailySpend, NUM_OF_DAYS_MONTH[3]);
	dailySpendfile.close();

	//reload dailyspend file
	dailySpendfile.open("DailySpend.txt", ios::in);
	loadDailySpend(dailySpendfile, dailySpend, NUM_OF_DAYS_MONTH[3]);
	dailySpendfile.close();
	
	//reprint calendar.
	printMontlyCalendar(3, dailySpend);
	printMontlyCalendar(4, dailySpend);
	printMontlyCalendar(5, dailySpend);


	initCataSum(catagorySumArr, NUM_OF_CATAGORY);
	calcCataSum(cataCodeArr, amountArr, numOfEntries, catagorySumArr, NUM_OF_CATAGORY);
	printDailySum(catagorySumArr, NUM_OF_CATAGORY);

	printHistogramH(catagorySumArr, 4, 10);

	cout << "\n\n";
	system("pause");

}

void initialDailySpendFile(){
	ofstream file;
	file.open("DailySpend.txt", ios::out | ios::trunc);

	for (int i = 1; i <= 366; ++i){
		file << 0 <<" ";
	}

	file.close();
}