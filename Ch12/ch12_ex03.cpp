/*
 * @Author: seenli
 * @Date: 2021-01-21 21:35:39
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-21 21:42:53
 * @FilePath: \Ch12\ch12_ex03.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 12, exercise 03: function that replaces all upercase characters in a
// C-style string with their lowercase equivalents. No standard library functions!

#include "../includes/std_lib_facilities.h"

void to_lower(char* s) {
    for (int i{}; s[i]; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 'a' - 'A';
        }
    }
}

void print_array(char* s) {
    for (int i{}; s[i]; ++i) {
        cout << s[i];
    }
}

void test(string s) {
    to_lower(&s[0]);
    print_array(&s[0]);
    cout << '\n';
}

int main()
try {
    string s;
    while (cin >> s && s != "quit") {
        test(s);
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
