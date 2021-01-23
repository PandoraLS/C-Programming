/*
 * @Author: seenli
 * @Date: 2021-01-23 16:11:22
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-23 16:16:58
 * @FilePath: \Ch13\ch13_drill2.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 13, Drill 2: std:vector drill

#include "../includes/std_lib_facilities.h"

vector<int> gv;

void print_vec(const vector<int>& v) {
    for (int i{}; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
}

void f(const vector<int>& v) {
    vector<int> lv(v.size());
    lv = gv;
    print_vec(lv);
    cout << endl;
    vector<int> lv2(v);
    print_vec(lv2);
    cout << endl;
}

void init_gv(vector<int>& v) {
    for (int i{}; i < 10; ++i) {
        v.push_back(pow(2, i));
    }
}

int main()
try {
    init_gv(gv);
    f(gv);
    vector<int> vv;
    vv.push_back(1);
    for (int i{1}; i < 10; ++i) {
        vv.push_back((i + 1) * vv[i - 1]);
    }
    f(vv);
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
