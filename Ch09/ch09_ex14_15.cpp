/*
 * @Author: seenli
 * @Date: 2021-01-09 14:40:04
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-11 13:41:23
 * @FilePath: \Ch09\ch09_ex14_15.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
	Section 9 Exercise 14
	this is the test program Money class.
	Section 9 Exercise 15
	this is the test program Money class.

	编译链接命令：在 Ch09/ 文件夹下：
	g++ -g ch09_ex14_15.cpp Money.cpp -o ch09_ex14_15.exe
	运行命令：
	.\ch09_ex14_15.exe
	输出结果：
	$200.00
	$5123.57
	$0.01
	$0.00
	$1.00
	$1.00
	$105.00
	Kr110.02
	Kr130.02
	$2.00
	Kr15.30
	请按任意键继续. . . 
*/

#include "ppp.h"
#include "Money.h"
#include <cstdlib>

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

	// 以下是ch09_ex15题
	Money m9{"USD104.995"};
	std::cout << m9.get_cents() << '\n';

	Money m10{"DKK109.995"};
	std::cout << m10.get_cents() << '\n';

	Money m11{"Kr129.995"};
	std::cout << m11.get_cents() << '\n';

	Money m12 = m5 + Money{"DKK6.8"};
	std::cout << m12.get_cents() << '\n';

	Money m13 = Money{"DKK8.5"} + m5;
	std::cout << m13.get_cents() << '\n';

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
