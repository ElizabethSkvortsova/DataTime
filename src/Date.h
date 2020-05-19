#pragma once
/* File  Date.h
Realization of Date class(Task 26)
Done by Skvortsova Yelyzaveta 
Date 18.05.2020 */

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

extern int DaysOfTheMonth[12]; //Supporting array of max amount of days of month
extern std::string MonthNames[]; //Supporting array of names of month
extern std::string DayNames[]; //Supporting array of names of day

struct Month {
	int index; // index of month
	std::string name; // name of month
	int days; // number of days in the month
}; //helper to store month in Date class


class Date
{
protected:
	int year;
	Month month;
	int day;

public:
	Date(); // trivial constructor
	Date(int year, int month, int day); // constructor of date
	Date(const Date& D); //copy contructor
	void init__Date(int year, int month, int day);// Supporting "constructor"
	void edit_date(Date& D); //Supporting for adding/subtracting days, which edit date

	int get_day();

	friend std::ostream& operator<<(std::ostream& output, Date& D); //function for output to console
	friend std::istream& operator>>(std::istream& input, Date& D); //function for input from console
	friend std::ofstream& operator<<(std::ofstream& output, Date& D); //function for output to file
	friend std::ifstream& operator>>(std::ifstream& input, Date& D); //function for input from file


	Date next(); // Next day of the date
	Date previous(); // Previous day of the date

	/* comparing functions */ 
	friend bool operator==(Date& D1, Date& D2);
	friend bool operator!=(Date& D1, Date& D2);
	friend bool operator<(Date& D1, Date& D2);
	friend bool operator>(Date& D1, Date& D2);
	friend bool operator<=(Date& D1, Date& D2);
	friend bool operator>=(Date& D1, Date& D2);
	

	std::string week_day(); // Name of weekday

	Date add_days(int days); // Add number of days
	Date subtract_days(int days); // Subtract number of days
	
	int days_from_beginning(); // Amount of days from 01.01.0000 to the given date
	friend int days_between(Date& D1, Date& D2);//Days between two given dates
	
	//math functions
	Date operator+(Date& D);
	Date operator-(Date& D);

	~Date();
};

