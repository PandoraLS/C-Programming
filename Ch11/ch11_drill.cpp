/*
 * @Author: seenli
 * @Date: 2021-01-18 17:15:22
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-18 17:50:18
 * @FilePath: \Ch11\ch11_drill.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, drill

#include "../includes/std_lib_facilities.h"

void int_output() {
    cout << showbase << "Birth year: " << endl
        << 1980 << "\t(decimal)" << endl
        << hex << 1980 << "\t(hexadecimal)" << endl
        << oct << 1980 << "\t(octal)" << endl;
}

void int_input() {
    int a{}, b{}, c{}, d{};
    cin >> a >> hex >> b >> oct >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << endl;
}

void float_output() {
    cout << 1234567.89 << "\t(general)\n"
        << fixed << 1234567.89 << "\t(fixed)\n"
        << scientific << 1234567.89 << "\t(scientific)\n";
}

int main()
try {
    int_output();
    cout << "==================================================================" << endl;
    int_input();
    cout << "==================================================================" << endl;
    float_output();
    cout << "==================================================================" << endl;

    cout << setw(10) << "Wuethrich" << " | " << "Benjamin" << " | "
        << setw(16) << "+1345 326 5181" << " | " << setw(29) << "benjamin.wuethrich@gmail.com" << endl
        << setw(10) << "Forrest" << " | " << setw(8) << "Kara" << " | "
        << setw(16) << "+1345 516 1920" << " | " << setw(29) << "kara_forrest@hotmail.com" << endl
        << setw(10) << "Aarnau" << " | " << setw(8) << "Mayra" << " | "
        << "+34 66 696 55 63" << " | " << setw(29) << "mayraaachen@hotmail.com" << endl
        << setw(10) << "Michel" << " | " << setw(8) << "Tanael" << " | "
        << "+41 79 374 48 62" << " | " << setw(29) << "tanael@gmail.com" << endl
        << setw(10) << "Widler" << " | " << setw(8) << "Andrea" << " | "
        << "+41 79 293 29 38" << " | " << setw(29) << "andreawidler@bluewin.ch" << endl
        << "Amanatidou" << " | " << "Elisabet" << " | "
        << "+41 76 701 61 28" << " | " << "elisabet.amanatidou@gmail.com" << endl;
    
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
