/*
 * @Author: seenli
 * @Date: 2021-01-12 19:15:02
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-12 19:42:01
 * @FilePath: \Ch10\ch04_ex04b.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chapter 10, exercise 04, second part: 
    测试每个温度，并将摄氏温度转换为华氏温度
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

// 将摄氏转换为华氏
double c_to_f(double t) {
    return t * 9 / 5 + 32;
}

const int max_temp = 108;
const int min_temp = -44;
const char fahr = 'f';
const char cels = 'c';

// 从文件中读取vector
void fill_from_file(vector<Reading>& readings, const string& name) {
    ifstream ist(name.c_str());
    if (!ist) {
        error("cannot open input file ", name);
    }
    Reading r;
    char ch;
    while (true) {
        ist >> r;
        if (!ist) break;            // 达到EOF
        if (r.hour < 0 || r.hour > 23) error("hour out of range");
        if (r.temperature<min_temp || r.temperature > max_temp) {
            error ("temperature out of range");
        }

        ist >> ch;
        switch (ch)
        {
        case cels:
            r.temperature = c_to_f(r.temperature);
            break;
        case fahr:
            break;
        default:
            error("illegal temperature scale ", ch);
        }
        readings.push_back(r);
    }
}

int main()
try {
    vector<Reading> readings;
    fill_from_file(readings, "ex04_raw_temps.txt");

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
