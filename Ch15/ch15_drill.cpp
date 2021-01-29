/*
 * @Author: seenli
 * @Date: 2021-01-27 21:10:45
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-28 11:25:06
 * @FilePath: \Ch15\ch15_drill.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// chapter 15, Drill

#include "../includes/std_lib_facilities.h"

// 6
template<class Iter1, class Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2) {
    while (f1 != e1) {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}

template<class Iter>
void print(Iter f, Iter e, const string& s) {
    cout << s << ": { ";
    while (f != e) {
        cout << *f << ' ';
        ++f;
    }
    cout << "}\n";
}


int main()
try {
    // 1
    const int arr_sz = 10;
    array<int, arr_sz> ai;
    for (int i = 0; i < ai.size(); ++i) ai[i] = i;
    print(ai.begin(), ai.end(), "ai");

    // 2
    vector<int> vi;
    for (int i = 0; i < arr_sz; ++i) vi.push_back(i);
    print(vi.begin(), vi.end(), "vi");

    // 3
    list<int> li;
    for (int i = 0; i < arr_sz; ++i) li.push_back(i);
    print(li.begin(), li.end(), "li");

    // 4
    array<int, arr_sz> ai_cp = ai;
    print(ai_cp.begin(), ai_cp.end(), "ai_cp");
    vector<int> vi_cp = vi;
    print(vi_cp.begin(), vi_cp.end(), "vi_cp");
    list<int> li_cp = li;
    print(li_cp.begin(), li_cp.end(), "li_cp");

    // 5
    for (array<int, arr_sz>::iterator p = ai.begin(); p != ai.end(); ++p) {
        *p += 2;
    }
    print(ai.begin(), ai.end(), "ai += 2");

    for (vector<int>::iterator p = vi.begin(); p != vi.end(); ++p) {
        *p += 3;
    }
    print(vi.begin(), vi.end(), "vi += 3");

    for (list<int>::iterator p = li.begin(); p != li.end(); ++p) {
        *p += 5;
    }
    print(li.begin(), li.end(), "li += 5");

    // 7
    vector<int>::iterator v_it = my_copy(ai.begin(), ai.end(), vi.begin());
    array<int, arr_sz>::iterator a_it = my_copy(li.begin(), li.end(), ai.begin());

    if (v_it != vi.begin() && a_it != ai.begin()) {
        print(vi.begin(), vi.end(), "vi copied from ai");
        print(ai.begin(), ai.end(), "ai copied from li");
        print(li.begin(), li.end(), "li");
    }

    //8
    v_it = find(vi.begin(), vi.end(), 3);
    if (v_it != vi.end()) {
        cout << "In vi, 3 has index " << v_it-vi.begin() << ".\n";
    }

    list<int>::iterator l_it = find(li.begin(), li.end(), 27);

    if (l_it != li.end()) {
        int idx = 0;
        for (list<int>::iterator iter = li.begin(); iter != l_it; ++iter) {
            ++idx;
        }
        cout << "In li, 27 has index " << idx << ".\n";
    } else {
        cout << "27 is not in li.\n";
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
