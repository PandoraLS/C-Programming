/*
 * @Author: seenli
 * @Date: 2021-01-24 11:34:48
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-24 11:37:12
 * @FilePath: \Ch13\ch13_ex05.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 13
// Exercise 05: write a function that concatenates two strings with a dot in between
// Exercise 06: modify function to take a string to be used as separator

#include "../includes/std_lib_facilities.h"

string cat_dot(const string& s1, const string& s2, const string& s3 = ".") {
    return s1 + s3 + s2;
}

int main()
try {
    cout << cat_dot("Niels", "Bohr") << endl;
    cout << cat_dot("Niels", "Bohr", "dot") << endl;
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