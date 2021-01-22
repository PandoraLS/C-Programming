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

    // ��ȡs�е�char������
    int n{};
    while (s[n] != 0) {
        ++n;
    }

    // Ϊ����0�����ڴ�ռ�
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
    cout << "�������ַ���,��������ѭ��,������ctrl+z\n";
    char ch;
    char* my_array = new char[1];
    *my_array = 0;
    while (cin >> ch && ch != '!') {
        my_array = add_size(my_array);                      // my_array�Ѿ������������ַ���
        int i{};
        for (; my_array[i]; ++i);                           // һֱ�ҵ�my_array��ĩβ
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
