/*
 * @Author: seenli
 * @Date: 2021-01-04 13:51:39
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-04 14:50:29
 * @FilePath: \Ch08\symbol_table.h
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <vector>

namespace ppp_calc {
    class Symbol_Table {
        public:
            Symbol_Table();
            ~Symbol_Table();            // Îö¹¹º¯Êý

            double get_value(const std::string& s);
            void set_value(const std::string& s, const double d);
            bool is_declared(const std::string& s);
            double declare(const std::string& s, const double d, const bool set_const = false);

        private:
            // place to hold variable name value
            struct Variable {
                std::string name;
                double value{};
                bool is_const{false};
            };

            // container for all the variables
            std::vector<Variable> var_table;

            // private template function to find name in var_table
            template<typename InputIt, typename T>
            constexpr InputIt find_name(InputIt first, InputIt last, const T& value) {
                for (; first != last; ++first) {
                    if (first->name == value) {
                        return first;
                    }
                }
                return last;
            }
    };
}   // ppp_calc

#endif
