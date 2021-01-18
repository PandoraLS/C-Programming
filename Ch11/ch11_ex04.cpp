/*
 * @Author: seenli
 * @Date: 2021-01-18 18:58:42
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-18 20:28:49
 * @FilePath: \Ch11\ch11_ex04.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 04: prompt user to enter several integers in any
// combination of octal, decimal and hexadecimal using the 0 and 0x prefixes,
// interpret them correctly and convert the to decimal form. Output values
// properly spaced like this:
// 0x43 hexadecimal converts to     67 decimal
// 0123 octal       converts to     83 decimal
//   65 decimal     converts to     65 decimal

#include "../includes/std_lib_facilities.h"

// ö�����ֽ���
enum num_format {decimal, octal, hexadecimal};

ostream& operator<<(ostream& os, num_format nf) {
    switch (nf) {
        case decimal:
            return os << "decimal\t";
        case octal:
            return os << "octal\t";
        case hexadecimal:
            return os << "hexadecimal";
        default:
            error("number_format �Ƿ�");
    }
}

// print one line of the solution
void printnum(int n, num_format nf) {
    cout << showbase;
    switch (nf) {
        case decimal:
            cout << dec << setw(6) << n;
            break;
        case octal:
            cout << oct << setw(6) << n;
            break;
        case hexadecimal:
            cout << hex << setw(6) << n;
            break;
    }
    cout << ' ' << nf << "\tconverts to " << dec << setw(6) << n << ' ' << decimal << endl;
}

int main()
try {
    cout << "Enter space-separated integers in decimal, octal or hexadecimal notation" << endl
        << "(using 0 and 0x prefixes), any letter to finish. Ctrl+Z ����" << endl;
    int n{};
    char ch;
    while (cin >> ch) {
        if (ch == '0') {
            cin.get(ch);
            if (ch == 'x') {                // '0x'ǰ׺ -- ʮ������
                cin >> hex >> n;
                printnum(n, octal);
            } else if (isdigit(ch)) {       // '0'ǰ׺ -- �˽��� 
                cin.unget();
                cin >> oct >> n;
                printnum(n, octal);
            } else {
                cin.unget();                // '0'ǰ׺��û������ -- �˽��Ƶ�0
                printnum(0, octal);
            }
        } else if (isdigit(ch)) {           // ʮ����
            cin.unget();
            cin >> dec >> n;
            printnum(n, decimal);
        } else {
            break;                          // ������
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
