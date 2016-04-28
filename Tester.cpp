#include "Utility.h"
#include "Data.h"
#include <fstream>
void main(){

	/*
	// initialize test numbers in 
	ofstream file;
	file.open("RecordTrack.txt", ios::out);

	for (int i = 0; i < 365; ++i){
		file << i % 2 <<" ";
	}

	file.close();
	*/

	ifstream tracker;
	tracker.open("RecordTrack.txt", ios::in);

	for (int i = 0; i < 366; ++i){
		tracker >> calendarDay[i];
	}

	tracker.close();

	printMontlyCalendar(1);
	printMontlyCalendar(2);
	printMontlyCalendar(3);

	cout << "\n\n";
	system("pause");

}