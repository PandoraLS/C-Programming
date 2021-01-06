/*
 * @Author: seenli
 * @Date: 2021-01-06 18:44:36
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-06 19:03:28
 * @FilePath: \Ch09\Book.h
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Book class under library namespace

#ifndef BOOK_H
#define BOOK_H

#include<string>

namespace library {
    class Book {
        public:
            enum class Genre{unknown, fiction, nonfiction, periodical, biography, children};
            Book();
            Book(
                std::string ISBN,                           // ISBN号
                std::string title,                          // 书名
                std::string author,                         // 作者
                int copyright_year,                         // 版权日期
                Genre genre = Genre::unknown                // 书的种类
            );
            std::string get_isbn() const {return m_isbn;}
            std::string get_title() const {return m_title;}
            std::string get_author() const {return m_author;}
            int get_copyright() const {return m_copyright_year;}
            Genre get_genre() const {return m_genre;}
            bool is_checked_out() const {return m_checked_out;}
            void check_inout(bool cio) {m_checked_out = cio;}

            friend std::ostream& operator<<(std::ostream& os, const Book& b);
            friend bool operator==(const Book& b1, const Book& b2);
            friend bool operator!=(const Book& b1, const Book& b2);

        private:
            std::string m_isbn;
            std::string m_title;
            std::string m_author;
            int m_copyright_year;
            Genre m_genre;
            bool m_checked_out;
            bool isbn_valid() const;
    };
}

#endif  // Book.h
