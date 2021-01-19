/*
 * @Author: seenli
 * @Date: 2021-01-19 15:06:01
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 15:13:57
 * @FilePath: \Ch11\ch11_ex09.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 09: convert a text file to a binary file and back
// Use macbeth.txt for input


#include "../includes/std_lib_facilities.h"

const string bin_file = "ex09_bin.dat";             // �������ļ���

// ��txt�ļ�תΪ�������ļ�
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

// ���������ļ�ת��Ϊtxt�ļ�s
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
    string iname{"macbeth.txt"};
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