#pragma once
/* File  Time.h
Realization of Date class(Task 26)
Done by Skvortsova Yelyzaveta
Date 18.05.2020*/
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Date.h"

class Time 
{
protected:
	int day;
	int hours;
	int minutes;
	int seconds;

public:
	Time(); // trivial constructor
	Time(int day, int hours, int minutes, int seconds); // constuctor
	Time(const Time& T); //copy contructor

	friend std::ostream& operator<<(std::ostream& output, Time& T); //function for output to console
	friend std::istream& operator>>(std::istream& input, Time& T); //function for input from console
	friend std::ofstream& operator<<(std::ofstream& output, Time& T); //function for output to file
	friend std::ifstream& operator>>(std::ifstream& input, Time& T); //function for input from file

	/* comparing functions */
	friend bool operator==(Time& T1, Time& T2);
	friend bool operator!=(Time& T1, Time& T2);
	friend bool operator<(Time& T1, Time& T2);
	friend bool operator>(Time& T1, Time& T2);
	friend bool operator<=(Time& T1, Time& T2);
	friend bool operator>=(Time& T1, Time& T2);

	int amount_days(); //Give amount of days in this time
	
	

	//Math functions
	Time operator+(Time& T);
	Time operator-(Time& T);
	Time operator*(int number);
	Time operator/(int number);

    friend Date add_date(Date& D, Time& T); // Add date and time
	friend Date subtract_date(Date& D, Time& T); // Subtract date and time

	~Time();
};

Time convert_date(Date& D); //Here we transform from Date to Time