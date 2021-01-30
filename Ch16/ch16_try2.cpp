/*
 * @Author: seenli
 * @Date: 2021-01-30 14:06:34
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-30 14:22:42
 * @FilePath: \Ch16\ch16_try2.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 16, Try This 1: test two different definitions of the find algorithm

#include "../includes/std_lib_facilities.h"

template<class In, class T>
In find1(In first, In last, const T& val) {
    while (first != last && *first != val) ++first;
    return first;
}

template<class In, class T>
In find2(In first, In last, const T& val) {
    for (In p = first; p != last; ++p)
        if (*p == val) return p;
    return last;
}

int main()
try {
    vector<int> vi;
    for (int i = 0; i<25; ++i) {
        vi.push_back(randint(50));
        cout << vi[i] << ' ';
    }
    cout << "\n";
    int idx = randint(vi.size());
    cout << "Looking for " << vi[idx] << ":\n";
    vector<int>::iterator v_iter1 = find1(vi.begin(),vi.end(),vi[idx]);
    vector<int>::iterator v_iter2 = find2(vi.begin(),vi.end(),vi[idx]);
    while (v_iter1!=vi.end()) {
        cout << *v_iter1 << '/' << *v_iter2 << ' ';
        ++v_iter1;
        ++v_iter2;
    }
    cout << "\n";
    system("pause");
    return 0;
}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
    keep_window_open();
	return 1;
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