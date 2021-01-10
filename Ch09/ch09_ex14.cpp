/*
 * @Author: seenli
 * @Date: 2021-01-09 14:40:04
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-10 14:55:56
 * @FilePath: \Ch09\ch09_ex14.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


/*
	Section 9 Exercise 14
	this is the test program Money class.
	编译链接命令：
	C:\software\mingw-w64\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe -g C:\Education\code\C-Programming\Ch09\ch09_ex14.cpp C:\Education\code\C-Programming\Ch09\Money.cpp -o C:\Education\code\C-Programming\Ch09\ch09_ex14.exe
	运行命令：
	.\ch09_ex14.exe
	输出结果：
	$200.00
	$5123.57
	$0.01
	$0.00
	$1.00
	$1.00
	请按任意键继续. . . 
*/

#include "ppp.h"
#include "Money.h"
#include <stdlib.h>

int main()
try {
    Money m1{"$199.999"};
    std::cout << m1.get_cents() << '\n';

    Money m2{"$5123.5689"};
	std::cout << m2.get_cents() << '\n';

	Money m3{"$0.005"};
	std::cout << m3.get_cents() << '\n';

	Money m4{"$0.004"};
	std::cout << m4.get_cents() << '\n';

	Money m5{"$1"};
	std::cout << m5.get_cents() << '\n';

	Money m6{"$.995"};
	std::cout << m6.get_cents() << '\n';

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