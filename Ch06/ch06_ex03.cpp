/*
 * @Author: seenli
 * @Date: 2020-12-20 15:31:45
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-20 16:24:33
 * @FilePath: \Ch06\ch06_ex03.cpp
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
        "{" Expression "}"
        Primary "!"
    Number:
        floating-point-literal
*/

#include "std_lib_facilities.h"

class Token {
    public:
        char kind;                                      // kind of token
        double value;                                   // for number: a value

        // 构造函数
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

// putback() 函数将其参数放回到Token_stream buffer
void Token_stream::putback(Token t) {
    if (full) {
        error("putback() into a full buffer");
    }
    buffer = t;                                         // 将 t 拷贝到 buffer
    full = true;                                        // buffer 是 full
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
        case ';':                                       // 输出
        case 'q':                                       // quit
        case '!': case '{': case '}':
        case '(': case ')': case '+': case '-': case '*': case '/':
            temp.kind = ch;
            break;
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);                            // 将digit放回输入流
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

double expression();                                    // 声明之后primary() 就可以调用 expression() 函数了

// 处理 数字 和 圆括号
double primary() {
    double temp{};                                      // 用语存储result
    Token t = ts.get();
    switch (t.kind)
    {
    case '{':                                           // 处理 '{' expression '}'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}') {
                error("'}' expected");
            }
            temp = d;
            break;
        }
    case '(':                                           // 处理 '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') {
                error("')' expected");
            }
            temp = d;
            break;
        }
    case '-':                                           // 处理 - 一元运算符
        temp = -1 * primary();
        break;
    case '+':
        temp = primary();                               // 处理 + 一元运算符
        break;
    case '!':
        cin.putback('!');                               // 如果阶乘前面没有primary
        temp = 0;                                       // 添加 1 返回到输入流中， 0或1的阶乘为1
    case '8':                                           // 使用 '8' 来代替number
        temp = t.value;                                 // 返回num的数值
        break;
    default:
        error("primary expected");
    }
    return temp;
}

// 阶乘优先级更高
double factorial() {
    double left = primary();
    Token t = ts.get();
    if (t.kind == '!') {
        cout << "warning 整型将把浮点数截断为整型" << endl;
        auto fact = narrow_cast<long long, double>(left);
        if (fact < 0) {
            error("阶乘不可以为负数");
        } else if (fact == 0) {
            left = 1.0;
        } else {
            decltype(fact) temp = 1;
            for (long long i = 1; i <= fact; ++i) {
                temp *= i;
                // 不做溢出检查
            }
            left = narrow_cast<double, long long>(temp);
        }
    } else {
        ts.putback(t);
    }
    return left;
}

// 处理 * 和 /, 尚未实现 % 
double term() {
    double left = factorial();
    Token t = ts.get();                                 // 从token流中获取下一个token
    while (true) {
        switch (t.kind)
        {
        case '*':
            left *= factorial();
            t = ts.get();
            break;
        case '/':
            {
                double d = factorial();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
        default:
            ts.putback(t);                              // 将 t 放回token 流中
            return left;
        }
    }
}


// 处理 + 和 -
double expression() {
    double left = term();                               // 读取和evaluete 一个 term
    Token t = ts.get();                                 // 从token 流中获取下一个token
    while (true) {
        switch (t.kind)
        {
        case '+':
            left += term();                             // 计算term 和 +
            t = ts.get();
            break;
        case '-':
            left -= term();                             // evaluete term and subtract
            t = ts.get();   
            break; 
        default:
            ts.putback(t);                              // 将 t 放回 token stream 中
            return left;                                // finally: 如果没有更多的 + 和 -: 返回answer
        }
    }
}

int main()
try {
    cout << "\nWelcome to our simple calculator.\n"
        << "Please enter expressions using floating-point numbers.\n"
        << "Operations available are +, -, *, / and !.\n"
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

