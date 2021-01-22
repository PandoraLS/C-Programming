/*
 * @Author: seenli
 * @Date: 2021-01-22 10:50:26
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-22 11:01:07
 * @FilePath: \Ch12\ch12_ex09.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 12, exercise 09: determine growth direction of stack and heap

#include "../includes/std_lib_facilities.h"

int main()
try {
    // 确定栈增长的方向
    int i1{}, i2{}, i3{};
    cout << "Addresses on stack: \n" << &i1 << "\n" << &i2 << "\n" << &i3 << "\n";
    int stack_diff = &i2 - &i1;
    if (stack_diff > 0) cout << "Stack grows up\n";
    else cout << "Stack grows down\n";

    // 确定堆增长的方向
    int* ip1 = new int(0);
    int* ip2 = new int(0);
    int* ip3 = new int(0);
    cout << "Addresses on heap: \n" << ip1 << "\n" << ip2 << "\n" << ip3 << "\n";
    int heap_diff = ip2 - ip1;
    if (heap_diff > 0) cout << "Heap grows up\n";
    else cout << "Heap grows down\n";
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
