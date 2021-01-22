/*
 * @Author: seenli
 * @Date: 2021-01-21 22:12:01
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-21 22:30:40
 * @FilePath: \Ch12\ch12_ex05.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 12, exercise 05: function that finds the first occurrence of a
// C-style string in another


#include "../includes/std_lib_facilities.h"
#include <cstring>

const char* findx(const char* s, const char* x) {
    if (x == 0) return s;
    for (int i{}; s[i]; ++i) {
        if (s[i] == x[0]) {                                 // 定位第一个匹配的字符
            for (int j{1}; x[j]; ++j) {                     // 循环子串
                if (s[i + j] != x[j]) break;                // 不匹配
                if (x[j + 1] == 0) return &s[i];            // 发现子串 0实际上是字符串的结束符'\0'
                if (s[i + j + 1] == 0) return 0;            // s ended before substring
            }
        }
    }
    return 0;
}

int main()
try {
    char* ss = "does this work with whitespace, too?";
    char* xx = "work with";
    char* s = new char[strlen(ss) + 1];
    strcpy(s, ss);                                              // char *strcpy(char *dest,const char *src)
    char* x = new char[strlen(xx) + 1];
    strcpy(x, xx);
    const char* sub = findx(s, x);
    if (!sub) cout << "Not found!\n";
    else cout << x << endl;
    delete[] s;
    delete[] x;

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