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

        // 结构
        Token(char ch, double val = 0.0): kind(ch), value(val) {}
};

class Token_stream {
    public:
        // The constructor just sets full to indicate that the buffer is empty:
        Token_stream(): full(false), buffer(' ') {}
        Token get();                // get a Token (get() is defined elsewhere)
        void putback(Token t);      // put a Token back
    private:
        bool full;                  // Token 是否在buffer中
        Token buffer;               // 保存Token的buffer
};

// putback()成员函数将其参数放回Token_stream的buffer中
void Token_stream::putback(Token t) {
    if (full) {
        error("putback() into full buffer");
    }
    buffer = t;                     // copy t to buffer
    full = true;                    // buffer is now full
}

Token Token_stream::get() {
    Token temp{' '};    // 存储用于return的

    // 检查是否已经有token了
    if (full) {
        // 将token从buffer中remove
        full = false;
        temp = buffer;
    } else {
        char ch;
        cin >> ch;                  // >> 会跳过空白符(空格, 换行符, tab等)
        
        switch (ch) {
            case ';':               // 输出 结果
            case 'q':               // 退出
            case '(': case ')': case '+': case '-': case '*': case '/':
                temp = Token(ch);
                break;
            case '.':
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);                // 将数字放回输入流
                double val;
                cin >> val;                     // 读入一个浮点数
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

// 处理 + 和 -
double expression();

// 处理 *  /  %
double term();

// 处理数字 和 圆括号
double primary();

int main()
try {
    double val = 0;
    while (cin) {
        Token t = ts.get();
        if (t.kind == 'q') break;                               // 'q' 退出
        if (t.kind == ';') cout << "=" << val << endl;          // ';' 打印输出
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

// 处理 + 和 -
double expression() {
    double left = term();                   // 读入并计算一个项
    Token t = ts.get();                     // 从单词流中获取下一个单词
    
    while (true) {
        switch (t.kind)
        {
        case '+':
            left += term();                 // 计算一项的值并相加
            t = ts.get();
            break;
        case '-':
            left -= term();                 // 计算一项的值并相减
            t = ts.get();
            break;
        default:
            ts.putback(t);                  // 将t放回到单词流中
            return left;                    // 最终 没有更多 + 和 -; 返回结果
        }
    }
}

// 处理 *  /  %
double term() {
    double left = primary();
    Token t = ts.get();                     // 从单词流中获取下一个单词

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
            ts.putback(t);                  // 将t放回到单词流中
            return left;
        }
    }
}

// 处理数字和圆括号
double primary() {
    double temp{};                          // 用于return的值
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
    case '8':                               // 我们使用 '8' 来表示数字
        temp = t.value;                     // 返回数字的值
        break;
    default:
        error("primary excepted");
    }
    return temp;
}

