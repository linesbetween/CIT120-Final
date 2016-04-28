#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
using namespace std;

const int CAP = 1000; // 3 entry per day?  need more?
const int DAY366 = 366; // for each day on calendar

string date[CAP];
int costGain[CAP], catCode[CAP];
double amount[CAP];

int calendarDay[DAY366];// store if each day has data entry, for display on calendar

#endif