/*
 * @Author: seenli
 * @Date: 2021-01-14 20:43:47
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-15 19:27:31
 * @FilePath: \Ch10\ch10_ex07.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chapter 10, exercise 07: use calculator from Chapter 7 with Roman Numerals
    instead of Arabic ones
*/

/*
    Simple calculator

    Revision history:

        Revised by Bjarne Stroustrup May 2007
        Revised by Bjarne Stroustrup August 2006
        Revised by Bjarne Stroustrup August 2004
        Originally written by Bjarne Stroustrup
            (bs@cs.tamu.edu) Spring 2004.

    This program implements a basic expression calculator.
    Input from cin; output to cout.

    The grammar for input is:

    Calculation:
        Statement
        Print
        Quit
        Calculation Statement

    Statement:
        Declaration
        Expression

    Declaration:
        "let" Name "=" Expression

    Print:
        ;

    Quit:
        q

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
        Number
        Name
        ( Expression )
        - Primary
        + Primary
    Number:
        Roman Numeral


        Input comes from cin through the Token_stream called ts.
*/

/*
    ��Ϊch10_ex07.cpp��Ҫ�õ�ch10_ex06.cpp, ������Ҫ��ch10_ex06.cpp�е�main����ע�͵�
    ִ�����
    g++ -g ch10_ex07.cpp ch10_ex06.cpp -o ch10_ex07.exe
*/

#include "ch10_ex06.h"

const char number = '8';                // t.kind==number ��ʾ t ��һ�� �������ֵ� Token
const char quit = 'q';                  // t.kind==quit ��ʾ t ��һ�� quit Token
const char print = ';';                 // t.kind==print ��ʾ t ��һ�� ��ӡ Token
const char name = 'a';                  // name Token ����ʾ�û��Զ��������
const char let = 'L';                   // ����һ�� Token

const string declkey = "let";           // ���� �ؼ���
const string prompt = "> ";             // ������ʾ��
const string result = "= ";             // = �����ʾ������

//---------------------------------------------------------------------------------------------

class Token {
    public:
        char kind;                      // Token ������
        Roman_int value;                // �������ֵ���ֵ
        string name;                    // ����������
        Token(char ch)                  : kind(ch), value(0) {}
        Token(char ch, Roman_int val)   : kind(ch), value(0) {} 
        Token(char ch, string n)        : kind(ch), name(n)  {}
};

//---------------------------------------------------------------------------------------------

// ������������
class Token_stream {
    public:
        Token_stream();                 // ����һ����cin��ȡ��Token_stream
        Token get();                    // get a Token
        void putback(Token t);          // put a Token
        void ignore(char c);            // ��������c���ڵ�Token

    private:
        bool full;                      // �������Ƿ���Token
        Token buffer;                   // ����Token��buffer
};

//---------------------------------------------------------------------------------------------

// ���캯��������������Ϊ��
Token_stream::Token_stream(): full(false), buffer(0) {}             // buffer����Token

//---------------------------------------------------------------------------------------------

// putback() ������������Żػ�����
void Token_stream::putback(Token t) {
    if (full) error("putback() into a full buffer");
    buffer = t;                         // �� t copy �� buffer��
    full = true;                        // ����bufferΪfull
}

Token Token_stream::get() {             // ����cin��ȡ���ַ����һ��Token
    if (full) {
        full = false;
        return buffer;
    }
    
    char ch;
    cin >> ch;                          // note that >> skips whitespace (space, newline, tab, etc.)

    switch(ch) {
        case quit:
        case print:
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
            return Token(ch);           
        
        case N: case I: case V: case X:
        case L: case C: case D: case M:         // ��������
        {
            cin.putback(ch);
            Roman_int r;
            cin >> r;
            return Token(number, r);
        }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) {
                    s += ch;
                }
                cin.putback(ch);
                if (s == declkey) {
                    return Token(let);              // �ؼ��� "let"
                }
                return Token(name, s);
            }
            error("Bad token");
    }
}

// c ��ʾ Token������
void Token_stream::ignore(char c) {
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // search input
    char ch = 0;
    while (cin >> ch) {
        if (ch == c)
            return;
    }
}

//---------------------------------------------------------------------------------------------

Token_stream ts;                    // �ṩ get() �� putback()

//---------------------------------------------------------------------------------------------

class Variable {
    public:
        string name;
        Roman_int value;
        Variable (string n, Roman_int r): name(n), value(r) {}
};

//---------------------------------------------------------------------------------------------

vector<Variable> var_table;


// ��������Ϊs��Variable��ֵ
Roman_int get_value(string s) {
    for (int i{}; i < var_table.size(); ++i) {
        if (var_table[i].name == s) {
            return var_table[i].value;
        }
    }
    error("get: undefined variable ", s);
}

// ����Ϊs��Variable ����value d
void set_value(string s, Roman_int d) {
    for (int i{}; i < var_table.size(); ++i) {
        if (var_table[i].name == s) {
            var_table[i].value = d;
            return;
        }
    }
    error("set: undefined variable ", s);
}

// var �Ƿ��Ѿ��� var_table�У�
bool is_declared(string var) {
    for (int i{}; i < var_table.size(); ++i) {
        if (var_table[i].name == var) {
            return true;
        }
    }
    return false;
}

// ��(var, val) ��ӵ� var_table
Roman_int define_name(string var, Roman_int val) {
    if (is_declared(var)) {
        error(var, " declared twice");
    }
    var_table.push_back(Variable(var, val));
    return val;
}

Roman_int expression();                 // ���� expression() 

// �������ֺ�����()
Roman_int primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(':                       // ���� '(' expression ')'
        {
            Roman_int d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number:
            return t.value;             // return number ��ֵ
        case name:
            return get_value(t.name);   // ���� variable ��ֵ
        case '-':
            return -primary();
        case '+':
            return primary();
        default:
            error("primary expected");
    }
}


// ���� *, /, %
Roman_int term() {
    Roman_int left = primary();
    Token t = ts.get();                 // ��Token stream��ȡ��һ�� token
    
    while (true) {
        switch (t.kind) {
            case '*':
                left = left * primary();
                t = ts.get();
                break;
            case '/':
            {
                Roman_int d = primary();
                if (d == Roman_int(0)) error("divide by zero");
                left = left / d;
                t = ts.get();
                break;
            }
            case '%':
            {
                Roman_int i1 = left;
                Roman_int i2 = term();
                if (i2 == Roman_int(0)) error("%: divide by zero");
                left = i1 % i2;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);              // �� t �Ż�token_stream
                return left;
        }
    }
}

// ���� + �� -
Roman_int expression() {
    Roman_int left = term();                // ��ȡ������ Term
    Token t = ts.get();                     // �� Token_stream �л�ȡ��һ�� token

    while (true) {
        switch (t.kind) {
            case '+':
                left = left + term();       // ����Term �� ���
                t = ts.get();
                break;
            case '-':
                left = left - term();       // ����Term �� ���
                t = ts.get();
                break;
            default:
                ts.putback(t);              // �� t �Ż� token stream
                return left;                // û�и���� + �� -: ���� answer
        }
    }
}


// ���� name = expression
// ����һ����Ϊ��name���ı�������ʼֵΪ��expression��
Roman_int declaration() {
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    Roman_int d = expression();
    define_name(var_name, d);
    return d;
}

Roman_int statement() {
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

void clean_up_mess() {
    ts.ignore(print);
}

void calculate() {
    while (cin)
    try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) {
            t = ts.get();                   // ���ȶ������е� print
        }
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << statement() << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}


int main()
try {
    calculate();
    system("pause");
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
}

