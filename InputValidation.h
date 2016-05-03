#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <iostream>
#include <string>
using namespace std;

double getDbNumberic();
double getDbGreater(double min);
int getInt();
int getIntGreater(int min);
int getIntRange(int min, int max);

double getDbNumberic(){  // done
	double num;

	while (!(cin >> num)){
		cout << "\t Input must be a number. Try again: ";
		cin.clear();
		cin.ignore(80, '\n');
	}
	cin.ignore(80, '\n');

	return num;
}

double getDbGreater(double min){   // done
	double num = getDbNumberic();
	while (num <= min){
		cout << "\t number must be more than " << min << ". Try again: ";
		num = getDbNumberic();
	}

	return num;
}

int getInt(){   // done
	double num = getDbNumberic();
	while (int(num) != num){
		cout << "\t Input must be whole number. Try again: ";
		num = getDbNumberic();
	}

	return int(num);
}

int getIntGreater(int min){ // done
	int num = getInt();
	while (num <= min){
		cout << "\t number must be more than " << min << ". Try again: ";
		num = getInt();
	}

	return num;
}


int getIntRange(int min, int max){  // done
	int num = getInt();

	while (num < min || num > max){
		cout << "\t Input has to be between"
			<< min << " and "<< max
			<< ". Please try again: ";
		num = getInt();
	}

	return num;
}


#endif