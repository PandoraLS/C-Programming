/*
 * @Author: seenli
 * @Date: 2021-01-13 15:59:45
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-13 16:34:56
 * @FilePath: \Ch10\ch10_ex05.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chapter 10, exercise 05 
    write the print_year() function from 10.11.2.
*/

#include "../includes/std_lib_facilities.h"

const int not_a_reading = -7777;            // 比最小值还小
const int not_a_month = -1;

struct Day {
    vector<double> hour;
    Day();                                  // 初始化hour为not a reading
};

Day::Day(): hour(24) {
    for (int i{}; i < hour.size(); ++i) {
        hour[i] = not_a_reading;
    }
}

struct Month {                              // 一个月的温度reading
    int month;                              // [0:12) January is 0
    vector<Day> day;                        // [1:31] 一月中的天数
    Month(): month(not_a_month), day(32) {}
};

struct Year {                               // 一年的temperature readings 
    int year;                               // 公元后为正数
    vector<Month> month;                    // [0:12) January is 0
    Year(): month(12) {}                    // 每年12月
};

struct Reading {
    int day;
    int hour;
    double temperature;
};

int month_to_int(string s);
bool is_valid(const Reading& r);
void end_of_loop(istream& ist, char term, const string& message);

istream& operator>>(istream& is, Reading& r) {
    char ch1;
    if (is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')') error("bad reading");
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

int main()
try {
    
    system("pause");
    return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
	return 2;
}