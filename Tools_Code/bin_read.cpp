/*
 * @Author: seenli
 * @Date: 2021-01-19 15:06:01
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 15:15:52
 * @FilePath: \Tools_Code\ch11_ex09.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// 二进制文件读取
// Chapter 11, exercise 09: convert a text file to a binary file and back
// Use ex09_in.txt for input


#include "std_lib_facilities.h"

const string bin_file = "ex09_bin.dat";             // 二进制文件名

// 将txt文件转为二进制文件
void to_binary(const string& s) {
    ifstream ifs(s.c_str());
    if (!ifs) error("cannot open input file ", s);
    ofstream ofs(bin_file.c_str(), ios_base::binary);
    if (!ofs) error("cannot open output file ", bin_file);

    char ch;
    while (ifs.get(ch)) {
        ofs.write(as_bytes(ch), sizeof(char));
    }
}

// 将二进制文件转换为txt文件s
void from_binary(const string& s) {
    ofstream ofs(s.c_str());
    if (!ofs) error("cannot open output file ", s);
    ifstream ifs(bin_file.c_str(), ios_base::binary);
    if (!ifs) error("cannot open input file ", bin_file);
    
    char ch;
    while (ifs.read(as_bytes(ch), sizeof(char))) {
        ofs << ch;
    }
}

int main()
try {
    string iname{"ex09_in.txt"};
    to_binary(iname);

    string oname{"ex09_out.txt"};
    from_binary(oname);
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