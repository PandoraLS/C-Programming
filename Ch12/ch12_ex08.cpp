/*
 * @Author: seenli
 * @Date: 2021-01-22 10:47:08
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-22 10:50:14
 * @FilePath: \Ch12\ch12_ex08.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 12, exercise 08: same as exercise 7, but read into a std:string

#include "../includes/std_lib_facilities.h"

int main()
try {
    char ch;
    string s;
    while (cin >> ch && ch != '!') {
        s.push_back(ch);
    }
    cout << s << endl;
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
