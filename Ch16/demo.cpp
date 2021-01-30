/*
 * @Author: seenli
 * @Date: 2021-01-11 21:43:18
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-30 15:20:07
 * @FilePath: \Ch16\demo.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


#include "../includes/std_lib_facilities.h"

int main()
try {
    
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