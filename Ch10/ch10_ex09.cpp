/*
 * @Author: seenli
 * @Date: 2021-01-15 19:58:27
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-15 20:41:35
 * @FilePath: \Ch10\ch10_ex09.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chapter 10, exercise 09: take names of two files containing sorted
    whitespace-separated words and merge them, preserving order
    use ex09_in1.txt and ex09_in2.txt for input
*/

#include "../includes/std_lib_facilities.h"

int main()
try {
    string s1, s2;
    cout << "请输入两个源文件的名称: ";
    cin >> s1 >> s2;
    string out_file = "ex09_out.txt";

    ifstream ifs1(s1.c_str());
    if (!ifs1) error("cannot open input file ", s1);
    ifstream ifs2(s2.c_str());
    if (!ifs2) error("cannot open input file ", s2);
    ofstream ofs(out_file.c_str());
    if (!ofs) error("cannot open output file ", out_file);
    
    string sf1, sf2;
    ifs1 >> sf1;
    ifs2 >> sf2;
    if (sf1 == "" || sf2 == "") error("至少一个输入文件为空");

    while (true) {
        if (sf1 <= sf2) {
            ofs << sf1 << endl;
            cout << sf1 << endl;
            if (ifs1.eof()) break;
            else ifs1 >> sf1;
        }
        else {
            ofs << sf2 << endl;
            cout << sf2 << endl;
            if (ifs2.eof()) break;
            else ifs2 >> sf2;
        }
    }

    // 清空未完files
    if (ifs1.eof()) {
        ofs << sf2 << endl;
        cout << sf2 << endl;
        while (ifs2 >> sf2) ofs << sf2 << endl;
    } else {
        ofs << sf1 << endl;
        cout << sf1 << endl;
        while (ifs1 >> sf1) ofs << sf1 << endl;
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
