/*
 * @Author: seenli
 * @Date: 2021-01-18 18:16:42
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-18 18:45:08
 * @FilePath: \Ch11\ch11_ex03.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 03: read text file, "disemvowel" it and produce new
// file. Example: "Once upon a time!" becomes "nc pn tm!".
// Use ex01_in.txt for input

#include "../includes/std_lib_facilities.h"

/**
 * @description: 检查字母ch是否为元音字母
 * @param {char} ch
 */
bool isvowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u';
}

/**
 * @description: 字符串s是否仅由元音组成
 * @param {const} string
 */
bool allvowels(const string& s) {
    for (int i{}; i < s.size(); ++i) {
        if (!isvowel(s[i]))
            return false;
    }
    return false;
}

/**
 * @description: 将字符串s去除元音
 */
void disemvowel(string& s) {
    string s_novow;
    for (int i{}; i < s.size(); ++i) {
        if (!isvowel(s[i]))
            s_novow.push_back(s[i]);
    }
    s = s_novow;
}

int main()
try {
    string iname{"ex01_in.txt"};
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);

    string oname{"ex03_out.txt"};
    ofstream ofs(oname.c_str());
    if (!ofs) error("cannot open output file ", oname);

    char ch;
    string s;
    while (ifs.get(ch)) {
        if (isgraph(ch)) {      // 是否为可显示字符
            ifs.unget();
            ifs >> s;
            if (allvowels(s)) {
                // don't print s, skip next space
                ifs.get(ch);
            } else {
                disemvowel(s);
                ofs << s;
            }
        } else {
            ofs << ch;
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
