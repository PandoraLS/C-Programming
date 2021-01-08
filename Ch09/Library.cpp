/*
 * @Author: seenli
 * @Date: 2021-01-08 13:53:27
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-08 20:43:29
 * @FilePath: \Ch09\Library.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#include <iostream>
#include "Library.h"

namespace library {
    Library::Library()
    {}
    
    void Library::add_book() {
        std::cout << "Enter ISBN:\n";
        std::string isbn{get_string()};

        std::cout << "Enter title:\n";
		std::string title{get_string()};

		std::cout << "Enter author:\n";
		std::string author{get_string()};

		std::cout << "Enter copyright year:\n";
		int copyright{};
		std::cin >> copyright;

        if (!std::cin.good() || isbn.empty() || title.empty() || author.empty()) {
            throw std::runtime_error("Invalid Library class Book created");
        }

        m_books.push_back(Book(isbn, title, author, copyright));
    }

    void Library::add_patron() {
        std::string name{get_string()};
        if (!name.empty()) {
            int card_number{};
            if (!m_patrons.empty()) {
                for (auto p: m_patrons) {
                    auto pcn = p.get_card_number();
                    if (pcn >= card_number) {
                        card_number = pcn + 1;
                    }
                }
            } else {
                card_number = 1;
            }

            if (!name.empty() && card_number != 0) {
                Patron patron(name, card_number);
                std::cout << "Set any fees:\n";
                double fees{};
                std::cin >> fees;
                patron.set_fees(fees);
                m_patrons.push_back(patron);
            } else {
                throw std::runtime_error("Invalid Library class Patron created");
            }
        } else {
            throw std::runtime_error("Invalid Library class Patron name created");
        }
    }

    //确保读者和图书是图书馆的一部分
    //如果其中任何一个不是库的一部分, 报告一个错误
    //如果用户欠费, 报告错误
    //如果没有错误, 创建一个事务放置到事务向量
    void Library::check_out_book(Book& b, Patron& p) {
        auto b_itr{std::find(m_books.begin(), m_books.end(), b)};
        // TODO 这里报错：没有与参数列表匹配的 函数模板 "std::find" 实例
        // 目前(2021年1月8日)尚不清楚是什么原因导致的, 暂时不做处理

        if (b_itr == m_books.cend()) {
            throw std::runtime_error("Library does not have this book");
        }
        if (b_itr->is_checked_out()) {
            throw std::runtime_error("Book is checked out");
        }

        auto p_itr{std::find(m_patrons.begin(), m_patrons.end(), p)};
        if (p_itr == m_patrons.cend()) {
            throw std::runtime_error("User is not registered");
        }
        if (p_itr->is_outstanding_fee()) {
            throw std::runtime_error("User has outstanding fees");
        }

        b_itr->check_inout(true);

        // 获取当前日期
        transactions.push_back(Transaction(*b_itr, *p_itr, Chrono::Date(2020, Chrono::Month::jan, 18)));
    }

    std::vector<std::pair<std::string, double>> Library::get_outstanding_fees() {
        std::vector<std::pair<std::string, double>> list;
        for (auto itr{m_patrons.begin()}; itr < m_patrons.end(); ++itr) {
            if (itr->is_outstanding_fee()) {
                list.push_back(std::make_pair(itr->get_name(), itr->get_fees()));
            }
        }
        return list;
    }

}