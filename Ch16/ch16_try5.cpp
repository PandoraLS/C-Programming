/*
 * @Author: seenli
 * @Date: 2021-01-30 14:24:45
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-30 14:37:04
 * @FilePath: \Ch16\ch16_try5.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 16, Try This 5: define a vector<Record>, initialise it with four
// records of your choice, and compute their total price using the functions
// given


#include "../includes/std_lib_facilities.h"
#include <numeric>

struct Record {
    Record(double up, int un): unit_price(up), units(un) {}
    double unit_price;
    int units;                  // 售出数量
};

double price(double v, const Record& r) {
    return v + r.unit_price * r.units;              // 计算price并且累加
}

void f(const vector<Record>& vr) {
    double total = accumulate(vr.begin(), vr.end(), 0.0, price);
    cout << "Total is " << total << endl;
}

int main()
try {
    Record rec1 = Record(10.9,15);
    Record rec2 = Record(25.5,3);
    Record rec3 = Record(101,75);
    Record rec4 = Record(5.33,27);
    vector<Record> vr;
    vr.push_back(rec1);
    vr.push_back(rec2);
    vr.push_back(rec3);
    vr.push_back(rec4);
    f(vr);
    
    system("pause");
    return 0;
}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
    keep_window_open();
	return 1;
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