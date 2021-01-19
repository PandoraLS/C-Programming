/*
 * @Author: seenli
 * @Date: 2021-01-19 18:35:59
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 18:40:13
 * @FilePath: \Ch11\ch11_ex13.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 13: reverse the order of words in a text file
// Use macbeth.txt for input


#include "../includes/std_lib_facilities.h"

int main()
try {
    string iname{"macbeth.txt"};
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);

    string oname{"ex13_out.txt"};
    ofstream ofs(oname.c_str());
    if (!ofs) error("cannot open output file ", oname);

    
    vector<string> contents;
    string s;
    while (ifs >> s) {
        contents.push_back(s);
    }

    for (int i = contents.size() - 1; i >= 0; --i) {
        ofs << contents[i] << endl;
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
