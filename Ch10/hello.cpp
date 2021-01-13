/*
 * @Author: seenli
 * @Date: 2021-01-13 16:16:35
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-13 16:18:08
 * @FilePath: \Ch10\hello.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#include "../includes/std_lib_facilities.h"

int main()
try {
    // 花括号初始化会默认为0
    int i{};
    double d{};
    float f{};
    cout << "int i: " << i << endl;
    cout << "double d: " << i << endl;
    cout << "float f: " << i << endl;
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