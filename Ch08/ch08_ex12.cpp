/*
 * @Author: seenli
 * @Date: 2021-01-05 17:10:25
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-05 18:21:03
 * @FilePath: \Ch08\ch08_ex12.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Section 8 Exercise 12
	- Write a function with input vector<string> argument.
	- returns a vector<int> containing the number of characters in each string.
	- also find the longest and shortest string.
	- lexicographically first and last string

	keep as one function and separate function?
	I guess depends on the situation but keeping 3 separate functions helps keeps each specialized.
	Could also just find size of each to find shortest and longest word.
	also for the lexicographically first and last string could use the sort function from the STL algorithm library
*/

#include "ppp.h"

template<typename T>
void print_vector(const std::vector<T>& v) {
    if (!v.empty()) {
        for (const auto& element : v) {
            std::cout << element << '\n';
        }
        std::cout << '\n';
    } else {
        std::cout << "vector is empty\n";
    }
}


std::vector<int> find_size(const std::vector<std::string>& vs) {
    std::vector<int> vn;
    if (!vs.empty()) {
        for (const auto& s : vs) {
            vn.push_back(static_cast<int>(s.size()));
        }
    }
    return vn;
}

int main() {
    std::vector<std::string> vs{"one hundred", "zero", "one", "five thousand", "two", "zero", "three", "four"};

    auto sizes = find_size(vs);
    print_vector(sizes);

    // °´×Ö·û´®³¤¶ÈÅÅÐò
    auto lengths = vs;
    std::stable_sort(lengths.begin(), lengths.end(), 
        [](const std::string& a, const std::string& b){return a.size() < b.size();});
    print_vector(lengths);

    // ×ÖµäÐò
    auto alpha_order = vs;
    std::stable_sort(alpha_order.begin(), alpha_order.end());
    print_vector(alpha_order);

    system("pause");
    return 0;
}
