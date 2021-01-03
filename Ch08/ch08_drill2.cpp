/*
 * @Author: seenli
 * @Date: 2021-01-03 23:15:46
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-03 23:24:36
 * @FilePath: \Ch08\ch08_drill2.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#include "std_lib_facilities.h"

void swap_v(int a, int b) {
    int temp{};
    temp = a;
    a = b;
    b = temp;
    cout << "*** In function swap_v() a: " << a << " b: " << b << endl;
}

void swap_r(int& a, int& b) {
    int temp{};
    temp = a;
    a = b;
    b = temp;
    cout << "*** In function swap_r() a: " << a << " b: " << b << endl;
}

int main() {
    int x{7}, y{9};
    cout << "x: " << x << " y: " << y << endl;
    swap_v(x, y);
    cout << "after swap_v() x: " << x << " y: " << y << "\n";
    swap_r(x, y);
	cout << "after swap_r() x: " << x << " y: " << y << "\n";
    cout << "-------------------------------------------------\n";

    system("pause");            // 最后保留住窗口
    return 0;
}