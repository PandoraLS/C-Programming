/*
 * @Author: seenli
 * @Date: 2021-01-28 11:54:21
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-28 14:12:58
 * @FilePath: \Ch15\ch15_try7.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 15, Try This 7: create a char[], vector<char>, list<char> and string,
// each with the value "Hello". Pass it as an argument to a function, write out
// the number of characters in the string passed, try to compare it to "Hello"
// and compare the argument to "Howdy" to see which would come first in a dic-
// tionary. Copy the argument into another variable of the same type.

// Could be improved by using an array adapted to STL conventions and having a
// single functions doing the four tests, similar to the single function compa-
// ring the containers to another string.

#include "../includes/std_lib_facilities.h"
#include <cstring>

template<class T>
int cmp_to_str(const T& lhs, const string& rhs) {
    int i = 0;
    for (typename T::const_iterator p = lhs.begin(); p != lhs.end() && i < rhs.size(); ++p) {
        if (*p < rhs[i]) return -1;
        if (*p > rhs[i]) return 1;
        ++i;
    }
    if (lhs.size() < rhs.size()) return -1;
    if (lhs.size() > rhs.size()) return 1;
    return 0;
}

// array compare
void ac_func(const char ac[]) {
    // get length
    cout << "length of ac[]: " << strlen(ac) << "\n";

    // compare to "Hello"
    if (strcmp(ac, "Hello") == 0) cout << "ac == \"Hello\"\n";

    // compare to "Howdy"
    int comp = strcmp(ac, "Howdy");
    switch (comp) {
        case -1:
            cout << "ac < \"Howdy\"\n";
            break;
        case 0:
            cout << "ac == \"Howdy\"\n";
            break;
        case 1:
            cout << "ac > \"Howdy\"\n";
            break;
        default:
            error("Illegal value");
    }

    // 复制到另一个变量
    char ac_cp[6];                          // size of array must be known
    strcpy(ac_cp, ac);
}

// vector compare
void vc_func(const vector<char>& vc) {
    cout << "length of vc: " << vc.size() << "\n";
    if (cmp_to_str(vc, "Hello") == 0) cout << "vc == \"Hello\"\n";
    int comp = cmp_to_str(vc, "Howdy");
    switch(comp) {
        case -1:
        cout << "vc < \"Howdy\"\n";
        break;
    case 0:
        cout << "vc == \"Howdy\"\n";
        break;
    case 1:
        cout << "vc > \"Howdy\"\n";
        break;
    default:
        error("Illegal value");
    }
    vector<char> vc_cp = vc;
}

// list compare
void lc_func(const list<char>& lc) {
    cout << "length of lc: " << lc.size() << "\n";
    if (cmp_to_str(lc, "Hello") == 0) cout << "lc == \"Hello\"\n";
    int comp = cmp_to_str(lc, "Howdy");
    switch(comp) {
        case -1:
        cout << "lc < \"Howdy\"\n";
        break;
    case 0:
        cout << "lc == \"Howdy\"\n";
        break;
    case 1:
        cout << "lc > \"Howdy\"\n";
        break;
    default:
        error("Illegal value");
    }
    list<char> lc_cp = lc;
}

// string compare
void sc_func(const string& sc) {
    cout << "Length of sc: " << sc.size() << "\n";
    if (sc == "Hello") cout << "sc == \"Hello\"\n";
    if (sc < "Howdy") cout << "sc < \"Howdy\"\n";
    string sc_cp = sc;
}

int main()
try {
    
    char ac[] = "Hello";
    ac_func(ac);
    cout << "\n";

    vector<char> vc;
    vc.push_back('H');
    vc.push_back('e');
    vc.push_back('l');
    vc.push_back('l');
    vc.push_back('o');
    vc_func(vc);
    cout << "\n";

    list<char> lc;
    lc.push_back('H');
    lc.push_back('e');
    lc.push_back('l');
    lc.push_back('l');
    lc.push_back('o');
    lc_func(lc);
    cout << "\n";

    string sc = "Hello";
    sc_func(sc);
    cout << "\n";
    
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
