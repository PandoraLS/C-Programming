/*
 * @Author: seenli
 * @Date: 2021-01-05 13:41:15
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-05 15:31:55
 * @FilePath: \Ch08\ch08_ex07_2.cpp
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

	Section 8 Exercise 7_2
	- add ability to create variable number of names
*/

#include<iostream>
#include "ppp.h"

int main() 
try {
	char c{};
	std::string name;
	std::vector<std::string> names;
    std::cout << "Enter names separated by ',' or new line. ctrl-z to exit\n";

	// 录入多个字符串的方式
	while (std::cin.get(c)) {
		if (c != ',' && c != '\n') {
			if (!name.empty()) {
				name += c;
			} else if (c != ' ') {
				name += c;
			}
		} else if (!name.empty()) {
			names.push_back(name);
			name.clear();
		}
	}

	std::cin.clear();			// clear EOF
	std::cout << "names entered\n";
	std::vector<double> ages;
    for (auto n: names) {
        std::cout << "Enter age for " << n << " ";
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
catch(std::exception& e){
	std::cerr << "exception: " << e.what() << std::endl;
	ppp::keep_window_open();
	return 1;
}
catch(...){
	std::cerr << "exception\n";
	ppp::keep_window_open();
	return 2;
}