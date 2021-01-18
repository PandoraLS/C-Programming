/*
 * @Author: seenli
 * @Date: 2021-01-18 17:35:28
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-18 17:41:48
 * @FilePath: \Ch11\ch11_ex01.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 01: read text file, convert input to all lower case,
// producing new file
// Use ex01_in.txt

#include "../includes/std_lib_facilities.h"

int main()
try {
    string iname{"ex01_in.txt"};
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);

    string oname{"ex01_out.txt"};
    ofstream ofs(oname.c_str());
    if (!ofs) error("cannot open output file ", oname);

    char ch;
    while (ifs.get(ch)) {
        if (isalpha(ch)) ch = tolower(ch);
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
