/*
 * @Author: seenli
 * @Date: 2021-01-30 16:39:26
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-30 16:50:59
 * @FilePath: \Ch16\ch16_ex08.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 16, Exercise 8: take word frequency example from 21.6.1 and modify
// it to output its lines in order of frequency rather than lexicographical
// order ("3: C++" rather than "C++: 3")

#include "../includes/std_lib_facilities.h"
#include <map>

int main()
try {
    map<string, int> words;

    const string ifname = "ex08_in.txt";
    ifstream ifs(ifname.c_str());
    if (!ifs) error("could not open ", ifname);
    string s;
    while (ifs >> s) ++words[s];

    vector<pair<int, string>> v_words;

    typedef map<string, int>::const_iterator Iter;
    for (Iter p = words.begin(); p != words.end(); ++p)
        v_words.push_back(make_pair(p->second, p->first));

    sort(v_words.begin(), v_words.end());

    typedef vector<pair<int, string>>::const_iterator v_iter;
    for (v_iter p = v_words.begin(); p != v_words.end(); ++p) {
        cout << p->first << ": " << p->second << endl;
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
