/*
 * @Author: seenli
 * @Date: 2021-01-19 18:43:09
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 18:47:00
 * @FilePath: \Ch11\ch11_ex14.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 14: read text file, write out how many characters of
// each character classification are in the file
// Use macbeth.txt for input


#include "../includes/std_lib_facilities.h"

int main()
try {
    string iname{"macbeth.txt"};
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);

    // read file into string
    char ch;
    int space = 0;                          // 字符类型计数器
    int alpha = 0;
    int digit = 0;
    int xdigit = 0;
    int upper = 0;
    int lower = 0;
    int alnum = 0;
    int cntrl = 0;
    int punct = 0;
    int print = 0;
    int graph = 0;

    while (ifs.get(ch)) {
        if (isspace(ch)) ++space;
        if (isalpha(ch)) ++alpha;
        if (isdigit(ch)) ++digit;
        if (isxdigit(ch)) ++xdigit;
        if (isupper(ch)) ++upper;
        if (islower(ch)) ++lower;
        if (isalnum(ch)) ++alnum;
        if (iscntrl(ch)) ++cntrl;
        if (ispunct(ch)) ++punct;
        if (isprint(ch)) ++print;
        if (isgraph(ch)) ++graph;
    }

    cout << "Analysis:\n";
    cout << "isspace:\t" << space << endl;
    cout << "isalpha:\t" << alpha << endl;
    cout << "isdigit:\t" << digit << endl;
    cout << "isxdigit:\t" << xdigit << endl;
    cout << "isupper:\t" << upper << endl;
    cout << "islower:\t" << lower << endl;
    cout << "isalnum:\t" << alnum << endl;
    cout << "iscntrl:\t" << cntrl << endl;
    cout << "ispunct:\t" << punct << endl;
    cout << "isprint:\t" << print << endl;
    cout << "isgraph:\t" << graph << endl;


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