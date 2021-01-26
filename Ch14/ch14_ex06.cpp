/*
 * @Author: seenli
 * @Date: 2021-01-26 20:02:06
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-26 21:14:38
 * @FilePath: \Ch14\ch14_ex06.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 14, exercise 06: repeat previous exercise, but with a class Number<T>
// and try adding %, use for Number<double> and Number<int>

#include "../includes/std_lib_facilities.h"

template<class T> class Number {
    T val;
    public:
        Number(): val(T()) { }                                      // 默认构造函数
        Number(const Number& arg): val(arg.val) { }                 // 拷贝构造函数
        Number(T v): val(v) { }                                     // 构造函数
        Number& operator=(const Number& v) {val = v.val; }          // 拷贝赋值
        T get() const {return val; }
};

template<class T>
Number<T> operator+(const Number<T>& v1, const Number<T>& v2) {
    return Number<T>(v1.get() + v2.get());
}

template<class T>
Number<T> operator-(const Number<T>& v1, const Number<T>& v2) {
    return Number<T>(v1.get() - v2.get());
}

template<class T>
Number<T> operator*(const Number<T>& v1, const Number<T>& v2) {
    return Number<T>(v1.get() * v2.get());
}

template<class T>
Number<T> operator/(const Number<T>& v1, const Number<T>& v2) {
    return Number<T>(v1.get() / v2.get());
}

template<class T>
Number<T> operator%(const Number<T>& v1, const Number<T>& v2) {
    return Number<T>(v1.get() % v2.get());
}

template<class T>
ostream& operator<<(ostream& os, const Number<T>& d) {
    os << d.get();
    return os;
}

int main()
try {
    cout << "int:\n";
    Number<int> i1;
    Number<int> i2 = 2;
    Number<int> i3(i2);
    Number<int> i4;
    i4 = i2;
    Number<int> i5 = 5;
    cout << "i1 (default constructed): " << i1 << "\n";
    cout << "i2 (constructed with argument): " << i2 << "\n";
    cout << "i3 (copy constructed from i2): " << i3 << "\n";
    cout << "i4 (copy assigned  from i2): " << i4 << "\n";
    cout << "i5 (constructed with argument): " << i5 << "\n";
    cout << "i2 + i5 = " << i2+i5 << "\n";
    cout << "i5 - i2 = " << i5-i2 << "\n";
    cout << "i2 * i5 = " << i2*i5 << "\n";
    cout << "i5 / i2 = " << i5/i2 << "\n";
    cout << "i5 % i2 = " << i5%i2 << "\n";

    cout << "\ndouble:\n";
    Number<double> d1;
    Number<double> d2 = 2.2;
    Number<double> d3(d2);
    Number<double> d4;
    d4 = d2;
    Number<double> d5 = 5.5;
    cout << "d1 (default constructed): " << d1 << "\n";
    cout << "d2 (constructed with argument): " << d2 << "\n";
    cout << "d3 (copy constructed from d2): " << d3 << "\n";
    cout << "d4 (copy assigned  from d2): " << d4 << "\n";
    cout << "d5 (constructed with argument): " << d5 << "\n";
    cout << "d2 + d5 = " << d2+d5 << "\n";
    cout << "d5 - d2 = " << d5-d2 << "\n";
    cout << "d2 * d5 = " << d2*d5 << "\n";
    cout << "d5 / d2 = " << d5/d2 << "\n";
//    cout << "d5 % d2 = " << d5%d2 << "\n";  // does not compile!

    cout << "\nchar:\n";
    Number<char> c1;
    Number<char> c2 = 'x';
    Number<char> c3(c2);
    Number<char> c4;
    c4 = c2;
    Number<char> c5 = 'C';
    cout << "c1 (default constructed): " << c1 << "\n";
    cout << "c2 (constructed with argument): " << c2 << "\n";
    cout << "c3 (copy constructed from c2): " << c3 << "\n";
    cout << "c4 (copy assigned  from c2): " << c4 << "\n";
    cout << "c5 (constructed with argument): " << c5 << "\n";
    cout << "c2 + c5 = " << c2+c5 << "\n";
    cout << "c5 - c2 = " << c5-c2 << "\n";
    cout << "c2 * c5 = " << c2*c5 << "\n";
    cout << "c5 / c2 = " << c5/c2 << "\n";
    cout << "c5 % c2 = " << c5%c2 << "\n";

    cout << "\nstring:\n";
    Number<string> s1;
    Number<string> s2("xxx");
    Number<string> s3(s2);
    Number<string> s4;
    s4 = s2;
    Number<string> s5("ABCD!");
    cout << "s1 (default constructed): " << s1 << "\n";
    cout << "s2 (constructed with argument): " << s2 << "\n";
    cout << "s3 (copy constructed from s2): " << s3 << "\n";
    cout << "s4 (copy assigned  from s2): " << s4 << "\n";
    cout << "s5 (constructed with argument): " << s5 << "\n";
    cout << "s2 + s5 = " << s2+s5 << "\n";
//    cout << "s5 - s2 = " << s5-s2 << "\n";  // does not compile
//    cout << "s2 * s5 = " << s2*s5 << "\n";  // does not compile
//    cout << "s5 / s2 = " << s5/s2 << "\n";  // does not compile
//    cout << "s5 % s2 = " << s5%s2 << "\n";  // does not compile
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
