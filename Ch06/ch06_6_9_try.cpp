/*
 * @Author: seenli
 * @Date: 2020-12-14 20:23:29
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-20 16:06:53
 * @FilePath: \Ch06\ch06_6_9_try.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Expression:
        Term
        Expression "+" Term
        Expression "-" Term
    Term:
        Primary
        Term "*" Primary
        Term "/" Primary
        Term "%" Primary
    Primary:
        Number
        "(" Expression ")"
    Number:
        floating-point-literal
*/

#include "std_lib_facilities.h"

class Token {
    public:
        char kind;                  // kind of token
        double value;               // for numbers: a value

        // �ṹ
        Token(char ch, double val = 0.0): kind(ch), value(val) {}
};

class Token_stream {
    public:
        // The constructor just sets full to indicate that the buffer is empty:
        Token_stream(): full(false), buffer(' ') {}
        Token get();                // get a Token (get() is defined elsewhere)
        void putback(Token t);      // put a Token back
    private:
        bool full;                  // Token �Ƿ���buffer��
        Token buffer;               // ����Token��buffer
};

// putback()��Ա������������Ż�Token_stream��buffer��
void Token_stream::putback(Token t) {
    if (full) {
        error("putback() into full buffer");
    }
    buffer = t;                     // copy t to buffer
    full = true;                    // buffer is now full
}

Token Token_stream::get() {
    Token temp{' '};    // �洢����return��

    // ����Ƿ��Ѿ���token��
    if (full) {
        // ��token��buffer��remove
        full = false;
        temp = buffer;
    } else {
        char ch;
        cin >> ch;                  // >> �������հ׷�(�ո�, ���з�, tab��)
        
        switch (ch) {
            case ';':               // ��� ���
            case 'q':               // �˳�
            case '(': case ')': case '+': case '-': case '*': case '/':
                temp = Token(ch);
                break;
            case '.':
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);                // �����ַŻ�������
                double val;
                cin >> val;                     // ����һ��������
                temp = Token('8', val);
                break;
            }
            default:
                error("Bad token");
        }
    }
    return temp;
}

Token_stream ts;                                // provoids get() and putback()

// ���� + �� -
double expression();

// ���� *  /  %
double term();

// �������� �� Բ����
double primary();

int main()
try {
    double val = 0;
    while (cin) {
        Token t = ts.get();
        if (t.kind == 'q') break;                               // 'q' �˳�
        if (t.kind == ';') cout << "=" << val << endl;          // ';' ��ӡ���
        else ts.putback(t);
        val = expression();
    }

    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "exception" << endl;
    keep_window_open();
    return 2;
}

// ���� + �� -
double expression() {
    double left = term();                   // ���벢����һ����
    Token t = ts.get();                     // �ӵ������л�ȡ��һ������
    
    while (true) {
        switch (t.kind)
        {
        case '+':
            left += term();                 // ����һ���ֵ�����
            t = ts.get();
            break;
        case '-':
            left -= term();                 // ����һ���ֵ�����
            t = ts.get();
            break;
        default:
            ts.putback(t);                  // ��t�Żص���������
            return left;                    // ���� û�и��� + �� -; ���ؽ��
        }
    }
}

// ���� *  /  %
double term() {
    double left = primary();
    Token t = ts.get();                     // �ӵ������л�ȡ��һ������

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
            ts.putback(t);                  // ��t�Żص���������
            return left;
        }
    }
}

// �������ֺ�Բ����
double primary() {
    double temp{};                          // ����return��ֵ
    Token t = ts.get();

    switch (t.kind)
    {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' excepted");
        temp = d;
        break;
    }
    case '8':                               // ����ʹ�� '8' ����ʾ����
        temp = t.value;                     // �������ֵ�ֵ
        break;
    default:
        error("primary excepted");
    }
    return temp;
}

