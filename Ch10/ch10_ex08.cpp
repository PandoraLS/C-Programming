/*
 * @Author: seenli
 * @Date: 2021-01-15 19:32:12
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-15 19:58:58
 * @FilePath: \Ch10\ch10_ex08.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chapter 10, exercise 08: take two file names, produce file that is content
    of the first file, followed by content of the second file
    Use ex08_in1.txt and ex08_in2.txt for input
*/

#include "../includes/std_lib_facilities.h"

int main()
try {
    string s1, s2;
    cout << "输入文件1和文件2的名称: ";
    cin >> s1 >> s2;
    string out_file = "ex08_out.txt";

    ifstream ifs1(s1.c_str());
    if (!ifs1) error("cannot open input file ", s1);
    ifstream ifs2(s2.c_str());
    if (!ifs2) error("cannot open input file ", s2);
    ofstream ofs(out_file.c_str());
    if (!ofs) error("cannot open output file ", out_file);

    char ch;
    while (ifs1.get(ch)) ofs << ch;
    while (ifs2.get(ch)) ofs << ch;
    system("pause");
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
