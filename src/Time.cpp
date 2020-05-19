/* File  Time.cpp
Realization of Date class functions(Task 26)
Done by Skvortsova Yelyzaveta 
Date 18.05.2020 */


#include "Time.h"


// trivial constructor
Time::Time() {
	this->day = 0;
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
} 
// constuctor
Time::Time(int day, int hours, int minutes, int seconds) {
	if (day >= 0) {
		this->day = day;
	}
	else {
		std::string error = "Not suitable day";
		throw error;
	}
	if (hours < 24 && hours >= 0) { 
		this->hours = hours; 
	}
	else {
		std::string error = "Not suitable hour";
		throw error;
	}
	if (minutes < 60 && minutes >= 0) {
		this->minutes = minutes;
	}
	else {
		std::string error = "Not suitable minutes";
		throw error;
	}
	if (seconds < 60 && seconds >= 0) {
		this->seconds = seconds;
	}
	else {
		std::string error = "Not suitable seconds";
		throw error;
	}
} 
//copy contructor
Time::Time(const Time& T) {
	this->day = T.day;
	this->hours = T.hours;
	this->minutes = T.minutes;
	this->seconds = T.seconds;
} 

//function for output to console
std::ostream& operator<<(std::ostream& output, Time& T) {
	output << T.day << "." << T.hours << "." << T.minutes << "." << T.seconds;
	return output;
} 
//function for input from console
std::istream& operator>>(std::istream& input, Time& T) {
	std::cout << "Day: ";
	input >> T.day;
	if (T.day < 0) {
		std::string error = "Not suitable day";
		throw error;
	}
	std::cout << "Hours: ";
	input >> T.hours;
	if (T.hours < 0 || T.hours >= 24) {
		std::string error = "Not suitable hour";
		throw error;
	}
	std::cout << "Minutes: ";
	input >> T.minutes;
	if (T.minutes < 0 || T.minutes >= 60) {
		std::string error = "Not suitable minutes";
		throw error;
	}
	std::cout << "Seconds: ";
	input >> T.seconds;
	if (T.seconds < 0 || T.seconds >= 60) {
		std::string error = "Not suitable seconds";
		throw error;
	}

} 
//function for output to file
std::ofstream& operator<<(std::ofstream& output, Time& T) {
	if (output.is_open()) {
		output << T.day << "." << T.hours << "." << T.minutes << "." << T.seconds;
		return output;
	}
	else {
		throw std::runtime_error("Unable to open file");
	}
} 
//function for input from file
std::ifstream& operator>>(std::ifstream& input, Time& T) {
	std::string day;
	std::string hours;
	std::string minutes;
	std::string seconds;
	if (input.is_open()) {
		if (std::getline(input, day, '.') && std::getline(input, hours, '.') && std::getline(input, minutes, '.') && std::getline(input, seconds)) {
			T.day = std::stoi(day);
			if (T.day < 0) {
				std::string error = "Not suitable day";
				throw error;
			}
			T.hours = std::stoi(hours);
			if (T.hours < 0 || T.hours >= 24) {
				std::string error = "Not suitable hour";
				throw error;
			}
			T.minutes = std::stoi(minutes);
			if (T.minutes < 0 || T.minutes >= 60) {
				std::string error = "Not suitable minutes";
				throw error;
			}
			T.seconds = std::stoi(seconds);
			if (T.seconds < 0 || T.seconds >= 60) {
				std::string error = "Not suitable seconds";
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

/* comparing functions */
bool operator==(Time& T1, Time& T2) {
	return (T1.day == T2.day && T1.hours == T2.hours && T1.minutes == T2.minutes && T1.seconds == T2.seconds);
}
bool operator!=(Time& T1, Time& T2) {
	return (T1.day != T2.day || T1.hours != T2.hours || T1.minutes != T2.minutes || T1.seconds != T2.seconds);
}
bool operator<(Time& T1, Time& T2) {
	if (T1.day < T2.day) {
		return true;
	}
	else if (T1.day > T2.day) {
		return false;
	}
	else {
		if (T1.hours < T2.hours) {
			return true;
		}
		else if (T1.hours > T2.hours) {
			return false;
		}
		else {
			if (T1.minutes < T2.minutes) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
bool operator>(Time& T1, Time& T2) {
	if (T1.day > T2.day) {
		return true;
	}
	else if (T1.day < T2.day) {
		return false;
	}
	else {
		if (T1.hours > T2.hours) {
			return true;
		}
		else if (T1.hours < T2.hours) {
			return false;
		}
		else {
			if (T1.minutes > T2.minutes) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
bool operator>=(Time& T1, Time& T2) {
	if (T1.day > T2.day) {
		return true;
	}
	else if (T1.day < T2.day) {
		return false;
	}
	else {
		if (T1.hours > T2.hours) {
			return true;
		}
		else if (T1.hours < T2.hours) {
			return false;
		}
		else {
			if (T1.minutes >= T2.minutes) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
bool operator<=(Time& T1, Time& T2) {
	if (T1.day < T2.day) {
		return true;
	}
	else if (T1.day > T2.day) {
		return false;
	}
	else {
		if (T1.hours < T2.hours) {
			return true;
		}
		else if (T1.hours > T2.hours) {
			return false;
		}
		else {
			if (T1.minutes <= T2.minutes) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

//Give amount of days in this time
int Time::amount_days() {
	return day;
}

//Here we transform from Date to Time
Time convert_date(Date& D) {
	return Time(D.get_day(), 0, 0, 0);
}

//Math functions
Time Time::operator+(Time& T) {
	int day_result = 0;
	int hour_result = 0;
	int minutes_result = 0;
	int seconds_result = 0;

	seconds_result = seconds + T.seconds;
	while (seconds_result >= 60) {
		minutes_result++;
		seconds_result -= 60;
	}
	minutes_result += minutes + T.minutes;
	while (minutes_result >= 60) {
		hour_result++;
		minutes_result -= 60;
	}
	hour_result += hours + T.hours;
	while (hour_result >= 24) {
		day_result++;
		hour_result -= 24;
	}
	day_result += day + T.day;
	return Time(day_result, hour_result, minutes_result, seconds_result);
}
Time Time::operator-(Time& T) {
	Time T1 = Time(day, hours, minutes, seconds);
	if (T1 == T) {
		return Time();
	}
	else if (T1 < T) {
		std::string error = "Negative Time";
		throw error;
	}
	else {
		int day_result = 0;
		int hour_result = 0;
		int minutes_result = 0;
		int seconds_result = 0;

		seconds_result = seconds - T.seconds;
		while (seconds_result < 0) {
			minutes_result--;
			seconds_result += 60;
		}
		minutes_result += minutes - T.minutes;
		while (minutes_result < 0) {
			hour_result--;
			minutes_result += 60;
		}
		hour_result += hours - T.hours;
		while (hour_result < 0) {
			day_result--;
			hour_result += 24;
		}
		day_result += day - T.day;
		return Time(day_result, hour_result, minutes_result, seconds_result);
	}
}
Time Time::operator*(int number) {
	if (number < 0) {
		std::string error = "Negative time";
		throw error;
	}
	else {
		int day_result = 0;
		int hour_result = 0;
		int minutes_result = 0;
		int seconds_result = 0;

		seconds_result = seconds * number ;
		while (seconds_result >= 60) {
			minutes_result++;
			seconds_result -= 60;
		}
		minutes_result += minutes * number;
		while (minutes_result >= 60) {
			hour_result++;
			minutes_result -= 60;
		}
		hour_result += hours * number;
		while (hour_result >= 24) {
			day_result++;
			hour_result -= 24;
		}
		day_result += day * number;
		return Time(day_result, hour_result, minutes_result, seconds_result);
	}
}
Time Time::operator/(int number) {
	if (number < 0) {
		std::string error = "Negative time";
		throw error;
	}
	else {
		int day_result = 0;
		int hour_result = 0;
		int minutes_result = 0;
		int seconds_result = 0;

		day_result = day / number;
		hour_result += (day % number) * 24;
		hour_result += hours / number;
		minutes_result += (hours % number) * 60;
		minutes_result += minutes / number;
		seconds_result += (minutes % number) * 60;
		seconds_result += seconds / number;
		while (seconds_result >= 60) {
			minutes_result++;
			seconds_result -= 60;
		}
		while (minutes_result >= 60) {
			hour_result++;
			minutes_result -= 60;
		}
		while (hour_result >= 24) {
			day_result++;
			hour_result -= 24;
		}
		return Time(day_result, hour_result, minutes_result, seconds_result);
	}
}

// Add date and time
Date add_date(Date& D, Time& T) {
	return D.add_days(T.day);
} 
// Subtract date and time
Date subtract_date(Date& D, Time& T) {
	return D.subtract_days(T.day);
} 

Time::~Time() {}