/* File  test_Date.cpp
Realization of tests for Date class functions
Done by Skvortsova Yelyzaveta
Date 18.05.2020 */

#include "../src/Date.h"

/*Test1 - Test of 
input/output from file*/
int Date_test1_in_out_file() {
	try {
		std::ifstream file("tests/Date.txt");
		std::ofstream file_result("tests/sDate_result1_in_out.txt");
		while (!file.eof()) {
			Date D;
			file >> D;
			file_result << D << "\n";
		}
		file.close();
		file_result.close();
		return 0;
	}
	catch (std::string er) {
		std::cout << er << std::endl;
		return 1;
	}
}

/*Test2 - Test of 
next/previous day*/
int Date_test2_next_prev() {
	try {
		std::ifstream file("tests/Date.txt");
		std::ofstream file_result("tests/Date_result2_next_prev.txt");
		while (!file.eof()) {
			Date D;
			file >> D;
			Date D_next = D.next();
			Date D_prev = D.previous();
			file_result << "For this date: " << D << "\nNext: " << D_next << "\nPrevious: " << D_prev;
			file_result << "\n-------------------------------------\n";
		}
		file.close();
		file_result.close();
		return 0;
	}
	catch (std::string er) {
		std::cout << er << std::endl;
		return 1;
	}
}

/*Test3 - Test of 
comparing functions*/
int Date_test3_comparing() {
	try {
		std::ifstream file("tests/Date.txt");
		std::ifstream file2("tests/Date2.txt");
		std::ofstream file_result("tests/Date_result3_comparing.txt");
		while (!file.eof() && !file2.eof()) {
			Date D;
			Date D2;
			file >> D;
			file2 >> D2;
			file_result << D << "== " << D2 << "?\n";
			if (D == D2) {
				file_result << "true\n";
			}
			else {
				file_result << "false\n";
			}
			file_result << D << "!= " << D2 << "?\n";
			if (D != D2) {
				file_result << "true\n";
			}
			else {
				file_result << "false\n";
			}
			file_result << D << "< " << D2 << "?\n";
			if (D < D2) {
				file_result << "true\n";
			}
			else {
				file_result << "false\n";
			}
			file_result << D << "<= " << D2 << "?\n";
			if (D <= D2) {
				file_result << "true\n";
			}
			else {
				file_result << "false\n";
			}
			file_result << D << "> " << D2 << "?\n";
			if (D > D2) {
				file_result << "true\n";
			}
			else {
				file_result << "false\n";
			}
			file_result << D << ">= " << D2 << "?\n";
			if (D >= D2) {
				file_result << "true\n";
			}
			else {
				file_result << "false\n";

			}

			file_result << "\n-------------------------------------\n";
		}
		file.close();
		file2.close();
		file_result.close();
		return 0;
	}
	catch (std::string er) {
		std::cout << er << std::endl;
		return 1;
	}
}

/*Test4 - Test of
math and add/subtract functions*/
int Date_test4_math() {
	try {
		std::ifstream file("tests/Date.txt");
		std::ifstream file2("tests/Date2.txt");
		std::ofstream file_result("tests/Date_result4_math.txt");
		while (!file.eof() && !file2.eof()) {
			Date D;
			Date D2;
			Date Result;
			int number = 78;
			int result = 0;
			file >> D;
			file2 >> D2;
			// Check addition of two dates
			file_result << D << " + " << D2 << " = ";
			Result = D + D2;
			file_result << Result << "\n";
			// Check subtraction of two dates
			file_result << D << " - " << D2 << " = ";
			Result = D - D2;
			file_result << Result << "\n";
			// Check addition of date and number
			file_result << D << " + " << number << " = ";
			Result = D.add_days(number);
			file_result << Result << "\n";
			// Check subtraction of date and number
			file_result << D << " - " << number << " = ";
			Result = D.subtract_days(number);
			file_result << Result << "\n";
			//Check days from the beggining
			file_result << D << " from the beginning: ";
			result = D.days_from_beginning();
			file_result << result << "\n";
			//Check days between
			file_result <<"Days between: " << D << " and " << D2;
			result = days_between(D, D2);
			file_result << result << "\n";

			file_result << "\n-------------------------------------\n";
		}
		file.close();
		file2.close();
		file_result.close();
		return 0;
	}
	catch (std::string er) {
		std::cout << er << std::endl;
		return 1;
	}
}

/*Test 5 - Test of
weekday*/
int Date_test5_weekday() {
	try {
		std::ifstream file("tests/Date.txt");
		std::ofstream file_result("tests/Date_result5_weekday.txt");
		while (!file.eof()) {
			Date D;
			file >> D;
			file_result << "For this date: " << D << "\nWeekday is: " << D.week_day() << "\n";
			file_result << "\n-------------------------------------\n";
		}
		file.close();
		file_result.close();
		return 0;
	}
	catch (std::string er) {
		std::cout << er << std::endl;
		return 1;
	}
}

int main() {
	if (Date_test1_in_out_file() == 0) {
		std::cout << "Date_test1_in_out_file passed\n";
	}
	if (Date_test2_next_prev() == 0) {
		std::cout << "Date_test2_next_prev passed\n";
	}
	if (Date_test3_comparing() == 0) {
		std::cout << "Date_test3_comparings passed\n";
	}
	if (Date_test4_math() == 0) {
		std::cout << "Date_test4_math passed\n";
	}
	if (Date_test5_weekday() == 0) {
		std::cout << "Date_test5_weekday passed\n";
	}
	return 0;
}
