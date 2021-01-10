/*
 * @Author: seenli
 * @Date: 2021-01-09 13:40:53
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-10 15:31:05
 * @FilePath: \Ch09\Money.h
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <vector>
#include <tuple>

class Money {
    public:
        Money(std::string m = "");
        std::string get_cents();

        Money operator+(const Money& m) const;
        friend std::ostream& operator<<(std::ostream& os, const Money& m);
        friend std::istream& operator>>(std::istream& is, Money& m);

    private:
        std::string m_currencyCode{"USD"};
        std::string m_currencySign{"$"};
        long m_cents{};                 // 美分的数量, 以美元存储的最低面额
        double m_conversion{};

        std::string validate_currency(const std::string& m);

        using currencyInfoTuple = std::tuple<std::string, std::string, double>;
        const std::vector<currencyInfoTuple> currencyInfo {
            {"USD", "$", 1}, // keep USD first because used as the standard stored currency
            {"DKK", "Kr", 6.8}
        };
};

#endif
