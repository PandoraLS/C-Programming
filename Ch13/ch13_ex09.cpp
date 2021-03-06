/*
 * @Author: seenli
 * @Date: 2021-01-24 20:43:00
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-24 20:51:11
 * @FilePath: \Ch13\ch13_ex09.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 13, exercise 09: write program that tells the order in which static
// storage, the stack and the free store are laid out. Does stack grow upward
// or downward? In an array on free store, are elements with higher indices
// allocated at higher or lower addresses?

#include "../includes/std_lib_facilities.h"

// static storage
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;

int main()
try {
    // static storage
    int* pa = &a;
    int* pb = &b;
    int* pc = &c;
    int* pd = &d;
    int* pe = &e;

    cout << pa << "\n"
        << pb << "\n"
        << pc << "\n"
        << pd << "\n"
        << pe << "\n";
    
    if (pe > pd) cout << "static storage grows upwards\n";

    // stack
    int sa = 0;
    int sb = 0;
    int sc = 0;
    int* psa = &sa;
    int* psb = &sb;
    int* psc = &sc;
    cout << "\n" << psa << "\n" << psb << "\n" << psc << "\n";
    if (psc < psb) cout << "Stack grows downwards\n";

    // free store / heap
    int* ha = new int(0);
    int* hb = new int(0);
    int* hc = new int(0);
    cout << "\n" << ha << "\n" << hb << "\n" << hc << "\n";
    if (hc>hb) cout << "Heap grows upwards\n";

    // array on free store
    int* harr = new int[5];
    cout << "\n";
    for (int i = 0; i<5; ++i) {
        harr[i] = 0;
        cout << &harr[i] << "\n";
    }
    if (&harr[4]>&harr[3]) cout << "Arrays on free store grow upwards\n";
    delete[] harr;
    delete hc;
    delete hb;
    delete ha;
    

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