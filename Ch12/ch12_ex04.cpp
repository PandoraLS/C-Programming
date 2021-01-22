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

    // ��ȡs���ַ�������
    int n{};
    while (s[n] != 0) {
        ++n;
    }

    // Ϊ����0�����ڴ�ռ�
    char* pc = new char[n+1];

    // ����string
    for (int i{}; s[i]; ++i) {
        pc[i] = s[i];
    }
    pc[n] = 0;              // 0 ��ֹ��

    // delete[] s;
    return pc;
}

int main()
try {
    cout << "�������ַ���,��������ѭ��,������ctrl+z\n";
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
