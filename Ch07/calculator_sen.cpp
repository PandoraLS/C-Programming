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
            Expression �C Term
    Term:
            Primary
            Term * Primary
            Term / Primary
            Term % Primary
            Primary !
    Primary:
            Number
            ( Expression )
            �C Primary
            + Primary
            sqrt (Primary)
    Number:
            floating-point-literal


    Input comes from cin through the Token_stream called ts.
*/

#include "std_lib_facilities.h"

// Token ���ڱ�����������������Լ�������
struct Token { // TODO ����Ϊʲô��struct ������class?��class��struct�ֱ���ʲôʱ����?
    char kind;
    double value;
    string name;

    // TODO ������÷���ʲô����?
    Token(char ch): kind(ch), value(0) {} // ������
    Token(char ch, double val): kind(ch), value(val) {} // ������
    Token(char ch, string n): kind(ch), name(n) {} // ������
};

// Token_stream
class Token_stream {
    bool full;
    Token buffer;
public:
    Token_stream(): full(0), buffer(0) {}
    Token get();                // ��cin�л�ȡ�ַ�����Token���ͷ���
    void putback(Token t){      //��symbol����buffer,���full=true,get()��ʹ��buffer�е�symbol
        buffer = t;
        full = true;
    }

    void ignore(char);      //���Ե��������֮ǰ�������ַ�
};

const char let = 'L';       // let������������
const char quit = 'E';      // quit�����˳�����
const char print = ';';     // print������
const char number = '8';    // ��������һ������
const char name = 'a';      // ��������һ������
const char sqrts = 's';     // ����ƽ����
const char pows = 'p';      // ����pow()
const char assign = '=';    // ����������ֵ

// ��cin�л�ȡ�ַ�����Token���ͷ���
Token Token_stream::get() { // ��cin��ȡ�ַ�
    if (full){              // ���buffer�ǿգ��ͷ���buffer�е�value
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;              // ����ʼ���������в����ַ�
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
            return Token(ch);           // ����ǲ�����or���žͷ�������
        case assign:
            return Token(assign);       // ����Ǹ�ֵ�������򷵻����ַ�
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
            cin.unget();            // �����number�ͷ��ص���������
            double val;
            cin >> val;             // ��������value��ȡ
            return Token(number, val);      // ����������һ��Token
        }
        default:
            if (isalpha(ch)) {      // ����Ǹ���ĸ
                string s;
                s += ch;            // ����ĸƴ�ӵ�s��
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                    s += ch;        // ����ƴ�ӵ�s��
                cin.unget();        // �����ַ�����������
                if (s == "let")     return Token(let);      // ����û������˱����ͷ��� 'let'
                if (s == "sqrt")    return Token(sqrts);    
                if (s == "pow")     return Token(pows);
                if (s == "exit")    return Token(quit);
                return Token(name, s);      // ���ر���������
            }
            error("Bad token");
    }
}   

// ���Ե�����symbol֮ǰ�������ַ�
void Token_stream::ignore(char c){      
    if (full && c == buffer.kind) {     // ���buffer���Ѿ���c�ˣ�ֱ�Ӷ���c
        full = false;
        return;
    }
    full = false;                       // ����buffer�е�ֵ������ǰ��һ��
    char ch;
    while (cin >> ch)                   // ��ȡ'c'֮ǰ������ֵ
        if (ch == c)
            return;                     // ����ҵ���'c'��ֱ��return
}

struct Variable {             
    string name;                        // Variable name
    double value;                       // Variable value
    Variable (string n, double v): name(n), value(v) {}
};

vector<Variable> names;                 // holds ���е� Variables

double get_value(string s){             // ��ȡvariable��ֵ
    for (Variable i: names){
        if (i.name == s)
            return i.value;
    }
    error("get: undefined name ", s);
}

void set_value(string s, double d){     // ����variable��ֵ
    for (int i = 0; i <= names.size(); ++i)
        if (names[i].name == s){
            names[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool is_declared(string s){             // ���variable�Ƿ�������
    for (int i = 0; i < names.size(); ++i)
        if (names[i].name == s)
            return true;
    return false;
}

Token_stream ts;                        // holds all Tokens

double expression();                    // ����expression()

double primary();                       // ����primary()

double squareroot() {
    double d = expression();
    if (d < 0) error("��⵽������ƽ����");
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
            error("δ�ṩ�ڶ���argument");
        double result = 1;
        for(double i = 0; i < rval; i++){
            result += lval;
        }
        t = ts.get();
        if (t.kind != ')')
            error("')' expected ");     // ���û�� ')' �ͷ���һ��error
        
        return result;
    } else
        error("')' expected ");         // ���û�� ')' �ͷ���һ��error
}

double primary(){                       // ����ֺš����ֺͷ��ر���(�������ȼ�)
    Token t = ts.get();                 // ��ȡһ��character
    switch (t.kind) {
        case '(':
        {
            double d = expression();    // �÷ֺ�ִ�м���
            t = ts.get();
            if (t.kind != ')')
                error("')' expected "); // ���û�� ')' �ͷ���һ��error
            return d;
        }

        case sqrts:                     // ����һ����һ������ƽ����
        {
            return squareroot();
        }
        case pows:
        {
            return pow();
        }
        case '-':                       // ������
            return - primary();         // ���ظ���
        case number:                    // ���Token��һnumber�򷵻�number��ֵ
            return t.value;
        case name:                      // ���Token��variable��name
        {
            string s = t.name;          // ����variable��name
            t = ts.get();
            if (t.kind == assign)       // ����и�ֵ���ų��֣������variable��ֵ
                set_value(s, expression());
            else
                ts.putback(t);
            return get_value(s);        // ����variable��ֵ
        }
        default:
            error("primary expected");
    }
}

double term(){                          // ����'*', '/', '!', '%' and @(sqrt) ������
    double left = primary();            // ��ȡһ��number
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
                    error("��0����");
                left /= d;
                break;
            }
            case '!':   // �׳�
            {
                int x = left;
                for (int i = 1; i < left; i++){         // �õ�x(��x)֮ǰ�������ĳ˻�
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
                    error("��0����");
                left = fmod(left, d);                   // ʹ��fmod�Ը�����������������
                break;
            }
            default:
                ts.putback(t);                            // ���ʲô��û���Ͱ�character���ص�stream��
                if (left == -0)
                    return 0;                           // ���⴦��-0
                return left;                            // �����µĻ�unchangedֵ of 'left'
        }
    }
}


double expression(){                                    // ���� '+' �� '-'
    double left = term();                               // �õ�������
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
                ts.putback(t);                            // ���ʲô��û���ͽ�character���ص�stream��
                return left;                            // left���ܸ�����Ҳ����û����
        }
    }
}


double declaration(){                                   // ����variable��name
    Token t = ts.get();                                 // ��stream�л�ȡһ��character
    if (t.kind != 'a') 
        error("name expected in declaration");          // ���û��name�򷵻�error
    string name = t.name;                               // read the name in 'name'
    if (is_declared(name))
        error(name, " declared twice");                 // ����Ƿ��Ѿ���������
    Token t2 = ts.get();                                // ��stream�л�ȡһ��character
    if (t2.kind != '=')
        error("= missing in declaration of ", name);    // ���û��'='���±�����ֵ,�򷵻�error
    
    double d = expression();                            // �����ṩ��ֵ
    names.push_back(Variable(name, d));                 // ���һ����variable��vector��
    return d;                                           // ������variable��ֵ
}

// ������ʽ������
double statement(){                                     // ���������ͱ��ʽ
    Token t = ts.get();
    switch (t.kind){
        case let:                                       // ����variable
            return declaration();
        default:                                        // ������������
            ts.putback(t);
            return expression();
    }
}

void clean_up_mess(){                                   // ��������쳣�ͺ��Ե�';'ǰ������characters
    ts.ignore(print);
}


const string prompt = "> ";                             // ������ʾ
const string result = "= ";                             // '='�����ǽ��

void calculate(){
    while (true) try{
        cout << prompt;                                 // ���'>'��ʾ��
        Token t = ts.get();                             // ��ȡ�Ľ����Token���͵�
        while (t.kind == print)                         // �ȶ������е�"print"����
            t = ts.get();
        if (t.kind == quit)                             // �˳�
            return;
        ts.putback(t);                                  // ��character�˻ص�stream��
        cout << result << statement() << endl;          // ������
    } catch (runtime_error & e) {
        cerr << e.what() << endl;                       // ����׳��쳣��cout error
        clean_up_mess();                                // ���Ե����е�charactersֱ��';'
    }
}


int main()
try{
    names.push_back(Variable("k", 1000));               // Ԥ���� variable 'k'
    calculate();                                        // �������
    return 0;
} catch (exception & e) {                               // �׳��쳣
    cerr << "exception: " << e.what() << endl;          // ��������
    char c;
    while (cin >> c && c != ';');
    return 1;
} catch (...) {                                         // �׳��쳣
    cerr << "exception\n";
    char c;
    while (cin >> c && c != ';');
    return 2;
}


