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
    因为ch10_ex07.cpp需要用到ch10_ex06.cpp, 所有需要将ch10_ex06.cpp中的main函数注释掉
    执行命令：
    g++ -g ch10_ex07.cpp ch10_ex06.cpp -o ch10_ex07.exe
*/

#include "ch10_ex06.h"

const char number = '8';                // t.kind==number 表示 t 是一个 罗马数字的 Token
const char quit = 'q';                  // t.kind==quit 表示 t 是一个 quit Token
const char print = ';';                 // t.kind==print 表示 t 是一个 打印 Token
const char name = 'a';                  // name Token 来表示用户自定义变量名
const char let = 'L';                   // 声明一个 Token

const string declkey = "let";           // 声明 关键词
const string prompt = "> ";             // 输入提示符
const string result = "= ";             // = 后面表示输出结果

//---------------------------------------------------------------------------------------------

class Token {
    public:
        char kind;                      // Token 的种类
        Roman_int value;                // 罗马数字的数值
        string name;                    // 变量的名称
        Token(char ch)                  : kind(ch), value(0) {}
        Token(char ch, Roman_int val)   : kind(ch), value(0) {} 
        Token(char ch, string n)        : kind(ch), name(n)  {}
};

//---------------------------------------------------------------------------------------------

// 缓冲区的作用
class Token_stream {
    public:
        Token_stream();                 // 创建一个从cin读取的Token_stream
        Token get();                    // get a Token
        void putback(Token t);          // put a Token
        void ignore(char c);            // 丢弃包括c在内的Token

    private:
        bool full;                      // 缓冲区是否有Token
        Token buffer;                   // 保存Token的buffer
};

//---------------------------------------------------------------------------------------------

// 构造函数将缓冲区设置为空
Token_stream::Token_stream(): full(false), buffer(0) {}             // buffer中无Token

//---------------------------------------------------------------------------------------------

// putback() 函数将其参数放回缓冲区
void Token_stream::putback(Token t) {
    if (full) error("putback() into a full buffer");
    buffer = t;                         // 将 t copy 到 buffer中
    full = true;                        // 设置buffer为full
}

Token Token_stream::get() {             // 将从cin读取的字符组成一个Token
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
        case L: case C: case D: case M:         // 罗马数字
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
                    return Token(let);              // 关键词 "let"
                }
                return Token(name, s);
            }
            error("Bad token");
    }
}

// c 表示 Token的种类
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

Token_stream ts;                    // 提供 get() 和 putback()

//---------------------------------------------------------------------------------------------

class Variable {
    public:
        string name;
        Roman_int value;
        Variable (string n, Roman_int r): name(n), value(r) {}
};

//---------------------------------------------------------------------------------------------

vector<Variable> var_table;


// 返回名字为s的Variable的值
Roman_int get_value(string s) {
    for (int i{}; i < var_table.size(); ++i) {
        if (var_table[i].name == s) {
            return var_table[i].value;
        }
    }
    error("get: undefined variable ", s);
}

// 给名为s的Variable 设置value d
void set_value(string s, Roman_int d) {
    for (int i{}; i < var_table.size(); ++i) {
        if (var_table[i].name == s) {
            var_table[i].value = d;
            return;
        }
    }
    error("set: undefined variable ", s);
}

// var 是否已经在 var_table中？
bool is_declared(string var) {
    for (int i{}; i < var_table.size(); ++i) {
        if (var_table[i].name == var) {
            return true;
        }
    }
    return false;
}

// 将(var, val) 添加到 var_table
Roman_int define_name(string var, Roman_int val) {
    if (is_declared(var)) {
        error(var, " declared twice");
    }
    var_table.push_back(Variable(var, val));
    return val;
}

Roman_int expression();                 // 声明 expression() 

// 处理数字和括号()
Roman_int primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(':                       // 处理 '(' expression ')'
        {
            Roman_int d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number:
            return t.value;             // return number 的值
        case name:
            return get_value(t.name);   // 返回 variable 的值
        case '-':
            return -primary();
        case '+':
            return primary();
        default:
            error("primary expected");
    }
}


// 处理 *, /, %
Roman_int term() {
    Roman_int left = primary();
    Token t = ts.get();                 // 从Token stream获取下一个 token
    
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
                ts.putback(t);              // 将 t 放回token_stream
                return left;
        }
    }
}

// 处理 + 和 -
Roman_int expression() {
    Roman_int left = term();                // 读取并计算 Term
    Token t = ts.get();                     // 从 Token_stream 中获取下一个 token

    while (true) {
        switch (t.kind) {
            case '+':
                left = left + term();       // 计算Term 并 添加
                t = ts.get();
                break;
            case '-':
                left = left - term();       // 计算Term 并 相减
                t = ts.get();
                break;
            default:
                ts.putback(t);              // 将 t 放回 token stream
                return left;                // 没有更多的 + 和 -: 返回 answer
        }
    }
}


// 处理 name = expression
// 声明一个名为“name”的变量，初始值为“expression”
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
            t = ts.get();                   // 首先丢弃所有的 print
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

