/*
 * @Author: seenli
 * @Date: 2021-01-26 12:11:35
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-26 16:10:00
 * @FilePath: \Ch14\ch14_ex01.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 14, exercise 01: write a template function that adds elements of one
// vector<T> to the elements of another: f(v1,v2) should do v1[i]+=v2[i] for
// each element of v1

#include "../includes/std_lib_facilities.h"

template<class T> void f(vector<T>& v1, const vector<T>& v2) {
    for (int i = 0; i < v1.size(); ++i) {
        if (i == v2.size()) break;
        v1[i] += v2[i];
    }
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    for (int i = 0; i < v.size() - 1; ++i) {
        os << ' ' << v[i] << ',';
    }
    os << ' ' << v[v.size() - 1] << "}";
    return os;
}


int main()
try {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    cout << "v1: " << v1 << "\n";
    vector<int> v2;
    for (int i = 0; i < 8; ++i) {
        v2.push_back(i);
    }
    cout << "v2: " << v2 << endl;
    f(v1, v2);
    cout << "After: " << v1 << "\n\n";

    v2.push_back(15);
    v2.push_back(16);
    v2.push_back(17);
    cout << "New v2: " << v2 << endl;
    f(v1, v2);
    cout << "After: " << v1 << endl;

    cout << "----------------------------------\n";
    vector<string> vs1;
    vs1.push_back("one");
    vs1.push_back("two");
    vs1.push_back("three");
    vs1.push_back("four");
    cout << "vs1: " << vs1 << endl;

    vector<string> vs2;
    vs2.push_back(" ONE");
    vs2.push_back(" TWO");
    vs2.push_back(" THREE");
    cout << "vs2: " << vs2 << endl;
    f(vs1, vs2);
    cout << "After: " << vs1 << endl;

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
