/*
 * @Author: seenli
 * @Date: 2021-01-12 14:44:11
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-12 17:19:33
 * @FilePath: \Ch10\ch10_ex03.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chapter 10, exercise 03: 
    read data from raw_temps.txt into a vector, calculate mean and median temperatures
*/

#include "../includes/std_lib_facilities.h"

// type of a temperature reading
struct Reading {
    int hour;               // hour after midnight [0:23]
    double temperature;     // 华氏温标
    Reading(): hour(0), temperature(0) {}
    Reading(int h, double t): hour(h), temperature(t) {}
};

bool operator<(const Reading& r1, const Reading& r2) {
    return r1.temperature < r2.temperature;
}

ostream& operator<<(ostream& os, const Reading& r) {
    return os << r.hour << ' ' << r.temperature;
}

istream& operator>>(istream& is, Reading& r) {
    int hour;
    double temperature;
    is >> hour >> temperature;
    if (!is) {
        return is;
    }
    r = Reading(hour, temperature);
    return is;
}

const int max_temp = 108;
const int min_temp = -44;

// 从文件中读取Readings并存储到vector中
void fill_from_file(vector<Reading>& readings, const string& name) {
    ifstream ist(name.c_str());
    if (!ist) {
        error("cannnot open input file ", name);
    }
    Reading r;
    while (ist >> r) {
        if (r.hour < 0 || r.hour > 23) {
            error("hour out of range");
        }
        if (r.temperature < min_temp || r.temperature > max_temp) {
            error("temperature out of range");
        }
        readings.push_back(r);
    }
}

int main()
try {
    vector<Reading> readings;
    fill_from_file(readings, "ex02_raw_temps.txt");

    // 计算中位数
    sort(readings.begin(), readings.end());
    double median = readings[readings.size() / 2].temperature;

    // 计算均值
    double sum {0.0};
    for (int i{0}; i < readings.size(); ++i) {
        sum += readings[i].temperature;
    }
    
    double avg = sum / readings.size();
    
    // 输出
    cout << "median temperature: " << median << " F" << endl;
    cout << "average temperature: " << avg << " F" << endl;
    
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
