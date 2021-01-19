/*
 * @Author: seenli
 * @Date: 2021-01-19 10:15:44
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 10:19:42
 * @FilePath: \Ch11\ch11_ex06.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 05: read text file, replace punctuation with whitespace,
// producing new file
// Use ex01_in.txt for input

#include "../includes/std_lib_facilities.h"

int main()
try {
    string iname{"ex01_in.txt"};
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);

    string oname{"ex06_out.txt"};
    ofstream ofs(oname.c_str());
    if (!ofs) error("cannot open output file ", oname);

    char ch;
    while (ifs.get(ch)) {
        if (ispunct(ch)) ch = ' ';
        ofs << ch;
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