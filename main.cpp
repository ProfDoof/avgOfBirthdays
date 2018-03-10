#include <iostream>
#include <iomanip>
#include <functional>
#include <queue>
#include <vector>
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
	Date output(0,0,0);
	priority_queue<Date, vector<Date>, greater<Date> > input;

	cout << "This program calculates the average day of the year given a set of birthdays.\nType -1 to stop.\n";
	cout << "Please enter date (Year Month Day) : ";
	cin >> year;

	while(year != -1)
	{
		cin >> month;
		cin >> day;

		Date temp(year, month, day);
		input.push(temp);

		cout << "Please enter date (Year Month Day) : ";
		cin >> year;

	}

	if(!input.empty())
		base_year = input.top().getYear();
	while(!input.empty())
	{
		counter++;
		total += input.top().dateToNum(base_year);
		input.pop();
	}

	cout << "1." << endl;
	total/=counter;
	output.numToDate(total, base_year);
	cout << "2." << endl;
	cout << "The average date is " << output.getYear() << "/" << output.getMonth() << "/" << output.getDay() << endl;
	cout << "Program is over" << endl;
}
