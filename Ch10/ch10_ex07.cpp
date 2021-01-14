/*
 * @Author: seenli
 * @Date: 2021-01-14 20:43:47
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-14 22:12:11
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

// 缓冲区的作用
class Token_stream {
    public:
        Token_stream();                 // 创建一个从cin读取的Token_stream
        Token get();                    // get a Token
        void putback(Token t);          // put a Token
        void ignore(char c);            // 丢弃包括c在内的标记

    private:
        bool full;                      // 缓冲区是否有Token
        Token buffer;                   // 保存Token的buffer
};

//---------------------------------------------------------------------------------------------

// 构造函数将缓冲区设置为空
Token_stream::Token_stream(): full(false), buffer(0) {}             // buffer中无Token


// 
