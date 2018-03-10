#include <iostream>
#include <iomanip>
#include <functional>
#include <queue>
#include <vector>
#include <fstream>
#include "date.h"
using namespace std;

int main()
{
	int year;
	int month;
	int day;
	int base_year;
	int counter = 0;
	int total = 0;
	string filename;
	ifstream fin;
	Date output(0,0,0);
	priority_queue<Date, vector<Date>, greater<Date> > input;

	cout << "This program calculates the average day of the year given a set of birthdays.\n";
	cout << "Please enter filename: ";
	cin >> filename;

	fin.open(filename.c_str());
	
	//pushes all dates into a priority queue to sort them 
	while(fin >> year)
	{
		fin >> month;
		fin >> day;

		Date temp(year, month, day);
		input.push(temp);
	}

	fin.close();
	
	//find the base year
	if(!input.empty())
		base_year = input.top().getYear();
	
	//convert all dates into number based on the base year given to form basically a dynamic number line and then add all the numbers together while
	//calculating the number of dates there are.
	while(!input.empty())
	{
		counter++;
		total += input.top().dateToNum(base_year);
		input.pop();
	}

	//calculate the average date from the total divided by the number of dates.
	total/=counter;
	output.numToDate(total, base_year);
	cout << "The average date is " << output.getMonth() << "/" << output.getDay() << endl;
}
