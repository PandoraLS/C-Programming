/*
 * @Author: seenli
 * @Date: 2021-01-10 13:29:57
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-10 15:31:41
 * @FilePath: \Ch09\toy_code2.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */
#include <iostream>
#include <tuple>
#include <array>
#include <cstdlib>
#include <vector>


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
        
        std::vector<currencyInfoTuple> currencyInfo {
            {"USD", "$", 1.0},            // 首先保留美元，因为美元是标准存储货币
            {"DKK", "Kr", 6.8}
        };
};

int main()
{

    // std::cout << "检验tuple的用法:\n";
    // typedef std::tuple<std::string, std::string, double> DATA_INFO;
    // //initialization value
    // DATA_INFO info("USD", "$", 1.0);
    // DATA_INFO info2("DKK", "Kr", 6.8);
    // // get values:
    // std::cout << "(" << std::get<0>(info) << ", " << std::get<1>(info)
    //           << ", " << std::get<2>(info) << ")\n";
    
    // std::vector<DATA_INFO> m_data;

    // std::cout << "=============================" << std::endl;
    // m_data.push_back(info);
    // m_data.push_back(info2);

    // for (int i{}; i < m_data.size(); ++i) {
    //     std::cout << "(" << std::get<0>(m_data.at(i)) << ", " << std::get<1>(m_data.at(i))
    //           << ", " << std::get<2>(m_data.at(i)) << ")\n";
    // }

    
    // std::cout << "=========检验tuple的用法结束============" << std::endl;

    // std::cout << "=========测试新用法============" << std::endl;

    // std::vector<DATA_INFO> m_data2 {
    //     {"USD2", "$2", 10},            // 首先保留美元，因为美元是标准存储货币
    //     {"DKK2", "Kr2", 66.8}
    // };

    // for (int i{}; i < m_data2.size(); ++i) {
    //     std::cout << "(" << std::get<0>(m_data2.at(i)) << ", " << std::get<1>(m_data2.at(i))
    //           << ", " << std::get<2>(m_data2.at(i)) << ")\n";
    // }

    // std::cout << "=========测试新用法结束============" << std::endl;

    // std::cout << "=========测试新用法222============" << std::endl;

    // using currencyInfoTuple = std::tuple<std::string, std::string, double>;
        
    // const std::vector<currencyInfoTuple> currencyInfo {
    //     {"USD", "$", 1.0},            // 首先保留美元，因为美元是标准存储货币
    //     {"DKK", "Kr", 6.8}
    // };

    // for (int i{}; i < currencyInfo.size(); ++i) {
    //     std::cout << "(" << std::get<0>(currencyInfo.at(i)) << ", " << std::get<1>(currencyInfo.at(i))
    //           << ", " << std::get<2>(currencyInfo.at(i)) << ")\n";
    // }

    // std::cout << "=========测试新用法结束222============" << std::endl;
    
    std::cout << "=========测试新用法333============" << std::endl;

    
    typedef std::tuple<std::string, std::string, double> currencyInfoTuple;
    std::vector<currencyInfoTuple> currencyInfo;
    currencyInfo.push_back(currencyInfoTuple("USD", "$", 1.0));
    currencyInfo.push_back(currencyInfoTuple("DKK", "Kr", 6.8));

    for (int i{}; i < currencyInfo.size(); ++i) {
        std::cout << "(" << std::get<0>(currencyInfo.at(i)) << ", " << std::get<1>(currencyInfo.at(i))
              << ", " << std::get<2>(currencyInfo.at(i)) << ")\n";
    }

    std::cout << "=========测试新用法结束333============" << std::endl;

    system("pause");
    return 0;
}


