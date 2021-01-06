/*
 * @Author: seenli
 * @Date: 2021-01-06 20:18:04
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-06 20:29:03
 * @FilePath: \Ch09\Patron.h
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Patron class under library namespace

#ifndef PATRON_H
#define PATRON_H

#include<string>
#include<iostream>

namespace library {
    class Patron {
        public:
            Patron();
            Patron(const std::string name, const int card_number);

            std::string get_name() const {return m_name;}
            int get_card_number() const {return m_card_number;}
            double get_fees() const;

            double set_fees(const double f);
            bool is_outstanding_fee() const;

            friend std::ostream& operator<<(std::ostream& os, const Patron& p);
            friend bool operator==(const Patron& p1, const Patron& p2);
            friend bool operator!=(const Patron& p1, const Patron& p2);

        private:
            std::string m_name;
            int m_card_number;
            double m_fees;
    };
}

#endif