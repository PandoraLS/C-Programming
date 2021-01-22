/*
 * @Author: seenli
 * @Date: 2021-01-21 22:36:32
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-22 10:46:38
 * @FilePath: \Ch12\ch12_ex07.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 12, exercise 07: read characters from cin into array on heap; read
// until '!' is entered, do not use std::string, ignore memory exhaustion

#include "../includes/std_lib_facilities.h"

// copy C-style string into new array one element bigger
char* add_size(const char* s) {
    if (s == 0) return 0;

    // 获取s中的char的数量
    int n{};
    while (s[n] != 0) {
        ++n;
    }

    // 为结束0分配内存空间
    char* pc = new char[n+2];;

    // copy string
    for (int i{}; s[i]; ++i) {
        pc[i] = s[i];
    }
    pc[n] = 0;

    return pc;
}

int main()
try {
    cout << "请输入字符串,如果想结束循环,请输入ctrl+z\n";
    char ch;
    char* my_array = new char[1];
    *my_array = 0;
    while (cin >> ch && ch != '!') {
        my_array = add_size(my_array);                      // my_array已经扩充了两个字符了
        int i{};
        for (; my_array[i]; ++i);                           // 一直找到my_array的末尾
        my_array[i] = ch;
        my_array[i + 1] = 0;
    }
    cout << my_array << endl;
    delete[] my_array;
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
