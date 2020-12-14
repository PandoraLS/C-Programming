/*
 * @Author: seenli
 * @Date: 2020-12-14 19:07:48
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-14 20:03:07
 * @FilePath: \Ch06\ch06_6_6_try.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

class Token {
    public:
        char kind;          // kind of token
        double value;       // for numbers: a value
        Token(char ch, double val = 0.0):kind(ch), value(val) {}
};

Token get_token();
double expression();        // read and evaluate a Expression
double term();              // read and evaluate a Term
double primary();           // read and evaluate a Primary

int main()
try {
    while(cin) {
        cout << "=" << expression() << endl;
    }
    keep_window_open();
    return 0;
}

catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}

catch (...) {
    cerr << "unknown exception \n";
    keep_window_open();
    return 2;
}

double expression() {
    double left = term();           // ��ȡ�ͼ���һ��Term
    Token t = get_token();          // ��ȡ��һ��token
    while (true) {
        switch (t.kind)
        {
        case '+':
            left += term();         // ����Term��add
            t = get_token();
            break;
        case '-':
            left -= term();         // ����Term��subtract
            t = get_token();
            break;
        default:
            return left;            // û��+��-������£�����left
        }
    }
}

double term() {
    double left = primary();
    Token t = get_token();

    while (true) {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
            {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = get_token();
                break;
            }
        default:
            return left;
        }
    }
}

double primary() {
    Token t = get_token();
    double temp{};
    switch (t.kind)
    {
    case '(':
        {
            double d = expression();
            t = get_token();
            if (t.kind != ')') error("')' expected");
            temp = d;
            break;
        }
    case '8':               // we use '8' to represent a number
        temp = t.value;     // return the number's value
        break;
    default:
        error("primary excepted");
    }
    return temp;
}

Token get_token() {
    char ch;
    cin >> ch;              // >> �������հ׷�(�ո񡢻��з���tab��)
    Token temp{' '};
    switch (ch)
    {
    case '(': case ')': case '+': case '-': case '*': case '/':
        temp.kind = ch;
        break;
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);        // �����ַŻ���������
        double val;
        cin >> val;
        temp.kind = '8';        // ʹ�� '8' ����ʾ һ������
        temp.value = val;
        break;
    }
    default:
        error("Bad token");
    }
    return temp;
}


