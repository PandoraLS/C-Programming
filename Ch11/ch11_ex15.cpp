/*
 * @Author: seenli
 * @Date: 2021-01-19 18:52:15
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 18:56:27
 * @FilePath: \Ch11\ch11_ex15.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 15: read file of whitespace-separated numbers, output
// file of numbers using scientific format, precision 8 in four fields of 20
// characters per line
// Use ex15_in.txt for input


#include "../includes/std_lib_facilities.h"

int main()
try {
    string iname{"ex15_in.txt"};
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);

    // 读取数字
    double d;
    vector<double> nums;
    while (ifs >> d) {
        nums.push_back(d);
    }

    // 按给定格式打印输出
    cout << scientific << setprecision(8);
    for (int i{}; i < nums.size(); ++i) {
        cout << setw(20) << nums[i];
        if (i + 1 % 4 == 0) {
            cout << endl;
        }
    }

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