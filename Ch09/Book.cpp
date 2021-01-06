/*
 * @Author: seenli
 * @Date: 2021-01-06 19:03:34
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-06 19:16:53
 * @FilePath: \Ch09\Book.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


#include "Book.h"
#include<sstream>

namespace library {
    Book::Book()
       :m_isbn("0-0-0-x"),
        m_title("?"),
        m_author("?"),
        m_copyright_year(9999),
        m_checked_out(false)
    {}

    Book::Book(
        std::string ISBN,                           // ISBN号
        std::string title,                          // 书名
        std::string author,                         // 作者
        int copyright_year,                         // 版权日期
        Genre genre                                 // 书的种类
    )
    : m_isbn(ISBN), m_title(title), m_author(author), m_copyright_year(copyright_year), 
    m_genre(genre), m_checked_out(false) {
        if (!isbn_valid()) throw std::runtime_error("Invalid ISBN");
    }

    bool Book::isbn_valid() const {
        std::stringstream ss;
        ss << m_isbn;
        int n1{}, n2{}, n3{};
        char c1{}, c2{}, c3{}, c4{};
        ss >> n1 >> c1 >> n2 >> c2 >> n3 >> c3 >> c4;
        if (ss.good() && c1 == '-' && c2 == '-' && c3 == '-' && isalnum(c4)) {
            return true;
        }
        return false;
    }

    std::ostream& operator<<(std::ostream& os, const Book& b) {
        os << "TITLE: " << b.m_title << '\n'
            << "AUTHOR: " << b.m_author << '\n'
            << "ISBN: " << b.m_isbn;
        return os;
    }

    bool operator==(const Book& b1, const Book& b2) {
        return b1.m_isbn == b2.m_isbn;
    }

    bool operator!=(const Book& b1, const Book& b2) {
        return !(b1 == b2);
    }
}
