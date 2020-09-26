//代码是按照calculator002buggy.cpp一步步来的
//实现版本为6.8节的

#include "std_lib_facilities.h"

class Token {
    public:
        char kind;
        double value;
    Token(char ch):kind(ch), value(0) {}
    Token(char ch, double val): kind(ch), value(val) {}
};

class Token_stream {
    public:
        Token_stream();
        Token get();
        void putback(Token t);
    private:
        bool full {false};
        Token buffer;
};

Token_stream::Token_stream(): full(false), buffer(0){

}

// putback() 成员函数将[单词]放回[单词流]
void Token_stream::putback(Token t){
    if (full)
        error("putback() into a full buffer");
    buffer = t;
    full = true;
}


// get() 用于返回下一个单词
Token Token_stream::get(){
    if (full) {
        full=false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch (ch) {
        case '=':   // for "print"
        case 'x':   // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token('8', val);
        } 
        default:
            error("Bad token");
    }
}


Token_stream ts;

double expression();


// 处理number和括号
double primary(){
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");
        return d;
    }
    case '8':
        return t.value;
    default:
        error("primary expected");
    }
}

// 处理 *，/，以及 %
double term(){
    double left = primary();
    Token t = ts.get();

    while(true){
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);  // 将 t 放回[单词流]中
            return left;
        }
    }
}

// 处理 + 和 -
double expression(){
    double left = term();
    Token t = ts.get();

    while (true) {
        switch(t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}


int main()
try{
    cout << "请输入表达式(使用浮点数).\n" <<
    "有效运算符为 '+','-','*', '/'. 如要打印结果请在表达式后输入'='.\n"<<
    "正常退出程序请使用'x'\n";
    double val = 0;
    while (cin){
        Token t = ts.get();

        if (t.kind == 'x')
            break;          //  退出程序
        if (t.kind == '=')
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
    keep_window_open();
}
catch (exception & e){
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception! \n";
    keep_window_open();
    return 2;
}


