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
    �޸���ϰ02�еĳ���ʹ������¶Ⱥ�׺c��f
*/


#include "../includes/std_lib_facilities.h"

// type of a temperature reading
struct Reading {
    int hour;               // hour after midnight [0:23]
    double temperature;     // �¶�
    char temp_scale;        // 'f'����, 'c'����
    Reading(int h, double t, char ts): hour(h), temperature(t), temp_scale(ts) {}
};

ostream& operator<<(ostream& os, const Reading& r) {
    return os << r.hour << ' ' << r.temperature << r.temp_scale;
}

const char fahr = 'f';          // ����
const char cels = 'c';          // ����

const int max_temp = 107;
const int min_temp = -43;

// ������� reading ����ʱ����¶�
Reading create_reading() {
    int h = randint(0, 23);
    double t = randint(min_temp, max_temp) + randint(-10, 10) / double(10);
    char ts;
    randint(0, 10) > 4 ? ts = fahr : ts = cels; // ���Ϻ����ϱ��� 6:4
    return Reading(h, t, ts);
}

// ���¶�������ļ�
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

