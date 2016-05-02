//Data fields  
//Data.h
//Hanfei Xu
//May 02 2016

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
using namespace std;


/*******************Data loaded from files*/
const int CAP = 150; // Capacity of each month's file.
//store user date entries, loaded from each month's file
int dayArr[CAP];
int cataCodeArr[CAP];
double amountArr[CAP];
// loaded from the same file as user data entries, at beginning of file
double monthBudget;


const int DAY366 = 366; // 366 days in 2016
//int dailyChecker[DAY366]; // checkers if each day has data entry, for display on calendar, loaded from another file
double dailySpend[DAY366];// store each day's spending, for display on calendar, loaded from another file 

/*********************Data created at run time*/
const string DATA_FILE_NAME[] = { 
	"JanuaryData.txt", 
	"FebruaryData.txt", "MarchData.txt", "AprilData.txt", "MayData.txt",
"JuneData.txt", "JulyData.txt", "AuguestData.txt", "SeptemberData.txt", "OctoberData.txt",
"NovemberData.txt", "DecemberData.txt" };

int currentMonth, currentDay;
double currentBalance;
int numOfEntries;
int firstDayOfMonthYearIndex;

const int MAX_DAYS_IN_MONTH = 31;
double dailySumArr[MAX_DAYS_IN_MONTH]; 
const int NUM_OF_CATAGORY = 4;
double catagorySumArr[NUM_OF_CATAGORY];

// for each entry
int entryDate;
double entryAmount;




#endif