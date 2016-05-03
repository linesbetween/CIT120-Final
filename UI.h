// Print user interface including banner, menu
// UI.h
// Hanfei Xu
// May 02 2016

#ifndef UI_H
#define UI_H
#include <iostream>
#include <iomanip>
#include <string>
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
		<< " 1. Add Entry  \n"
		<< " 2. Change budget \n"
		<< " 3. Display curret month overview \n"
		<< " 4. Create current month report \n"
		<< " 5. Display/report previous months \n"
		<< " 6. Exit \n"
		<< "\n Please choose number option: ";
}

#endif
