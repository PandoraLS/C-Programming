/*
 * @Author: seenli
 * @Date: 2021-01-28 16:13:40
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-28 16:20:16
 * @FilePath: \Ch15\ch15_ex07.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 15, Exercise 07: find the lexicographical last string in an unsorted
// vector<string>. Beware that "lexicographical" is not the same as "alphabeti-
// cal", as "Zzzz"<"aaa" (uppercase letters are lexicographically before lower-
// case letters).


#include "../includes/std_lib_facilities.h"

// 返回实参最大元素的迭代器
template<class Iterator>
Iterator biggest_element(Iterator first, Iterator last) {
    Iterator high = first;
    while (first != last) {
        if (*first > *high) {
            high = first;
        }
        ++first;
    }
    return high;
}

int main()
try {
    vector<string> vs;
    string s;
    cout << "Enter a few words, Ctrl-Z to end: \n";
    while (cin >> s) {
        vs.push_back(s);
    }

    vector<string>::iterator last = biggest_element(vs.begin(), vs.end());
    if (last!=vs.end())
        cout << "The lexicographically last string in the vector is \""
            << *last << "\".\n";
    else
        cout << "Something went wrong.\n";

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