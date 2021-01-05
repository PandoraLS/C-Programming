/*
 * @Author: seenli
 * @Date: 2021-01-05 12:51:29
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-05 13:40:34
 * @FilePath: \Ch08\ch08_ex07.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Section 8 Exercise 7
	- Read 5 names into vector<string> name.
	- Prompt user for age of the people named.
	- Store the ages in a vector<double>.
	- Print the 5 name age pairs.
	- Sort the names.
	- Print the sorted 5 name age pairs.
*/

#include<iostream>
#include "ppp.h"

int main() {
    std::vector<std::string> names{"James", "Ted", "Ryan", "Arther", "Linus"};
    std::vector<double> ages;
    for (auto name: names) {
        std::cout << "Enter age for " << name << " ";
        double age{};
        if (!(std::cin >> age)) {
            ppp::error("Invalid age entered!");
        }
        ages.push_back(age);
    }

    std::cout << "\n\n";
    if (names.size() == ages.size()) {
        for (auto itr{names.begin()}; itr < names.cend(); ++itr) {
            std::size_t index{static_cast<std::size_t>(itr - names.begin())};
            std::cout << names.at(index) << " is " << ages.at(index) << " years old.\n";
        }
    }
    
    std::cout << "\n\n";
    std::vector<std::string> copy_names = names;
    std::sort(names.begin(), names.end());
    if (names.size() == ages.size()) {
        for (const auto name : names) {
            const auto itr{std::find(copy_names.begin(), copy_names.end(), name)};
            if (itr == copy_names.cend()) {
                ppp::error("Name not found!");
            }
            std::size_t index = static_cast<std::size_t>(itr - copy_names.begin()); 
            // 找到name在原vector中的相对位置(为了定位age)

            std::cout << name << " is " << ages.at(index) << " years old. \n";
        }
    }
    system("pause");
    return 0;
}
