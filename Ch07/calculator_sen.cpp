/*
This program implements a basic expression calculator.
    Input from cin; output to cout.
    The grammar for input is:

    Statement:
            Expression
            Print
            Quit
    Print:
            ;

    Quit:
            q

    Expression:
            Term
            Expression + Term
            Expression – Term
    Term:
            Primary
            Term * Primary
            Term / Primary
            Term % Primary
            Primary !
    Primary:
            Number
            ( Expression )
            – Primary
            + Primary
            sqrt (Primary)
    Number:
            floating-point-literal


    Input comes from cin through the Token_stream called ts.
*/

#include "std_lib_facilities.h"

// Token 用于保存操作符、操作数以及变量名
struct Token { // TODO 这里为什么用struct 而不是class?，class和struct分别在什么时候用?
    char kind;
    double value;
    string name;

    // TODO 这里的用法有什么意义?
    Token(char ch): kind(ch), value(0) {} // 操作符
    Token(char ch, double val): kind(ch), value(val) {} // 操作数
    Token(char ch, string n): kind(ch), name(n) {} // 变量名
};

// Token_stream
class Token_stream {
    bool full;
    Token buffer;
public:
    Token_stream(): full(0), buffer(0) {}
    Token get();                // 从cin中获取字符并以Token类型返回
    void putback(Token t){      //将symbol返回buffer,如果full=true,get()将使用buffer中的symbol
        buffer = t;
        full = true;
    }

    void ignore(char);      //忽略掉特殊符号之前的所有字符
};

const char let = 'L';       // let用于声明变量
const char quit = 'E';      // quit用于退出程序
const char print = ';';     // print计算结果
const char number = '8';    // 表明这是一个数字
const char name = 'a';      // 表明这是一个变量
const char sqrts = 's';     // 表明平方根
const char pows = 'p';      // 表明pow()
const char assign = '=';    // 给变量赋新值

// 从cin中获取字符并以Token类型返回
Token Token_stream::get() { // 从cin获取字符
    if (full){              // 如果buffer非空，就返回buffer中的value
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;              // 否则开始在输入流中查找字符
    switch (ch) {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
        case '!':
        case ',':
            return Token(ch);           // 如果是操作符or逗号就返回他们
        case assign:
            return Token(assign);       // 如果是赋值操作，则返回其字符
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
            cin.unget();            // 如果是number就返回到输入流中
            double val;
            cin >> val;             // 将完整的value读取
            return Token(number, val);      // 返回完整的一个Token
        }
        default:
            if (isalpha(ch)) {      // 如果是个字母
                string s;
                s += ch;            // 将字母拼接到s上
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                    s += ch;        // 继续拼接到s上
                cin.unget();        // 返回字符到输入流中
                if (s == "let")     return Token(let);      // 如果用户声明了变量就返回 'let'
                if (s == "sqrt")    return Token(sqrts);    
                if (s == "pow")     return Token(pows);
                if (s == "exit")    return Token(quit);
                return Token(name, s);      // 返回变量的名称
            }
            error("Bad token");
    }
}   

// 忽略掉特殊symbol之前的所有字符
void Token_stream::ignore(char c){      
    if (full && c == buffer.kind) {     // 如果buffer中已经有c了，直接丢弃c
        full = false;
        return;
    }
    full = false;                       // 丢弃buffer中的值，并向前进一步
    char ch;
    while (cin >> ch)                   // 读取'c'之前的所有值
        if (ch == c)
            return;                     // 如果找到了'c'，直接return
}

struct Variable {             
    string name;                        // Variable name
    double value;                       // Variable value
    Variable (string n, double v): name(n), value(v) {}
};

vector<Variable> names;                 // holds 所有的 Variables

double get_value(string s){             // 获取variable的值
    for (Variable i: names){
        if (i.name == s)
            return i.value;
    }
    error("get: undefined name ", s);
}

void set_value(string s, double d){     // 设置variable的值
    for (int i = 0; i <= names.size(); ++i)
        if (names[i].name == s){
            names[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool is_declared(string s){             // 检查variable是否已声明
    for (int i = 0; i < names.size(); ++i)
        if (names[i].name == s)
            return true;
    return false;
}

Token_stream ts;                        // holds all Tokens

double expression();                    // 声明expression()

double primary();                       // 声明primary()

double squareroot() {
    double d = expression();
    if (d < 0) error("检测到负数的平方根");
    return sqrt(d);
}

double pow() {
    Token t = ts.get();
    if (t.kind == '(') {
        double lval = expression();
        int rval = 0;
        t = ts.get();
        if (t.kind == ',')
            rval = narrow_cast<int>(primary());
        else
            error("未提供第二个argument");
        double result = 1;
        for(double i = 0; i < rval; i++){
            result += lval;
        }
        t = ts.get();
        if (t.kind != ')')
            error("')' expected ");     // 如果没有 ')' 就返回一个error
        
        return result;
    } else
        error("')' expected ");         // 如果没有 ')' 就返回一个error
}

double primary(){                       // 处理分号、数字和返回变量(处理优先级)
    Token t = ts.get();                 // 获取一个character
    switch (t.kind) {
        case '(':
        {
            double d = expression();    // 用分号执行计算
            t = ts.get();
            if (t.kind != ')')
                error("')' expected "); // 如果没有 ')' 就返回一个error
            return d;
        }

        case sqrts:                     // 计算一个或一组数的平方根
        {
            return squareroot();
        }
        case pows:
        {
            return pow();
        }
        case '-':                       // 处理负数
            return - primary();         // 返回负数
        case number:                    // 如果Token是一number则返回number的值
            return t.value;
        case name:                      // 如果Token是variable的name
        {
            string s = t.name;          // 保存variable的name
            t = ts.get();
            if (t.kind == assign)       // 如果有赋值符号出现，则更新variable的值
                set_value(s, expression());
            else
                ts.putback(t);
            return get_value(s);        // 返回variable的值
        }
        default:
            error("primary expected");
    }
}

double term(){                          // 处理'*', '/', '!', '%' and @(sqrt) 操作符
    double left = primary();            // 获取一个number
    while (true) {
        Token t = ts.get();             
        switch(t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0)
                    error("除0错误");
                left /= d;
                break;
            }
            case '!':   // 阶乘
            {
                int x = left;
                for (int i = 1; i < left; i++){         // 得到x(含x)之前所有数的乘积
                    x *= i;
                }
                if (x == 0)
                    left = 1;
                else
                    left = x;
                break;
            }
            case '%':
            {
                double d = primary();
                if (d == 0)
                    error("除0错误");
                left = fmod(left, d);                   // 使用fmod对浮点数进行余数除法
                break;
            }
            default:
                ts.putback(t);                            // 如果什么都没做就把character返回到stream中
                if (left == -0)
                    return 0;                           // 特殊处理-0
                return left;                            // 返回新的或unchanged值 of 'left'
        }
    }
}


double expression(){                                    // 处理 '+' 和 '-'
    double left = term();                               // 得到计算结果
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
                ts.putback(t);                            // 如果什么都没做就将character返回到stream中
                return left;                            // left可能更改了也可能没更改
        }
    }
}


double declaration(){                                   // 声明variable的name
    Token t = ts.get();                                 // 从stream中获取一个character
    if (t.kind != 'a') 
        error("name expected in declaration");          // 如果没有name则返回error
    string name = t.name;                               // read the name in 'name'
    if (is_declared(name))
        error(name, " declared twice");                 // 检查是否已经声明过了
    Token t2 = ts.get();                                // 从stream中获取一个character
    if (t2.kind != '=')
        error("= missing in declaration of ", name);    // 如果没有'='给新变量赋值,则返回error
    
    double d = expression();                            // 处理提供的值
    names.push_back(Variable(name, d));                 // 添加一个新variable到vector中
    return d;                                           // 返回新variable的值
}

// 处理表达式和声明
double statement(){                                     // 区分声明和表达式
    Token t = ts.get();
    switch (t.kind){
        case let:                                       // 声明variable
            return declaration();
        default:                                        // 进行其他操作
            ts.putback(t);
            return expression();
    }
}

void clean_up_mess(){                                   // 如果发生异常就忽略掉';'前的所有characters
    ts.ignore(print);
}


const string prompt = "> ";                             // 输入提示
const string result = "= ";                             // '='后面是结果

void calculate(){
    while (true) try{
        cout << prompt;                                 // 输出'>'提示符
        Token t = ts.get();                             // 获取的结果是Token类型的
        while (t.kind == print)                         // 先丢弃所有的"print"单词
            t = ts.get();
        if (t.kind == quit)                             // 退出
            return;
        ts.putback(t);                                  // 将character退回到stream中
        cout << result << statement() << endl;          // 输出结果
    } catch (runtime_error & e) {
        cerr << e.what() << endl;                       // 如果抛出异常则cout error
        clean_up_mess();                                // 忽略掉所有的characters直到';'
    }
}


int main()
try{
    names.push_back(Variable("k", 1000));               // 预定义 variable 'k'
    calculate();                                        // 计算过程
    return 0;
} catch (exception & e) {                               // 抛出异常
    cerr << "exception: " << e.what() << endl;          // 描述错误
    char c;
    while (cin >> c && c != ';');
    return 1;
} catch (...) {                                         // 抛出异常
    cerr << "exception\n";
    char c;
    while (cin >> c && c != ';');
    return 2;
}


