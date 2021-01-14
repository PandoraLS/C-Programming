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

const char number = '8';                // t.kind==number ��ʾ t ��һ�� �������ֵ� Token
const char quit = 'q';                  // t.kind==quit ��ʾ t ��һ�� quit Token
const char print = ';';                 // t.kind==print ��ʾ t ��һ�� ��ӡ Token
const char name = 'a';                  // name Token ����ʾ�û��Զ��������
const char let = 'L';                   // ����һ�� Token

const string declkey = "let";           // ���� �ؼ���
const string prompt = "> ";             // ������ʾ��
const string result = "= ";             // = �����ʾ������

//---------------------------------------------------------------------------------------------

class Token {
    public:
        char kind;                      // Token ������
        Roman_int value;                // �������ֵ���ֵ
        string name;                    // ����������
        Token(char ch)                  : kind(ch), value(0) {}
        Token(char ch, Roman_int val)   : kind(ch), value(0) {} 
        Token(char ch, string n)        : kind(ch), name(n)  {}
};

// ������������
class Token_stream {
    public:
        Token_stream();                 // ����һ����cin��ȡ��Token_stream
        Token get();                    // get a Token
        void putback(Token t);          // put a Token
        void ignore(char c);            // ��������c���ڵı��

    private:
        bool full;                      // �������Ƿ���Token
        Token buffer;                   // ����Token��buffer
};

//---------------------------------------------------------------------------------------------

// ���캯��������������Ϊ��
Token_stream::Token_stream(): full(false), buffer(0) {}             // buffer����Token


// 
