/*
 * @Author: seenli
 * @Date: 2021-01-19 18:15:59
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 18:44:00
 * @FilePath: \Ch11\ch11_ex12.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 12: reverse the order of characters in a text file
// (hint: "file open modes")
// Use macbeth.txt for input


#include "../includes/std_lib_facilities.h"

int main()
try {
    string iname{"macbeth.txt"};
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);

    string oname{"ex12_out.txt"};
    ofstream ofs(oname.c_str());
    if (!ofs) error("cannot open output file ", oname);

    // read file into string
    string contents;
    char ch;
    while (ifs.get(ch)) {
        contents.push_back(ch);
    }

    // 从后向前读取string并写到file中
    for (int i = contents.size() - 1; i >= 0; --i) {
        ofs << contents[i];
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