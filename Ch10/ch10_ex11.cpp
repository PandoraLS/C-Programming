/*
 * @Author: seenli
 * @Date: 2021-01-15 20:56:22
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-15 21:25:10
 * @FilePath: \Ch10\ch10_ex11.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chapter 10, exercise 11: produce sum of all whitespace-separated integers in
    input text file
    Use ex11_in.txt for input
*/

#include "../includes/std_lib_facilities.h"

// 定义空白符
bool whitespace(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n');
}

int main()
try {
    string ifname;
    cout << "输入文件名称: ";
    cin >> ifname;
    ifstream ifs(ifname.c_str());
    if (!ifs) error("cannot open input file ", ifname);

    int sum{}, i{}, count{};
    char ch{};
    string s;
    while (ifs >> ch) {
        if (isdigit(ch)) {
            ifs.unget();
            if (ifs >> i) {
                if (ifs.eof() || (ifs.get(ch) && whitespace(ch))) {
                    ++count;
                    sum += i;
                    cout << i << endl;
                } else {
                    ifs.unget();
                    ifs >> s;                       // 读取字符串, 不是一个单独的整数
                }
            } else {
                error("cannot read integer");
            }
        } else {
            ifs.unget();
            ifs >> s;
        }
    }
    cout << "Sum of " << count << " whitespace-separated integers in file: " << sum << endl;
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