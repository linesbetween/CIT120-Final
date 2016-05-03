// Print user interface including banner, menu, handle interaction with menu
// UI.h
// Hanfei Xu
// May 02 2016

#ifndef UI_H
#define UI_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Calendar2016.h"
#include "InputValidation.h"
using namespace std;

//Banner
void printBanner(string content[], int maxLength);
void printCenterLine(string content, int maxLength);

//Main menu
void dispMainMenu();

void printBanner(string content[], int maxLength){ 
	int i = 0;
	while (content[i] != ""){
		printCenterLine(content[i], maxLength);
		++i;
	}
	cout << "\n\n";
}

void printCenterLine(string content, int maxLength){
	cout << "\n" << setw((maxLength - content.length()) / 2 + content.length()) << content;
}

void dispMainMenu(){
	cout
		<< "\n\n Main Menu \n"
		<< " 1. Add spending to any day of current month  \n"
		<< " 2. Change budget of current month\n"
		<< " 3. Display curret month overview \n"
		<< " 4. Create current month report \n"
		<< " 5. Display/report previous months \n"
		<< " 6. Exit \n"
		<< "\n Please choose number option: ";
}

//Choice 1 add entry to day in current month
void getNewEntry(int month, int& day, int& code, double& amount){
	cout << "\nPlease input date ";
	day = getIntRange(1, NUM_OF_DAYS_MONTH[month - 1]);
	cout
		<< "\nPlease input code (1-4) of spending type \n"
		<< "1. Daily expense: like food, transportation \n"
		<< "2. Occasional spending: like social, hobby, purchase  \n"
		<< "3. Fixed bills: like rent, mortgage, utility \n"
		<< "4. Investment: like stock, education, childcare \n";
	code = getIntRange(1, 4);
	cout << "\nPlease input amount "; 
	amount = getIntGreater(0); // no limit here but for better report display, please keep under 500
}

//Choice 2 change budget
double getNewBugdet(){
	cout << "\nWhat's the new budget? ";
	return getDbGreater(0);
}

//Choice 6 save & exit



#endif
