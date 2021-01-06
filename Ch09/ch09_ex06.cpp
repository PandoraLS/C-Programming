/*
 * @Author: seenli
 * @Date: 2021-01-06 19:23:02
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-06 20:13:40
 * @FilePath: \Ch09\ch09_ex06.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
	Section 9 Exercise 6
	Design and implement a Book class under library namespace
	- add == operator to for ISBNs
	- add != operator to for ISBNs
	- add << to print title, author, and ISBN on separate lines
*/

#include "ppp.h"
#include "Book.h"

int main()
try {
    library::Book book1("0-321-99278-4", 
        "Programming Principles and Practices Using C++ Second Edition", "Bjarne Stroustrup", 2014);
    std::cout << book1 << "\n\n";
    library::Book book2;
    library::Book book3 = book1;

    if (book1 == book3) {
        std::cout << book3 << "\n\n";
    }

    if (book1 != book2) {
        std::cout << book2 << "\n\n";
    }

    system("pause");
    return 0;
}
catch (std::exception& e) {
	std::cerr << "exception: " << e.what() << std::endl;
	ppp::keep_window_open();
	return 1;
}
catch (...) {
	std::cerr << "exception\n";
	ppp::keep_window_open();
	return 2;
}

