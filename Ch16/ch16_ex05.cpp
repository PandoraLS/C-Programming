/*
 * @Author: seenli
 * @Date: 2021-01-30 15:34:13
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-30 15:49:11
 * @FilePath: \Ch16\ch16_ex05.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 16, Exercise 5: redesign and reimplement find() and count() to take
// iterators to first and last elements (no end()), compare results to the
// standard versions - can't return iterator to end() if not found

#include "../includes/std_lib_facilities.h"

// return iterator to first occurrence of val in [first,last]; if element is not
// found, return iterator to first - user has to check if first contains the
// value or not
template<class In, class T>
In my_find(In first, In last, const T& val) {
    In p = first;
    while (p != last) {
        if (*p == val) return p;
        ++p;
    }

    // 检查最后一个元素
    if (*p == val) return p;
    return first;               // 未发现val, 必须检查 *first是否等于val
}

// 返回val在[first,last]中出现的次数
template<class In, class T>
int my_count(In first, In last, const T& val) {
    int count = 0;
    while (first != last) {
        if (*first == val) ++count;
        ++first;
    }
    if (*first == val) ++count;
    return count;
}

int main()
try {
    vector<int> vi;
    for (int i = 0; i<10; ++i)
        vi.push_back(randint(10));

    typedef vector<int>::iterator vi_it;

    cout << "vi:\n";
    for (vi_it it = vi.begin(); it<vi.end(); ++it)
        cout << *it << '\n';

    cout << "Enter int to search for and count (-1 to quit): ";
    int n;
    while (cin>>n) {
        if (n==-1) break;
        vi_it it = my_find(vi.begin(),vi.end()-1,n);
        int count = my_count(vi.begin(),vi.end()-1,n);
        if (it==vi.begin() && *it!=n) cout << n << " is not in vi. Next int: ";
        else cout << n << " is at index " << it-vi.begin()
            << " (occurs " << count << " time" << (count==1 ? "" : "s")
            << "). Next int: ";
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