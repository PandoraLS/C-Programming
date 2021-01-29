/*
 * @Author: seenli
 * @Date: 2021-01-28 14:17:31
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-28 14:32:00
 * @FilePath: \Ch15\ch15_try8.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 15, Try This 8: same as Try This 7, but with an array of int, a
// vector<int> and a list<int>, with the value { 1, 2, 3, 4, 5 }.

#include "../includes/std_lib_facilities.h"

// 当数组衰减为指针时, 需要数组的大小
void ai_func(const int ai[], int sz) {
	cout << "Number of elements in ai: " << sz << endl;
}

void vi_func(const vector<int>& vi) {
	cout << "Number of elements in vi: " << vi.size() << endl;
}

void li_func(const list<int>& li) {
	cout << "Number of elements in li: " << li.size() << endl;
}

int main()
try {
    int ai[] = {1, 2, 3, 4, 5};
	ai_func(ai, sizeof(ai)/ sizeof(*ai));

	vector<int> vi;
	for (int i = 1; i < 6; ++i) {
		vi.push_back(i);
	}
	vi_func(vi);

	list<int> li;
	for (int i = 1; i < 6; ++i) {
		li.push_back(i);
	}
	li_func(li);

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