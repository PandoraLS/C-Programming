/*
 * @Author: seenli
 * @Date: 2021-01-18 17:54:23
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-18 18:16:34
 * @FilePath: \Ch11\ch11_ex02.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Write a program that given a file name and a word outputs each line that contains 
// that word together with the line number. Hint: getline().

#include "../includes/std_lib_facilities.h"

int main()
try {
    string word_match{"return"};
    ifstream ifs{"ch11_ex02.cpp"};
    string line;
    for (size_t line_num{1}; getline(ifs, line); ++line_num) {
        if (string::npos != line.find(word_match)) {
            cout << line_num << line << endl;
        }
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
