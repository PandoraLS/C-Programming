/*
 * @Author: seenli
 * @Date: 2021-01-02 13:40:03
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-02 15:13:30
 * @FilePath: \Ch07\ch07_ex04.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
	copied from drill 11 removed drill 10 stuff
	also added modulo
	section 7 exercise 1
	allow underscores in the calculator's variable names

	section 7 exercise 2
	modified how function is handled.  place call in primary and removed recursive call from function handler
	provide assignment operator = so can reassign already declared variables with let.
	The issue with this is to make sure there is no proceeding expression.
	example:
	let x = 2; x + 3; x = 4; //is ok
	x = 5 + x; //is ok were existing value of x added to 5 then new value into x
	x + 4 - x = 5; is not ok
	let y = 3; x = y = 5; is not ok ?

	section 7 exercise 3
	Provide named constants that you can't change the value of

	section 7 exercise 4
	Define a symbol table class
*/


#include "std_lib_facilities.h"

class Symbol_Table {
    public:
        Symbol_Table() {};
        
        double get_value(const string& s);
        void set_value(const string& s, const double d);
        bool is_declared(const string& s);
        double declare(const string& s, const double d, const bool set_const = false);

    private:
        // ����hold����name-value
        struct Variable {
            string name;
            double value{};
            bool is_const{false};
        };

        // �洢���еı���
        vector<Variable> var_table;

        // ˽�к��� find name in var_table
        using vt_itr = vector<Variable>::iterator;
        vt_itr find_name(vt_itr first, vt_itr last, const string& value) {
            for (; first != last; ++first) {
                if (first->name == value) {
                    return first;
                }
            }
            return last;
        }
};

/**
 * @description: ���������s���ض�Ӧ��value
 * @param {conststring} s
 */
double Symbol_Table::get_value(const string& s) {
    auto vt_itr = find_name(var_table.begin(), var_table.end(), s);
    if (vt_itr == var_table.cend()) {
        error("get: undefined name ", s);
    }
    return vt_itr->value;
}

/**
 * @description: ���ҵ�name�������ö�Ӧ��value
 * @param {conststring} s
 * @param {constdouble} d
 */
void Symbol_Table::set_value(const string& s, const double d) {
    auto vt_itr = find_name(var_table.begin(), var_table.end(), s);
    if (vt_itr == var_table.cend()) {
        error("set: undefined name ", s);
    }
    if (vt_itr->is_const) {
        error(s, ": is a constant");
    }
    vt_itr->value = d;
}

/**
 * @description: name�Ƿ��Ѿ�������
 * @param {conststring} s
 */
bool Symbol_Table::is_declared(const string& s) {
    return var_table.cend() != find_name(var_table.begin(), var_table.end(), s);
}

/**
 * @description: ��name value��ӵ�Variable��vector��
 * @param {conststring} s
 * @param {constdouble} d
 * @param {constbool} set_const
 */
double Symbol_Table::declare(const string& s, const double d, const bool set_const) {
    if(is_declared(s)) error(s, " declared twice");
    var_table.push_back(Variable{s, d, set_const});
    return d;
}

Symbol_Table symbol_table;

const char number = '8';                        // t.kind == number ��ʾ t ��һ�� number Token
const char quit = 'q';                          // t.kind == quit ��ʾ t ��һ�� quit Token
const string declexit = "exit";                  // �˳��ؼ���
const char print = ';';                         // t.kind == print ��ʾ t ��һ�� print Token

const char name = 'a';                          // name token
const char let = 'L';                           // ���� token
const string declkey = "let";                   // ���� keyword
const char constant = 'C';                      // ���� ���� token
const string declkey_const = "const";
const char func = 'F';                          // function Token

/**
 * @description: ������ֺͲ�������
 */
struct Token {
    char kind;
    double value;
    string name;
    Token(char ch, double val = 0.0) : kind(ch), value(val), name("") {}
    Token(char ch, string s): kind(ch), value(0.0), name(s) {} 
};


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
			case ',':
            case '%':
            case '=':
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
                if (isalpha(ch) || (ch == '_')) {
                    string s;
                    s += ch;
                    while (cin.get(ch) && (isalpha(ch)  || isdigit(ch) || (ch == '_'))) {
                        s += ch;
                    }
                    cin.putback(ch);            // �����ȡ�ķ���ĸor�������˻ص�cin��
                    if (s == declkey) {
                        t.kind = let;
                    } else if (s == declkey_const) {
                        t.kind = constant;
                    } else if (ch == '(') {
                        t.kind = func;
                        t.name = s;
                    } else if (s == declexit) {
                        t.kind = quit;
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
double funct(const string& s);

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
                break;
            }
        case '-':
            d = -1 * primary();
            break;
        case '+':
            d = primary();
            break;
        case number:
            d = t.value;
            break;
        case name:
            d = symbol_table.get_value(t.name);
            break;
        case func:
            d = funct(t.name);
            break;
        default:
            error("primary expected");
    }
    return d;
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
            case '%':
                {
                    double d = primary();
                    if (d == 0) {
                        error("divide by zero");
                    }
                    left = fmod(left, d);
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
            case ',':                       // let fall through
            default:
                ts.putback(t);
                return left;
        }
    }
}

/**
 * @description: �����������
 */
double declaration(const bool is_const = false) {
    Token t = ts.get();
    if (t.kind != name) {
        error("name expected in declaration");
    }
    if (symbol_table.is_declared(t.name)) {
        error(t.name, " declared twice");
    }

    Token t2 = ts.get();
    if (t2.kind != '=') {
        error("= missing in declaration of ", t.name);
    }
    double d = expression();
    symbol_table.declare(t.name, d, is_const);
    return d;
}


double func_availible(const string& s, const vector<double>& args) {
    double d{};
    if (s == "sqrt") {
        if (args.size() != 1) error("sqrt() expects 1 argument");
        if (args[0] < 0) error("sqrt() expects argument value >= 0");
        d = sqrt(args[0]);
    } else if (s == "pow") {
        if (args.size() != 2) error("pow() expects 2 arguments");
        d = args[0];
        auto multiplier = args[0];
        auto p = narrow_cast<int>(args[1]);
        for (; p > 1; --p) {
            d *= multiplier;
        }
    } else {
        error("unknown function");
    }
    return d;
}

/**
 * @description: ��ѧ����
 * @param {const} string s �����ַ�
 */
double funct(const string& s) {
    Token t = ts.get();
    vector<double> func_args;
    if (t.kind != '(') {
        error("expected '(', malformed function call");
    } else {
        do {
            t = ts.get();

            // �������
            if (t.kind != ')') {
                ts.putback(t);
                func_args.push_back(expression());
                t = ts.get();
                if (t.kind != ',' && t.kind != ')') error("expected ')', ���εĺ�������");
            }
        } while (t.kind != ')');
    }
    return func_availible(s, func_args);
}

double statement() {
    Token t = ts.get();
    double d{};
    switch(t.kind) {
        case let:
            d = declaration();
            break;
        case constant:
            d = declaration(true);
            break;
        case name:
            {
                Token t2 = ts.get();

                if (t2.kind != '=') {
                    cin.putback(t2.kind);
                    ts.putback(t);
                    d = expression();
                } else {
                    d = expression();
                    symbol_table.set_value(t.name, d);
                }
                break;
            }
        default:
            ts.putback(t);
            d = expression();
    }

    return d;
}

/**
 * @description: ���Ե���������ʣ�ಿ��
 */
void clean_up_mess() {
    ts.ignore(print);
}

void calculate() {
    const string prompt = "> ";          // ��ʾ��
    const string result = "= ";          // ���

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
