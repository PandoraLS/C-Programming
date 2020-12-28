/*
 * @Author: seenli
 * @Date: 2020-12-28 13:41:30
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-28 15:00:14
 * @FilePath: \Ch06\ch06_ex10.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
Section 6 exercise 10
Ask user for 2 numbers.
Ask if want to do permutation or combination
p(a,b) = a!/(a-b)!
c(a,b) = p(a,b)/b!
https://www.mathsisfun.com/combinatorics/combinations-permutations.html
*/

#include "std_lib_facilities.h"

/**
 * @description: �����start��end�Ľ׳�, start > end
 * @param {int} start   �׳˵����
 * @param {int} end     �׳˵��յ�
 */
int factoral(int start, int end) {
    int fact{1};
    for (auto i{start}; i > (start - end); --i) {
        fact *= i;
        if ((i > 0 && fact > numeric_limits<int>::max() - i) ||
            (i < 0 && fact < numeric_limits<int>::min() - i)) {
                error("int overflow error");
            }
    }
    return fact;
}

/**
 * @description: ��a��Ԫ���г�ȡb��Ԫ�أ�����
 * @param {int} a
 * @param {int} b
 */
int permutation(int a, int b) {
    if (a <= 0 || (a - b) < 0) {
        error("Negative term in pernutaition.\n");
    }
    return factoral(a, b);
}

/**
 * @description: ��a��Ԫ���г�ȡb��Ԫ�أ����
 * @param {int} a
 * @param {int} b
 */
int combination(int a, int b) {
    int c{permutation(a, b) / factoral(b, b)};
    return c;
}

int main()
try {
    cout << "��������number, ��һ��num��Ҫ���ڵڶ���num. \n";
    int a{}, b{};
    while (!(cin >> a && cin >> b && (a > b))) {
        cout << "��Ч������һ��number�����ڵڶ���number\n";
        cin.clear();
        cin.sync_with_stdio(false);
        cin.ignore(cin.rdbuf()->in_avail());
    }

    cout << "����or���? ����������'p', ���������'c'\n";
    char p_c{};
    while (cin >> p_c) {
        p_c = narrow_cast<char, int>(tolower(p_c));
        if (p_c != 'p' && p_c != 'c') {
            cout << "��Ч�������, ����������\n";
        } else {
            break;
        }
    }

    int answer{};
    if (p_c == 'p') {
        answer = permutation(a, b);
    } else if (p_c == 'c') {
        answer = combination(a, b);
    } else {
        error("Invalid evaluation choice \n");
    }
    cout << "The " << (p_c == 'p' ? "permutation" : "combination") << " is " << answer << endl;
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}

catch (...) {
    cerr << "Unknown error" << endl;
    keep_window_open();
    return 2;
}

