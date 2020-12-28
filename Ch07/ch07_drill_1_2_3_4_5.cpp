/*
 * @Author: seenli
 * @Date: 2020-12-28 15:25:08
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-28 17:00:26
 * @FilePath: \Ch07\ch07_drill_1_2_3_4_5.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Drill 1, 2, 3, 4 and 5

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
 * @description: ��cin�����ЧToken
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
                    cin.putback(ch);
                    if (s == declkey) {
                        t.kind = let;
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

void Token_stream::ignore(const char c) {
    if (full && c == buffer.kind) {
        full = false;
    } else {
        full = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail(), c);
    }
}

int main()
try {
    
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
