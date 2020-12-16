/*
 * @Author: seenli
 * @Date: 2020-12-15 21:07:44
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-16 13:58:52
 * @FilePath: \Ch06\ch06_ex02.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/**
Section 6 exercise 2
Add the ability to use {}
*/

#include "std_lib_facilities.h"

class Token {
    public:
        char kind;                                      // kind of token
        double value;                                   // for number: a value

        // ���캯��
        Token(char ch): kind(ch), value(0) {}
        Token(char ch, double val): kind(ch), value(val) {}
};

class Token_stream {
    public:
        Token_stream(): full(false), buffer(' ') {}
        Token get();                                    
        void putback(Token t);
    private:
        bool full;
        Token buffer;  
};

// putback() ������������Żص�Token_stream buffer
void Token_stream::putback(Token t) {
    if (full) {
        error("putback() into a full buffer");
    }
    buffer = t;                                         // �� t ������ buffer
    full = true;                                        // buffer �� full
}

Token Token_stream::get() {
    Token temp{' '};

    // do we already have a Token ready?
    if (full) {
        full = false;
        temp = buffer;
    } else {
        char ch;
        cin >> ch;
        switch (ch)
        {
        case ';':                                       // ���
        case 'q':                                       // quit
        case '{': case '}':
        case '(': case ')': case '+': case '-': case '*': case '/':
            temp.kind = ch;
            break;
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);                            // ��digit�Ż�������
            double val;
            cin >> val;
            temp.kind = '8';
            temp.value = val;
            break;
        }
        default:
            error("Bad token");
        }
    }
    return temp;
}

Token_stream ts;

double expression();                                    // ����֮��primary() �Ϳ��Ե��� expression() ������

// ���� ���� �� Բ����
double primary() {
    double temp{};                                      // ����洢result
    Token t = ts.get();
    switch (t.kind)
    {
    case '{':                                           // ���� '{' expression '}'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}') {
                error("'}' expected");
            }
            temp = d;
            break;
        }
    case '(':                                           // ���� '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') {
                error("')' expected");
            }
            temp = d;
            break;
        }
    case '-':                                           // ���� - һԪ�����
        temp = -1 * primary();
        break;
    case '+':
        temp = primary();                               // ���� + һԪ�����
        break;
    case '8':                                           // ʹ�� '8' ������number
        temp = t.value;                                 // ����num����ֵ
        break;
    default:
        error("primary expected");
    }
    return temp;
}

// ���� * �� /, ��δʵ�� % 
double term() {
    double left = primary();
    Token t = ts.get();                                 // ��token���л�ȡ��һ��token
    while (true) {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
        default:
            ts.putback(t);                              // �� t �Ż�token ����
            return left;
        }
    }
}


// ���� + �� -
double expression() {
    double left = term();                               // ��ȡ��evaluete һ�� term
    Token t = ts.get();                                 // ��token ���л�ȡ��һ��token
    while (true) {
        switch (t.kind)
        {
        case '+':
            left += term();                             // ����term �� +
            t = ts.get();
            break;
        case '-':
            left -= term();                             // evaluete term and subtract
            t = ts.get();   
            break; 
        default:
            ts.putback(t);                              // �� t �Ż� token stream ��
            return left;                                // finally: ���û�и���� + �� -: ����answer
        }
    }
}

int main()
try {
    cout << "\nWelcome to our simple calculator.\n"
        << "Please enter expressions using floating-point numbers.\n"
        << "Operations available are +, -, * and /.\n"
        << "Can change order of operations using ( ) and or { }.\n"
        << "Use the ; to show results and q to exit.\n\n";

    double val{};
    while (cin) {
        Token t = ts.get();
        if (t.kind == 'q') {                         // 'q' for quit
            cout << "Bye" << endl;
            break;
        }
        if (t.kind == ';') {
            cout << "= " << val << endl;            // ';' for "print now"
        } else {
            ts.putback(t);
            val = expression();
        }
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
    cerr << "Oops: unknown exception! \n";
    keep_window_open();
    return 2;
}

