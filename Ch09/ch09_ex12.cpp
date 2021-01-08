/*
 * @Author: seenli
 * @Date: 2021-01-08 21:22:23
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-08 21:35:18
 * @FilePath: \Ch09\ch09_ex12.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
	Section 9 Exercise 12
	this is the test program.
	- change the representation of a Date to be number of days sense Jan 1, 1970
*/

#include "../includes/ppp.h"
#include "Chrono.h"

int main()
try {
    Chrono::Date d1{2019,Chrono::Month::mar, 18};

	std::cout << d1 << " Week#: " << week_of_year(d1) << '\n';

	Chrono::Date n_day{};

	std::cout << n_day << " Week#: " << week_of_year(n_day) << '\n';

	n_day.add_day(367);

	std::cout << n_day << " Week#: " << week_of_year(n_day) << '\n';

	n_day.add_year(2);

	std::cout << n_day << " Week#: " << week_of_year(n_day) << '\n';

	n_day.add_month(1);
	n_day.add_day(26);

	std::cout << n_day << " Week#: " << week_of_year(n_day) << '\n';

	n_day.add_month(11);

	std::cout << n_day << " Week#: " << week_of_year(n_day) << '\n';

	n_day.add_month(1);
	std::cout << n_day << " Week#: " << week_of_year(n_day) << '\n';

	n_day.add_month(1);
	std::cout << n_day << " Week#: " << week_of_year(n_day) << '\n';

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

