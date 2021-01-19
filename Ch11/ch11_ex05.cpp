/*
 * @Author: seenli
 * @Date: 2021-01-19 09:51:04
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 10:14:38
 * @FilePath: \Ch11\ch11_ex05.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 05: read strings and for each string, present for each
// character its classifications

#include "../includes/std_lib_facilities.h"

// print for each character all its classifications
void char_class(const string& s) { 
    for (int i{}; i < s.size(); ++i) {
        cout << s[i];
        if (isspace(s[i])) cout << " isspace";
        if (isalpha(s[i])) cout << " isalpha";
        if (isdigit(s[i])) cout << " isdigit";
        if (isxdigit(s[i])) cout << " isxdigit";
        if (isupper(s[i])) cout << " isupper";
        if (islower(s[i])) cout << " islower";
        if (isalnum(s[i])) cout << " isalnum";
        if (iscntrl(s[i])) cout << " iscntrl";
        if (ispunct(s[i])) cout << " ispunct";
        if (isprint(s[i])) cout << " isprint";
        if (isgraph(s[i])) cout << " isgraph";
        cout << endl;
    }
}

int main()
try {
    cout << "ÇëÊäÈëstrings, ÒÔ ctrl+z ½áÊø\n";
    string s;
    while (cin >> s) {
        char_class(s);
        cout << endl;
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
