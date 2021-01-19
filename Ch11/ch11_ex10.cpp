/*
 * @Author: seenli
 * @Date: 2021-01-19 15:30:33
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 15:45:46
 * @FilePath: \Ch11\ch11_ex10.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 10: write a function to return a vector of whitespace-
// separated substrings of the argument string

#include "../includes/std_lib_facilities.h"

// 返回空白符分隔的子string of s
vector<string> split(const string& s) {
    istringstream is(s);
    string ss;
    vector<string> substrings;
    while (is >> ss) substrings.push_back(ss);
    return substrings;
}

// 打印strings的vector
void print_vec(const vector<string> vs) {
    for (int i{}; i < vs.size(); ++i) {
        cout << vs[i] << endl;
    }
}

int main()
try {
    cout << "输入几个单词,ctrl+z结束\n";
    string s;
    while (getline(cin, s)) {
        vector<string> substrings = split(s);
        cout << "\nYou entered: \n";
        print_vec(substrings);
        cout << "\nAnother try: \n";
    }
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