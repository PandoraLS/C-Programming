/*
 * @Author: seenli
 * @Date: 2021-01-23 17:20:11
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-24 11:26:40
 * @FilePath: \Ch13\ch13_ex01.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 13
// Exercise 01: function that copies C-style string into heap
// without standard library functions, no subscripting (use dereference
// operator)

// Exercise 02: function that finds first occurrence of C-style string in other
// C-style string withouth standard library functions and subscripting

// Exercise 03: function that compares two C-style strings lexicographically,
// returns -1 if s1 < s2, 0 if s1 == s2, 1 if s1 > s2. Not stdlib functions,
// no subscripting

#include "../includes/std_lib_facilities.h"

char* strdupl(const char* s) {
    // 获取s的size
    int i{};
    const char* p = s;
    while (*p++) ++i;

    // 分配一个新的string, 并为终止符0留一个空位
    char* s_cpy = new char[i + 1];

    // copy s, 添加终止符0
    char* s_cpy_ptr = s_cpy;
    while (*s) *s_cpy_ptr++ = *s++;
    *s_cpy_ptr = 0;
    return s_cpy;
}

char* findx(const char* s, const char* x) {
    if (x == 0 || !*x) return const_cast<char*>(s);
    if (s == 0 || !*s) return 0;

    for (int i{}; *(s + i); ++i) {
        if (*(s + i) == *x) {                                               // 定位第一个匹配的字符
            for (int j{}; *(x + j); ++j) {                                  // 循环子串
                if (!*(s + i + j)) return 0;                                // 到达s的end(发现子串的0结束符)
                if (*(s + i + j) != *(x + j)) break;                        // x not found
                if (!*(x + j + 1)) return const_cast<char*>(s + i);         // found x
            }
        }
    }
    return 0;                                                               // 达到s的end
}

int strcomp(const char* s1, const char* s2) {
    if (s1 == 0 || s2 == 0) error("Null pointer sent to strcomp()");
    for (int i = 0; *(s1 + i); ++i) {
        // if only s1 ends or s1[i]<s2[i], s1<s2
        if (*(s1 + i) == 0 && *(s2 + i) || *(s1 + i) < *(s2 + i)) return -1;

        // if only s2 ends or s1[i]>s2[i], s1>s2
        if (*(s2 + i) == 0 && *(s1 + i) || *(s1 + i) > *(s2 + i)) return 1;
    }
    
    // s1 and s2 are identical
    return 0;
}

void print_str(const char* s) {
    if (s == 0) error("cannot print from null pointer");
    while (*s) cout << *s++;
}

int main()
try {
    // test exercise 1
    char s[] = "Test";
    char* s_cpy = strdupl(s);
    print_str(s_cpy);
    cout << "\n";
    delete[] s_cpy;

    // test exercise 2
    char s2[] = "This is a test phrase";
    char x[] = "test";
    cout << "s: " << s2 << "\n";
    cout << "x: " << x << "\n";
    print_str(findx(s2, x));
    cout << "\n";

    // test exercise 3
    const int max = 5;
    char a[max], b[max];
    cout << "输入的a.size和b.size必须小于等于5\n";
    while (cin >> a >> b) {
        int comp = strcomp(a, b);
        switch (comp) {
            case -1:
                cout << a << " < " << b << endl;
                break;
            case 0:
                cout << a << " == " << b << endl;
                break;
            case 1:
                cout << a << " > " << b << endl;
                break;
            default:
                error("invalid result returned by strcomp");
                break;
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
