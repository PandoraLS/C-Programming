/*
 * @Author: seenli
 * @Date: 2021-01-21 22:30:56
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-21 22:35:40
 * @FilePath: \Ch12\ch12_ex06.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 12, exercise 06: test memory exhaustion

#include "../includes/std_lib_facilities.h"

int main()
try {
    int i = 0;
    while (true) {
        cout << ++i << " MB\n";
        double* pd = new double[131072];    // allocate 1 MB
    }
    system("pause");
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
