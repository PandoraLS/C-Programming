/*
 * @Author: seenli
 * @Date: 2021-01-21 18:29:37
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-21 21:32:22
 * @FilePath: \Ch12\ch12_ex02.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 17, 
// Exercise 01: output format of pointer value
// Exercise 02: how many bytes in an int, double, bool? Don't use sizeof()

#include "../includes/std_lib_facilities.h"

int ptr_to_int(void* ptr) {
    ostringstream oss;
    oss << ptr;
    istringstream iss(oss.str());
    int adr_int;
    iss >> hex >> adr_int;
    if (!iss) error("problem reading address");
    return adr_int;
}

struct x {int a, b, c;};

struct v {
    int a, b, c;
    virtual void f() {}
};

int main()
try {
    // 1
    cout << "Output format of a pointer: \n";
    int* pi = new int(0);
    cout << "int* pi is " << pi << endl;
    cout << "&*pi is " << &*pi << endl;
    cout << "&pi[1] is " << &pi[1] << endl;
    delete pi;

    // 2
    cout << "\nNumber of bytes of different types: \n";
    pi = new int[2];
    pi[0] = 0;
    pi[1] = 0;
    // 通过指针相减来获取类型的大小
    int var_size = ptr_to_int(&pi[1]) - ptr_to_int(pi);
    cout << "int: " << &pi[1] << " - " << pi << " = " << var_size << " bytes. \n";
    cout << "sizeof(int): " << sizeof(int) << endl;
    delete[] pi;

    char* pc = new char[2];
    pc[0] = 0;
    pc[1] = 0;
    var_size = ptr_to_int(&pc[1]) - ptr_to_int(pc);
    // 为什么这里要用void*呢
    cout << "char: " << (void*)&pc[1] << " - " << (void*)pc << " = " << var_size << " bytes. \n";
    cout << "sizeof(char): " << sizeof(char) << "\n";
    delete[] pc;

    double* pd = new double[2];
    pd[0] = 0;
    pd[1] = 0;
    var_size = ptr_to_int(&pd[1]) - ptr_to_int(pd);
    cout << "double: " << &pd[1] << " - " << pd << " = " << var_size << " bytes. \n";
    cout << "sizeof(double): " << sizeof(double) << "\n";
    delete[] pd;

    bool* pb = new bool[2];
    pb[0] = 0;
    pb[1] = 0;
    var_size = ptr_to_int(&pb[1]) - ptr_to_int(pb);
    cout << "bool: " << &pb[1] << " - " << pb << " = " << var_size << " bytes. \n";
    cout << "sizeof(bool): " << sizeof(bool) << "\n";
    delete[] pb;

    x* px  = new x[2];
    var_size = ptr_to_int(&px[1]) - ptr_to_int(px);
    cout << "struct x: " << &px[1] << " - " << px << " = " << var_size << " byte. \n";
    cout << "sizeof(x): " << sizeof(x) << "\n";

    v* pv = new v[2];
    var_size = ptr_to_int(&pv[1]) - ptr_to_int(pv);
    cout << "struct v: " << &pv[1] << " - " << pv << " = " << var_size << " byte. \n";
    cout << "sizeof(v): " << sizeof(v) << "\n";

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
