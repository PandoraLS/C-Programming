/*
 * @Author: seenli
 * @Date: 2021-01-12 14:09:51
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-12 16:28:53
 * @FilePath: \Ch10\ch10_ex02.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chapter 10, exercise 02: 
    create file of data like defined in §10.5; 
    and fill it with at least 50 temperature readings; 
    call the file it creates raw_temps.txt
*/

#include "../includes/std_lib_facilities.h"

// type of a temperature reading
struct Reading {
    int hour;               // hour after midnight [0:23]
    double temperature;     // 华氏温标
    Reading(int h, double t): hour(h), temperature(t) {}
};

ostream& operator<<(ostream& os, const Reading& r) {
    return os << r.hour << ' ' << r.temperature;
}

const int max_temp = 107;
const int min_temp = -43;

// 创建随机 reading 生成时间和温度
Reading create_reading() {
    int h = randint(0, 23);
    double t = randint(min_temp, max_temp) + randint(-10, 10) / double(10);
    return Reading(h, t);
}

// 将温度输出到文件
void write_to_file(const vector<Reading>& r, const string& name) {
    ofstream ost(name.c_str());
    if (!ost) {
        error("cannot open output file ", name);
    }
    for (int i{0}; i < r.size(); ++i) {
        ost << r[i] << endl;
    }
}

int main()
try {
    vector<Reading> readings;
    for (int i{0}; i < 250; ++i) {
        readings.push_back(create_reading());
    }
    write_to_file(readings, "ex02_raw_temps.txt");
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