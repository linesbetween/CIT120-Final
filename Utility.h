//Print monthly calendar of 2016 
//Utility.h
//Hanfei Xu
//May 02 2016

#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Data.h"
using namespace std;

const string monthName[] = { "January", "February", "March", "April", "May", "June", "July",
						"Auguest", "September", "October", "November", "December" };
const string weekdayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
const int numOfDaysInMonth[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

const int offsetInMonth[] = { 5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; // offset from Sunday for first day of each month

// get month number (1-12)
int firstDayOfMonthInYear(int month);
// return first day of each month's INDEX in calendarDay array 

// get month number (1-12) and day (1-31)
int getDayOfYear(int month, int day); 
// return INDEX in calendarDay array

// get month number (1-12) //ONLY for 2016
void printMontlyCalendar(int month);


void printMontlyCalendar(int month){ 
	const int WID_COL = 6, WID_SIGN = 3;
	int offset = offsetInMonth[month - 1];  
	int daysInMonth = numOfDaysInMonth[month - 1];
	int dayOfYear;
	
	cout <<"\n\n\t\t\t"<< monthName[month - 1] << "    2016 \n\n";

	//print table title 
	cout << left;
	for (int i = 1; i <= 7; ++i){
		cout << setw(WID_COL + WID_SIGN) << weekdayName[i - 1];
		//cout << setw(WID_SIGN) << char(251);
	}
	cout << "\n";

	//print days 
	for (int i = 1; i <= (daysInMonth + offset); ++i){
		if (i <= offset)
			cout << setw(WID_COL + WID_SIGN) << "";
		
		else{
			dayOfYear = getDayOfYear(month, i - offset);
			cout << setw(WID_COL) << i - offset << setw(WID_SIGN) << (calendarDay[dayOfYear] == 1 ? char(251) : ' '); 
			if (i % 7 == 0)
				cout << "\n";
		}
	}
}


int firstDayOfMonthInYear(int month){

	int position = 0;
	for (int i = 1; i < month; ++i){
		position += numOfDaysInMonth[i];
	}

	return position;
}


int getDayOfYear(int month, int day){
	int dayInYear = 0;

	dayInYear += firstDayOfMonthInYear(month);
	dayInYear += day-1;

	return dayInYear;
}


#endif