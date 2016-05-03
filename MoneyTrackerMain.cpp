//
// MoneyTrackerMain.cpp
// Hanfei Xu
// May 02 2016

#include "UI.h"
#include "Calendar2016.h"
#include "FileOperator.h"
#include "DataOperator.h"
#include "HistogramH.h"
#include "InputValidation.h"
#include <fstream>


void main(){
	////////////////Data fields //////////////////////////////////////////////
	/*******************Data loaded from files*/
	const int CAP = 150; // Capacity of each month's file.
	//store user date entries, loaded from each month's file
	int dayArr[CAP];
	int cataCodeArr[CAP];
	double amountArr[CAP];
	// loaded from the same file as user data entries, at beginning of file
	double monthBudget;

	// store each day's spending, for display on calendar, loaded from another file
	const int DAY366 = 366; 
	double dailySpendInYear[DAY366]; 

	/*********************Data created at run time*/
	const string DATA_FILE_NAME[] = {"JanuaryData.txt", "FebruaryData.txt", "MarchData.txt", "AprilData.txt",
		"MayData.txt", "JuneData.txt", "JulyData.txt", "AuguestData.txt", "SeptemberData.txt", "OctoberData.txt",
		"NovemberData.txt", "DecemberData.txt" };

	int choice;
	int currentMonth, currentDay;
	int entryDate;
	double entryAmount;
	double budget, currentBalance, currentTotalSpend;
	int numOfEntries;
	int firstDayOfMonthYearIndex;

	const int MAX_DAYS_IN_MONTH = 31;
	double dailySumArr[MAX_DAYS_IN_MONTH];
	const int NUM_OF_CATAGORY = 4;
	double catagorySumArr[NUM_OF_CATAGORY];


	//////////////////Title & Banner////////////////////////////////////////
	system("title Where Did Your Dollar Go? by Hanfei Xu");

	const int MAX_LENGTH = 90;
	string banner[] = {
		"CIT120 Final Project",
		"Daily Spending Tracker",
		"by Hanfei Xu",
		""
	};
	printBanner(banner, MAX_LENGTH);
	
	///////////////////UI //////////////////////////////////////////////////

	printCenterLine("Welcom to your money tracker \n", MAX_LENGTH);
	printCenterLine("May I know what month this is (Input numberice month #) ?\n", MAX_LENGTH);
	for (int i = 0; i < 12; ++i){
		if (i % 6 == 0)
			cout << "\n";
		cout << i + 1 << " " << MONTH_NAME[i] << ", ";		
	}
	cout << "\n";
	currentMonth = getIntRange(1, 12);

	initDailySum(dailySumArr, MAX_DAYS_IN_MONTH);
	
	fstream monthData;
	monthData.open(DATA_FILE_NAME[currentMonth - 1], ios::in);
	if (!monthData){ // if user try to start a new month

		//create new month data file
		monthData.close();
		monthData.open(DATA_FILE_NAME[currentMonth - 1], ios::out);
		//set budget
		cout << "\nYou started a NEW month. Please set your budget (you can change that later): ";
		budget = getDbGreater(0);
		currentBalance = budget;
		numOfEntries = 0;
		monthData.close();
	}
	else { // if user stays in old month
		//load budget, entries,from file
		numOfEntries = loadMonthData(monthData, budget, dayArr, cataCodeArr, amountArr, CAP);
		monthData.close();

		//calculate daily spending, totalspending, balance
		calcDailySum(dayArr, amountArr, numOfEntries, dailySumArr, MAX_DAYS_IN_MONTH);
		currentTotalSpend = calcTotalSpending(dailySumArr, MAX_DAYS_IN_MONTH);
		currentBalance = budget - currentTotalSpend;

		// Print monthly overview
		printMonthlyCalendar(currentMonth, dailySumArr);
		cout << "\n"
			<< "Budget: " << budget << "\n"
			<< "Balance: " << currentBalance << "\n\n";
		
	}

	dispMainMenu();
	choice = getIntRange(1, 6);














	cout << "\n\n";
	system("pause");
}

void mainMenu(){
	
}