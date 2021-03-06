/*
 * @Author: seenli
 * @Date: 2021-01-30 15:19:40
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-30 15:31:35
 * @FilePath: \Ch16\ch16_ex04.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 16, Exercise 4: implement count_if() yourself and test it

#include "../includes/std_lib_facilities.h"

template<class In, class Pred>
int my_count_if(In first, In last, const Pred& p) {
    int ctr = 0;
    while (first != last) {
        if (p(*first)) ++ctr;
        ++first;
    }
    return ctr;
}

template<class T>
class Less_than {
    T val;
public:
    Less_than(T v): val(v) {}
    bool operator()(const T& v) const {return v < val;}
};

template<class T>
class Greater_than {
    T val;
public:
    Greater_than(T v): val(v) {}
    bool operator()(const T& v) const {return v > val;}
};

bool odd(int i) {return i % 2 != 0;}

int main()
try {
    vector<int> vi;
    for (int i = 0; i<10; ++i)
        vi.push_back(randint(10));
    cout << "vi:\n";
    for (vector<int>::iterator p = vi.begin(); p!=vi.end(); ++p)
        cout << *p << '\n';

    // Test Less_than function object
    cout << "Enter value for less than count, -1 to exit: ";
    int val;
    while (cin>>val) {
        if (val==-1) break;
        int ctr = my_count_if(vi.begin(),vi.end(),Less_than<int>(val));
        cout << "There " << (ctr==1 ? "is " : "are ") << ctr << " value"
            << (ctr==1 ? " " : "s ") << "less than " << val << " in vi.\n"
            << "Next value: ";
    }

    // Test Greater_than function object
    cout << "Enter value for greater than count, -1 to exit: ";
    while (cin>>val) {
        if (val==-1) break;
        int ctr = my_count_if(vi.begin(),vi.end(),Greater_than<int>(val));
        cout << "There " << (ctr==1 ? "is " : "are ") << ctr << " value"
            << (ctr==1 ? " " : "s ") << "greater than " << val << " in vi.\n"
            << "Next value: ";
    }

    // Test odd() function
    int ctr = my_count_if(vi.begin(),vi.end(),odd);
    cout << "There are " << ctr << " odd values in vi.\n";
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