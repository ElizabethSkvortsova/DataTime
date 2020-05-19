/* File  Date.cpp
Realization of Date classs functions(Task 26)
Done by Skvortsova Yelyzaveta
Date 18.05.2020 */

#include "Date.h"
//Supporting array of max amount of days of month
int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
//Supporting array of names of month
std::string month_names[12] = {"January", "February", "March", "April", "May", "June",
							 "July", "August", "September", "October", "November", "December"};
//Supporting array of names of day
std::string days_of_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


/*Constuctors and 
supporting functions*/

// trivial constructor
Date::Date()
{
	init__Date(0, 1, 1);
}
// constructor of date
Date::Date(int year, int month, int day) {
	init__Date(year, month, day);
}
//copy contructor
Date::Date(const Date& D) {
	init__Date(D.year, D.month.index, D.day);
}
// Supporting "constructor"
void Date::init__Date(int year, int month, int day) {
	// check and init year
	if (year < 0) {
		std::string error = "Not suitable year";
		throw error;
	}
	else {
		this->year = year;
	}
	// check and init month
	if (month <= 12) {
		this->month.index = month;
		this->month.name = month_names[month-1];
		this->month.days = days_in_month[month-1];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
			this->month.days++;
		}
	}
	else {
		std::string error = "Not suitable month";
		throw error;
	}
	//check and init day
	if (day > this->month.days) {
		std::string error = "Not suitable day";
		throw error;
	}
	else {
		this->day = day;
	}
	
}
//Supporting for adding/subtracting days, which edit date
void Date::edit_date(Date& D) {
	int index = D.month.index;
	while (D.day > D.month.days) {
		D.day -= D.month.days;
		D.month.index++;
		index++;
		if (D.month.index == 13) {
			D.month.index = 1;
			D.year++;
			index = 1;
		}
		D.month.days = days_in_month[index - 1];
		if (D.month.index == 2 && ((D.year % 4 == 0 && D.year % 100 != 0) || D.year % 400 == 0))
		{
			D.month.days++;
		}
	}
	while (D.day <= 0) {
		D.month.index--;
		index--;
		if (D.month.index == 0) {
			D.year--;
			D.month.index = 12;
			index = 12;
		}
		D.month.days = days_in_month[index - 1];
		if (D.month.index == 2 && !(D.year % 400 % 4)) {
			D.month.days++;
		}
		D.day += D.month.days;
	}
}

int Date::get_day() {
	return day;
}

/*Functions of input/output
from/to consloe and file*/
std::ostream& operator<<(std::ostream& output, Date& D) {
	if (D.month.index < 10) {
		output << D.year << ".0" << D.month.index << "." << D.day << " or ";
	}
	else {
		output << D.year << "." << D.month.index << "." << D.day << " or ";
	}
	output << D.day << " " << D.month.name << " " << D.year;
	return output;
}
std::istream& operator>>(std::istream& input, Date& D) {
	std::cout << "Year: ";
	input >> D.year;
	if (D.year < 0) {
		std::string error = "Not suitable year";
		throw error;
	}
	std::cout << "Month: ";
	input >> D.month.index;
	if (D.month.index <= 12) {
		D.month.name = month_names[D.month.index-1];
		D.month.days = days_in_month[D.month.index-1];
		if (D.month.index == 2 && ((D.year % 4 == 0 && D.year % 100 != 0) || D.year % 400 == 0)) {
			D.month.days++;
		}
	}
	else {
		std::string error = "Not suitable month";
		throw error;
	}
	std::cout << "Day: ";
	input >> D.day;
	if (D.day > D.month.days) {
		std::string error = "Not suitable day";
		throw error;
	}
	return input;
}
std::ofstream& operator<<(std::ofstream& output, Date& D) {
	if (output.is_open()) {
		if (D.month.index < 10) {
			output << D.year << ".0" << D.month.index << "." << D.day << " or ";
		}
		else {
			output << D.year << "." << D.month.index << "." << D.day << " or ";
		}
		output << D.day << " " << D.month.name << " " << D.year;
		return output;
	}
	else {
		throw std::runtime_error("Unable to open file");
	}
}
std::ifstream& operator>>(std::ifstream& input, Date& D) {
	std::string year;
	std::string month;
	std::string day;
	if (input.is_open()) {
		if (std::getline(input, year, '.') && std::getline(input, month, '.') && std::getline(input, day)) {
			D.year = std::stoi(year);
			if (D.year < 0) {
				std::string error = "Not suitable year";
				throw error;
			}
			D.month.index = std::stoi(month);
			if (D.month.index <= 12) {
				D.month.name = month_names[D.month.index-1];
				D.month.days = days_in_month[D.month.index-1];
				if (D.month.index == 2 && (((D.year % 4 == 0) && (D.year % 100 != 0)) || (D.year % 400 == 0))) {
					D.month.days++;
				}
			}
			else {
				std::string error = "Not suitable month";
				throw error;
			}
			D.day = std::stoi(day);
			if (D.day > D.month.days) {
				std::string error = "Not suitable day";
				throw error;
			}
		}
		else {
			std::string error = "Wrong input";
			throw error;
		}
	}
	else {
		throw std::runtime_error("Unable to open file");
	}
}

/*Functions which give 
next/previous dates*/
Date Date::next() {
	if (day == month.days) {
		if (month.index == 12) {
			return Date(year+1, 1, 1);
		}
		else {
			return Date(year, month.index+1, 1);
		}
	}
	else {
		return Date(year, month.index, day+1);
	}
}
Date Date::previous() {
	if (day == 1) {
		if (month.index == 1) {
			return Date(year-1, 12, 31);
		}
		else {
			return Date(year, month.index-1, 1);
		}
	}
	else {
		return Date(year, month.index, day-1);
	}
}

/*Bool operations, which
compare dates*/
bool operator==(Date& D1, Date& D2) {
	return (D1.day == D2.day && D1.month.index == D2.month.index && D1.year == D2.year);
}
bool operator!=(Date& D1, Date& D2) {
	return (D1.day != D2.day || D1.month.index != D2.month.index || D1.year != D2.year);
}
bool operator<(Date& D1, Date& D2) {
	if (D1.year < D2.year) {
		return true;
	}
	else if (D1.year > D2.year) {
		return false;
	}
	else {
		if (D1.month.index < D2.month.index) {
			return true;
		}
		else if (D1.month.index > D2.month.index) {
			return false;
		}
		else {
			if (D1.day < D2.day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
bool operator>(Date& D1, Date& D2) {
	if (D1.year < D2.year) {
		return false;
	}
	else if (D1.year > D2.year) {
		return true;
	}
	else {
		if (D1.month.index < D2.month.index) {
			return false;
		}
		else if (D1.month.index > D2.month.index) {
			return true;
		}
		else {
			if (D1.day <= D2.day) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}
bool operator<=(Date& D1, Date& D2) {
	if (D1.year < D2.year) {
		return true;
	}
	else if (D1.year > D2.year) {
		return false;
	}
	else {
		if (D1.month.index < D2.month.index) {
			return true;
		}
		else if (D1.month.index > D2.month.index) {
			return false;
		}
		else {
			if (D1.day <= D2.day) {
				return true;
			}
			else{
				return false;
			}
		}
	}
}
bool operator>=(Date& D1, Date& D2){
	if (D1.year < D2.year) {
		return false;
	}
	else if (D1.year > D2.year) {
		return true;
	}
	else {
		if (D1.month.index < D2.month.index) {
			return false;
		}
		else if (D1.month.index > D2.month.index) {
			return true;
		}
		else {
			if (D1.day < D2.day) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}

// Give name of weekday
std::string Date::week_day() {
	int a = (14 - month.index) / 12;
	int y = year - a;
	int m = month.index + 12 * a - 2;
	return days_of_week[(day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7];
}

/*Functions which give/subtract
given amount of days*/
Date Date::add_days(int days) {
	Date Help(year, month.index, day);
	Help.day += days;
	edit_date(Help);
	return Help;
}
Date Date::subtract_days(int days) {
	Date Help(year, month.index, day);
	Help.day -= days;
	edit_date(Help);
	return Help;
}

/*Functions which show days from 01.01.0000
or between two dates*/
int Date::days_from_beginning() {
	int year_help = year;
	int month_help = month.index;
	int day_help = day;
	if (month.index < 3) {
		year_help--;
		month_help += 12;
	}
	return ((year_help + 1) * 365 + year_help / 4 - year_help / 100 + year_help / 400 + (153 * month_help - 457) / 5 + day_help - 306);
}
int days_between(Date& D1, Date& D2) {
	int res1 = D1.days_from_beginning();
	int res2 = D2.days_from_beginning();
	return(abs(res1 - res2));
}

/*Functions which add/subtract
dates*/
Date Date::operator+(Date& D2) {
	Date D1 = Date(year, month.index, day);
	int difference = days_between(D1, D2);
	Date result;
	if (D1 <= D2){
		result = D2.add_days(difference);
		return	result;
	}
	else {
		result = D1.add_days(difference);
		return	result;
	}
}
Date Date::operator-(Date& D2) {
	Date D1 = Date(year, month.index, day);
	int difference = days_between(D1, D2);
	Date result;
	if (D1 >= D2) {
		result = D2.subtract_days(difference);
		return	result;
	}
	else {
		result = D1.subtract_days(difference);
		return	result;
	}
}

Date::~Date()
{
}
