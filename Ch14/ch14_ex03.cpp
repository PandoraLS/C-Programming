/*
 * @Author: seenli
 * @Date: 2021-01-26 16:25:01
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-26 17:33:24
 * @FilePath: \Ch14\ch14_ex03.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 19, exercise 03: template class Pair to hold pair of values of any
// type; use to implement symbol table like the one used in calculator (ch7.8)

#include "../includes/std_lib_facilities.h"

template<class T, class U> struct Pair {
    Pair(T vt, U vu): val1(vt), val2(vu) { }
    T val1;
    U val2;
};

class Symbol_table {
    vector<Pair<string, double>> var_table;
    public:
        double get(string s);                   // return the value of the Variable named s
        void set(string s, double d);           // set the Variable named s to d
        bool is_declared(string var);           // is var already in var_table?
        double declare(string var, double val); // add (var,val) to var_table
        void print();                           // print table
};

double Symbol_table::get(string s) {
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].val1 == s) return var_table[i].val2;
    error("Variable not found: ", s);
}

void Symbol_table::set(string s, double d) {
    for (int i = 0; i < var_table.size(); ++i) {
        if (var_table[i].val1 == s) {
            var_table[i].val2 = d;
            return;
        }
    }
    error("Variable not found: ", s);
}

bool Symbol_table::is_declared(string s) {
    for (int i = 0; i < var_table.size(); ++i) {
        if (var_table[i].val1 == s) return true;
    }
    return false;
}

double Symbol_table::declare(string s, double d) {
    if (is_declared(s)) error("variable exists already: ", s);
    var_table.push_back(Pair<string, double>(s, d));
    return d;
}

void Symbol_table::print() {
    for (int i = 0; i < var_table.size(); ++i) {
        cout << var_table[i].val1 << ": " << var_table[i].val2 << endl;
    }
}

int main()
try {
    Symbol_table st;
    st.declare("Pi", 3.14);
    st.declare("e", 2.72);
    st.print();
    cout << "Pi is " << st.get("Pi") << endl;
    if (st.is_declared("Pi")) {
        cout << "Pi is declared\n";
    } else {
        cout << "Pi is not declared\n";
    }

    if (st.is_declared("nd")) {
        cout << "nd is declared\n";
    } else {
        cout << "nd is not declared\n";
    }

    st.set("Pi", 4.14);
    cout << "Pi is now " << st.get("Pi") << endl;
    
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