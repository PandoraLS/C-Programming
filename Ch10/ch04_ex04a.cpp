/*
 * @Author: seenli
 * @Date: 2021-01-12 16:27:14
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-12 19:14:18
 * @FilePath: \Ch10\ch04_ex04a.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chapter 10, exercise 04, first part: 
    修改练习02中的程序，使其包含温度后缀c或f
*/


#include "../includes/std_lib_facilities.h"

// type of a temperature reading
struct Reading {
    int hour;               // hour after midnight [0:23]
    double temperature;     // 温度
    char temp_scale;        // 'f'华氏, 'c'摄氏
    Reading(int h, double t, char ts): hour(h), temperature(t), temp_scale(ts) {}
};

ostream& operator<<(ostream& os, const Reading& r) {
    return os << r.hour << ' ' << r.temperature << r.temp_scale;
}

const char fahr = 'f';          // 华氏
const char cels = 'c';          // 摄氏

const int max_temp = 107;
const int min_temp = -43;

// 创建随机 reading 生成时间和温度
Reading create_reading() {
    int h = randint(0, 23);
    double t = randint(min_temp, max_temp) + randint(-10, 10) / double(10);
    char ts;
    randint(0, 10) > 4 ? ts = fahr : ts = cels; // 华氏和摄氏比例 6:4
    return Reading(h, t, ts);
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
    write_to_file(readings, "ex04_raw_temps.txt");
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

