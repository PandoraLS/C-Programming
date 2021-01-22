/*
 * @Author: seenli
 * @Date: 2021-01-21 21:44:09
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-21 22:11:33
 * @FilePath: \Ch12\ch12_ex04.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 12, exercise 04: function that copies a C-style string into memory
// it allocates on the heap without using standard library functions

#include "../includes/std_lib_facilities.h"

char* strcopy(const char* s) {
    if (s == 0) return 0;

    // 获取s中字符的数量
    int n{};
    while (s[n] != 0) {
        ++n;
    }

    // 为结束0分配内存空间
    char* pc = new char[n+1];

    // 复制string
    for (int i{}; s[i]; ++i) {
        pc[i] = s[i];
    }
    pc[n] = 0;              // 0 终止符

    // delete[] s;
    return pc;
}

int main()
try {
    cout << "请输入字符串,如果想结束循环,请输入ctrl+z\n";
    string s;
    char* cstr;
    while (cin >> s && s != "quit") {
        cstr = strcopy(&s[0]);
        cout << cstr << "\n";
        delete[] cstr;
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
