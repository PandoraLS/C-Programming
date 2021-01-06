/*
 * @Author: seenli
 * @Date: 2021-01-06 19:17:15
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-06 19:23:36
 * @FilePath: \Ch09\ch09_ex05.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
	Section 9 Exercise 5
	Design and implement a Book class under library namespace
*/

#include "ppp.h"
#include "Book.h"

int main()
try {
    library::Book book ("0-321-99278-4", 
    	"Programming Principles and Practices Using C++ Second Edition", "Bjarne Stroustrup", 2014);
    std::cout << "ISBN: " << book.get_isbn() << '\n'
        << "TITLE: " << book.get_title() << '\n'
		<< "AUTHOR: " << book.get_author() << '\n'
		<< "COPYRIGHT: " << book.get_copyright() << '\n'
		<< "checked out: " << std::boolalpha << book.is_checked_out() << "\n\n";
    
    book.check_inout(true);
    std::cout << "ISBN: " << book.get_isbn() << '\n'
		<< "TITLE: " << book.get_title() << '\n'
		<< "AUTHOR: " << book.get_author() << '\n'
		<< "COPYRIGHT: " << book.get_copyright() << '\n'
		<< "checked out: " << std::boolalpha << book.is_checked_out() << "\n\n";

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
