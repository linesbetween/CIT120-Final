//Print horizontal histogram of daily spending or catagory spending
//StickGraph.h
//Hanfei Xu
//May 02 2016

#ifndef HISTOGRAMH_H
#define HISTOGRAMH_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//xArr[] contains values of items (x axis), posivtive doubles; sizeX contains number items (y axis), positive int.
//xUnit is the minimun step of x. 
void printHistogramH(double xArr[], int sizeX, double xUnit, string xLabel = "", string yLabel = "");
double findMax(double xArr[], int xSize);


void printHistogramH(double xArr[], int sizeX, double xUnit, string xLabel, string yLabel ){ //TODO label, label array
	// print x axis with scale
	double maxX = findMax(xArr, sizeX);

	cout << setw(4) << left << "";
	for (int i = 0; i <= maxX / xUnit + 1; ++i){
		if (i % 5 == 0)
			cout << setw(5) << left << i*xUnit;
	}
	cout << "\n" 
		 << setw(4) << left << "";;
	for (int i = 0; i <= maxX / xUnit + 1; ++i) 
		cout << "|";
	cout << xLabel<<"\n";

	// print histogram & y axis
	for (int j = 0; j < sizeX; ++j){
		cout <<setw(4)<<left<< j+1 <<"|";
		for (int i = 1; i <= xArr[j] / xUnit; ++i){
			cout << char(178); //TODO multiline
		}
		cout << "\n"<<setw(5)<<right<<"|"<<"\n";
	}
	
	cout << yLabel 
		 << "\n\n";
}

double findMax(double xArr[], int xSize){
	double max = xArr[0];

	for (int i = 1; i < xSize; ++i){
		if (max < xArr[i])
			max = xArr[i];
	}
		
	return max;
}

#endif