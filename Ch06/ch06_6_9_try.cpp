/*
 * @Author: seenli
 * @Date: 2020-12-14 20:23:29
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-14 20:40:47
 * @FilePath: \Ch06\ch06_6_9_try.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
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
}

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t){
    if (full) {
        error("putback() into full buffer");
    }
    buffer = t;                     // copy t to buffer
    full = true;                    // buffer is now full
}


