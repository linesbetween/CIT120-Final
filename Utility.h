#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Data.h"
using namespace std;

string monthName[] = { "January", "February", "March", "April", "May", "June", "July",
						"Auguest", "September", "October", "November", "December" };
string weekdayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
int numOfDaysInMonth[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int offsetMonth[] = { 5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; // offset from Sunday for first day of each month

int firstDayOfMonthInYear(int month);// first day of each month's INDEX in calendarDay array 
int getDayOfYear(int month, int day);
void printMontlyCalendar(int month);

void printMontlyCalendar(int month){ //ONLY for 2016
	const int WID_COL = 6, WID_SIGN = 3;
	int offset = offsetMonth[month - 1];  
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
	dayInYear += day;

	return dayInYear;
}

#endif