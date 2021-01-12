/*
 * @Author: seenli
 * @Date: 2021-01-12 13:52:38
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-12 14:09:40
 * @FilePath: \Ch10\ch10_ex01.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chaper 10, exercise 01: 
    produce sum of numbers in file of whitespace-separated integers
    Use ch10_ex01_in.txt for input
*/

#include "../includes/std_lib_facilities.h"

// 从文件中读取空格隔开的整数
void read_ints(vector<int>& ints, const string& name) {
    ifstream ist(name.c_str());
    if (!ist) {
        error("cannot open input file ", name);
    }
    int n;
    while (ist >> n) {
        ints.push_back(n);
    }
}

// vector elements 求和
int get_sum(const vector<int>& v) {
    int sum {0};
    for (int i{0}; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}



int main()
try {
    cout << "Enter file name: \n";
    string iname;
    cin >> iname;
    vector<int> ints;
    read_ints(ints, iname);
    int sum = get_sum(ints);
    cout << "Sum of intergers in " << iname << " is " << sum << ".\n";
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