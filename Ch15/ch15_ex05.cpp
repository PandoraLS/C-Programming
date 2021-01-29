/*
 * @Author: seenli
 * @Date: 2021-01-28 15:37:13
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-28 15:54:38
 * @FilePath: \Ch15\ch15_ex05.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 15, Exercise 05: Define an input and an output operator (>> and <<) for vector.

#include "../includes/std_lib_facilities.h"

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ",";
        os << ' ';
    }
    os << '}';
    return os;
}

template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    char ch;
    is >> ch;
    if (ch != '{') error("vector must start with '{'");
    T element;
    while (true) {
        is >> ch;
        if (is && ch == '}') return is;
        else is.unget();
        is >> element;
        if (is) v.push_back(element);
        else error("invalid element");
    }
    return is;
}

int main()
try {
    vector<double> vd;
    vector<int> vi;
    vector<string> vs;
    cout << "请输入double, int, string类型的数据, 数据需要用{}包括起来\n";
    cout << "Enter vector of doubles: ";
    cin >> vd;
    cout << "Enter vector of integers: ";
    cin >> vi;
    cout << "Enter vector of strings: 左花括号->回车->字符串->回车->右花括号";
    cin >> vs;

    cout << vd << '\n' << vi << '\n' << vs << '\n';

    system("pause");
    return 0;
}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << endl;
    keep_window_open();
    return 3;
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