/*
 * @Author: seenli
 * @Date: 2020-12-30 21:24:07
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-30 23:32:44
 * @FilePath: \Ch07\ch07_drill_7_8.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
	Section 7 Drill 7
	give the calculator a square root function
	Section 7 Drill 8
	check for negative numbers before using square root function and give an error
*/

#include "std_lib_facilities.h"

/**
 * @description: ������ֺͲ�������
 */
struct Token {
    char kind;
    double value;
    string name;
    Token(char ch, double val = 0.0) : kind(ch), value(val) {}
    Token(char ch, string s): kind(ch), value(0.0), name(s) {} 
};

/**
 * @description: �����洢����
 */
struct Variable {
    string name;
    double value{};
};

/**
 * @description: ���ص��ڲ���, �� get, set, is_declared����
 */
bool operator==(const Variable& v, const string s) {return v.name == s;}

// �洢���е�variables
vector<Variable> names;

/**
 * @description: ���������s���ض�Ӧ��value
 * @param {conststring} s
 */
double get_value(const string s) {
    auto vt_itr = find(names.cbegin(), names.cend(), s);
    if (vt_itr == names.cend()) {
        error("get: undefined name ", s);
    }
    return vt_itr->value;
}

/**
 * @description: ���ҵ�name�������ö�Ӧ��value
 * @param {conststring} s
 * @param {constdouble} d
 */
void set_value(const string s, const double d) {
    auto vt_itr = find(names.begin(), names.end(), s);
    if (vt_itr == names.cend()) {
        error("set: undefined name ", s);
    }
    vt_itr->value = d;
}

/**
 * @description: name�Ƿ��Ѿ�������
 * @param {conststring} s
 */
bool is_declared(const string s) {
    return names.cend() != find(names.cbegin(), names.cend(), s);
}

/**
 * @description: ��� name-value ��, ������value
 * @param {conststring} s
 * @param {constdouble} d
 */
double define_name(const string s, const double d) {
    if (is_declared(s)) {
        error(s, " declared twice");
    }
    names.push_back(Variable{s, d});
    return d;
}

/**
 * @description: ��cin�����ЧToken, Token_stream������ģʽ��cin���
 */
class Token_stream {
    public:
        Token_stream(): full(false), buffer('\0') {}
        Token get();                                // get a Token ���ŵ�stream��
        void putback(const Token t);                // put a Token back
        void ignore(const char c);                  // �����ַ�
    private:
        bool full;                                  // Token �Ƿ���buffer��
        Token buffer;                               // ���Token��buffer
};

constexpr char number = '8';                        // t.kind == number ��ʾ t ��һ�� number Token
constexpr char quit = 'q';                          // t.kind == quit ��ʾ t ��һ�� quit Token
constexpr char print = ';';                         // t.kind == print ��ʾ t ��һ�� print Token

constexpr char name = 'a';                          // name token
constexpr char let = 'L';                           // ���� token
constexpr char* declkey = "let";                    // ���� keyword
constexpr char func = 'F';                          // function Token

/**
 * @description: ��ȡһ��Token�����뵽stream��
 */
Token Token_stream::get() {
    Token t{'\0'};
    if (full) {
        full = false;
        t = buffer;
    } else {
        char ch{};
        cin >> ch;
        switch (ch) {
            case print:
            case quit:
            case '(':
            case ')':
            case '+':
            case '-':
            case '*':
            case '/':
                t.kind = ch;
                break;
            case '=':
                if (this->buffer.kind != let) {
                    const string s = (this->buffer.kind == name ? this->buffer.name : to_string(this->buffer.value));
                    error(s, " can not be re-assigned");
                }
                t.kind = ch;
                break;
            case '.':
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                {
                    cin.putback(ch);
                    double val;
                    cin >> val;
                    t.kind = number;
                    t.value = val;
                    break;
                }
            default:
                if (isalpha(ch)) {
                    string s;
                    s += ch;
                    while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) {
                        s += ch;
                    }
                    cin.putback(ch);            // �����ȡ�ķ���ĸor�������˻ص�cin��
                    if (s == declkey) {
                        t.kind = let;
                    } else if (ch == '(') {
                        t.kind = func;
                        t.name = s;
                    } else {
                        t.kind = name;
                        t.name = s;
                    }
                } else {
                    error("Bad token");
                }
        }
    }
    return t;
}

/**
 * @description: put a Token back
 */
void Token_stream::putback(const Token t) {
    if (full) {
        error("putback() into a full buffer");
    }
    buffer = t;
    full = true;
}

/**
 * @description: ���Ե���������ʣ�ಿ��
 */
void Token_stream::ignore(const char c) {
    if (full && c == buffer.kind) {
        full = false;
    } else {
        full = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), c);             // ����������ʣ�ಿ��ȫ�����Ե�,�������c����ǰ��ֹ
    }
}

Token_stream ts;

double expression();

double primary() {
    Token t = ts.get();
    double d{};
    switch(t.kind) {
        case '(':
            {
                d = expression();
                t = ts.get();
                if (t.kind != ')') {
                    error("')' expected");
                }
                return d;
            }
        case '-':
            return -1 * primary();
        case '+':
            return primary();
        case number:
            return t.value;
        case name:
            return get_value(t.name);
        default:
            error("primary expected");
    }
}


double term() {
    double left = primary();
    while (true) {
        Token t = ts.get();
        switch(t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
                {
                    double d = primary();
                    if (d == 0) {
                        error("divide by zero");
                    }
                    left /= d;
                    break;
                }
            default:
                ts.putback(t);
                return left;

        }
    }
}


double expression() {
    double left = term();
    while (true) {
        Token t = ts.get();
        switch(t.kind) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

/**
 * @description: �����������
 */
double declaration() {
    Token t = ts.get();
    if (t.kind != name) {
        error("name expected in declaration");
    }
    if (is_declared(t.name)) {
        error(t.name, " declared twice");
    }

    Token t2 = ts.get();
    if (t2.kind != '=') {
        error("= missing in declaration of ", t.name);
    }
    double d = expression();
    define_name(t.name, d);
    return d;
}

/**
 * @description: ��ѧ����
 * @param {const} string t ��ѧ������
 */
double funct(const string& t) {
    if (t != "sqrt") {
        error("unknown function call");
    }
    auto d = expression();
    if (d < 0) {
        error("can not take a square root of a negative number");
    }
    return sqrt(d);
}

double statement() {
    Token t = ts.get();
    switch(t.kind) {
        case let:
            return declaration();
        case func:
            return funct(t.name);
        default:
            ts.putback(t);
            return expression();
    }
}

/**
 * @description: ���Ե���������ʣ�ಿ��
 */
void clean_up_mess() {
    ts.ignore(print);
}

void calculate() {
    constexpr char* prompt = "> ";          // ��ʾ��
    constexpr char* result = "= ";          // ���

    while (true) try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) {
            t = ts.get();
        }
        if (t.kind == quit) {
            return ;
        }
        ts.putback(t);
        cout << result << statement() << endl;
    }
    catch (runtime_error& e) {
        cerr << "error: " << e.what() << endl;
        clean_up_mess();
    }
}


int main()
try {
    cin.sync_with_stdio(false);
    calculate();
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
