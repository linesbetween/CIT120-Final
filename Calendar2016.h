// Print monthly calendar of 2016 
// Calendar2016.h
// Hanfei Xu
// May 02 2016

#ifndef CALENDAR_H
#define CALENDAR_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string MONTH_NAME[] = { "January", "February", "March", "April", "May", "June", "July",
						"Auguest", "September", "October", "November", "December" };
const string WEEKDAY_NAME[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
const int NUM_OF_DAYS_MONTH[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

const int OFFSET_DAY[] = { 5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; // offset from Sunday for first day of each month

// get month number (1-12)
int firstDayOfMonthInYear(int month);
// return first day of each month's INDEX in calendarDay array 

// get month number (1-12) and day (1-31)
int getDayOfYear(int month, int day); 
// return INDEX in calendarDay array

// get month number (1-12) //ONLY for 2016
void printYearlyCalendar(int month, const double dailySpend[]);

void printMonthlyCalendar(int month, const double dailySumArr[]);

void printMonthlyCalendar(int month, const double dailySumArr[]){
	const int WID_COL = 4, WID_NUM = 7;
	int offset = OFFSET_DAY[month - 1];
	int daysInMonth = NUM_OF_DAYS_MONTH[month - 1];

	cout << "\n\n\t\t\t\t\t" << MONTH_NAME[month - 1] << "    2016 \n\n";

	//print table title 
	cout << left;
	for (int i = 1; i <= 7; ++i){
		cout << setw(WID_COL + WID_NUM + 2) << WEEKDAY_NAME[i - 1];
		//cout << setw(WID_NUM) << char(251);
	}
	cout << "\n";

	//print days 
	for (int i = 1; i <= (daysInMonth + offset); ++i){
		if (i <= offset)
			cout << setw(WID_COL + WID_NUM + 2) << "";

		else{
			cout << "|" << setw(WID_COL) << i - offset << "$" << setw(WID_NUM) << dailySumArr[i-offset-1];
			if (i % 7 == 0)
				cout << "\n";
		}
	}

}

void printYearlyCalendar(int month, const double dailySpend[]){ 
	const int WID_COL = 4, WID_NUM = 7;
	int offset = OFFSET_DAY[month - 1];
	int daysInMonth = NUM_OF_DAYS_MONTH[month - 1];
	int dayOfYear;
	
	cout << "\n\n\t\t\t\t\t" << MONTH_NAME[month - 1] << "    2016 \n\n";

	//print table title 
	cout << left;
	for (int i = 1; i <= 7; ++i){
		cout << setw(WID_COL + WID_NUM + 2) << WEEKDAY_NAME[i - 1];
		//cout << setw(WID_NUM) << char(251);
	}
	cout << "\n";

	//print days 
	for (int i = 1; i <= (daysInMonth + offset); ++i){
		if (i <= offset)
			cout << setw(WID_COL + WID_NUM + 2) << "";
		
		else{
			dayOfYear = getDayOfYear(month, i - offset);
			cout <<"|"<< setw(WID_COL) << i - offset << "$" << setw(WID_NUM) << dailySpend[dayOfYear] ;
			if (i % 7 == 0)
				cout << "\n";
		}
	}
}


int firstDayOfMonthInYear(int month){

	int position = 0;
	for (int i = 1; i < month; ++i){
		position += NUM_OF_DAYS_MONTH[i];
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