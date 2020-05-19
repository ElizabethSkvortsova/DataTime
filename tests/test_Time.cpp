/* File  test_Time.cpp
Realization of tests for Time class functions
Done by Skvortsova Yelyzaveta
Date 18.05.2020 */

#include "../src/Time.h"
/*Test1 - Test of
input/output from file*/
int Time_test1_in_out_file() {
	try {
		std::ifstream file("tests/Time.txt");
		std::ofstream file_result("tests/Time_result1_in_out.txt");
		while (!file.eof()) {
			Time T;
			file >> T;
			file_result << T << "\n";
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
comparing functions*/
int Time_test2_compare() {
	try {
		std::ifstream file("tests/Time.txt");
		std::ifstream file2("tests/Time2.txt");
		std::ofstream file_result("tests/Time_result2_compare.txt");
		while (!file.eof() && !file2.eof()) {
			Time T;
			Time T2;
			file >> T;
			file2 >> T2;
			bool res = 0;
			file_result << T << " == " << T2 << " : ";
			res = T == T2;
			file_result << res << "\n";
			file_result << T << " != " << T2 << " : ";
			res = T != T2;
			file_result << res << "\n";
			file_result << T << " > " << T2 << " : ";
			res = T > T2;
			file_result << res << "\n";
			file_result << T << " >= " << T2 << " : ";
			res = T >= T2;
			file_result << res << "\n";
			file_result << T << " < " << T2 << " : ";
			res = T < T2;
			file_result << res << "\n";
			file_result << T << " <= " << T2 << " : ";
			res = T <= T2;
			file_result << res << "\n";
			file_result << "\n-----------------------\n";
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
math functions*/
int Time_test3_math() {
	try {
		std::ifstream file("tests/Time.txt");
		std::ifstream file2("tests/Time2.txt");
		std::ofstream file_result("tests/Time_result3_math.txt");
		while (!file.eof() && !file2.eof()) {
			Time T;
			Time T2;
			file >> T;
			file2 >> T2;
			Time res;
			int number = 3;
			file_result << T << " + " << T2 << " : ";
			res = T + T2;
			file_result << res << "\n";
			file_result << T << " - " << T2 << " : ";
			res = T - T2;
			file_result << res << "\n";
			file_result << T << " * " << number << " : ";
			res = T * number;
			file_result << res << "\n";
			file_result << T << " / " << number << " : ";
			res = T / number;
			file_result << res << "\n";
			file_result << "\n-----------------------\n";
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

/*Test4 - Test of
date and time*/
int Time_test4_datetime() {
	try {
		std::ifstream file("tests/Time.txt");
		std::ifstream file2("tests/Date.txt");
		std::ofstream file_result("tests/Time_result4_datetime.txt");
		while (!file.eof() && !file2.eof()) {
				Time T;
				file >> T;
				Date D;
				file2 >> D;
				Time help = convert_date(D);
				file_result << "From " << D << " to time you get:\n " << help;
				Date help1 = add_date(D, T);
				file_result << "If we add " << D << " and " << T << " we get: " << help1 << "\n";
				help1 = subtract_date(D, T);
				file_result << "If we subtract " << D << " and " << T << " we get: " << help1 << "\n";
			
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
	if (Time_test1_in_out_file() == 0) {
		std::cout << "Time_test1_in_out_file passed\n";
	}
	if (Time_test2_compare() == 0) {
		std::cout << "Time_test2_compare passed\n";
	}
	if (Time_test3_math() == 0) {
		std::cout << "Time_test3_math passed\n";
	}
	if (Time_test4_datetime() == 0) {
		std::cout << "Time_test4_datetime passed\n";
	}
	return 0;
}