/*
 * @Author: seenli
 * @Date: 2021-01-26 19:36:30
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-26 19:58:47
 * @FilePath: \Ch14\ch14_ex05.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 14, exercise 05: class Int with single member of type int with
// constructors, assignment, operators +,-,*,/ for it. Test and improve, e.g.,
// define operators << and >> for convenient I/O

#include "../includes/std_lib_facilities.h"

class Int {
    int val;
    public:
        Int(): val(0) { }                               // 默认构造函数
        Int(const Int& arg): val(arg.val) { }           // 拷贝 构造函数
        Int(int v): val(v) { }                          // 构造函数
        Int& operator=(const Int& v) {val = v.val;}     // 拷贝赋值
        int get() const {return val;}
};

Int operator+(const Int& v1, const Int& v2) {
    return Int(v1.get() + v2.get()); 
}

Int operator-(const Int& v1, const Int& v2) {
    return Int(v1.get() - v2.get());
}

Int operator*(const Int& v1, const Int& v2) {
    return Int(v1.get() * v2.get());
}

Int operator/(const Int& v1, const Int& v2) {
    return Int(v1.get() / v2.get());
}

ostream& operator<<(ostream& os, const Int& d) {
    os << d.get();
    return os;
}

int main()
try {
    Int i1;
    Int i2 = 2;
    Int i3(i2);
    Int i4;
    i4 = i2;
    Int i5 = 6;
    cout << "i1 (default constructed): " << i1 << "\n";
    cout << "i2 (constructed with argument): " << i2 << "\n";
    cout << "i3 (copy constructed from i2): " << i3 << "\n";
    cout << "i4 (copy assigned  from i2): " << i4 << "\n";
    cout << "i5 (constructed with argument): " << i5 << "\n";
    cout << "i2 + i5 = " << i2+i5 << "\n";
    cout << "i5 - i2 = " << i5-i2 << "\n";
    cout << "i2 * i5 = " << i2*i5 << "\n";
    cout << "i5 / i2 = " << i5/i2 << "\n";
    
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