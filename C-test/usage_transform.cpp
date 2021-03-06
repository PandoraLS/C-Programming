/*
 * @Author: seenli 
 * @Date: 2020-10-10 12:17:01 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-10 12:38:51
 */

/*
transform�÷�
�ο����ӣ�https://blog.csdn.net/fengbingchun/article/details/63252470
*/

#include <algorithm> // std::transform
#include <string>
#include <cctype> // std::toupper
#include <iostream>
#include <vector>
#include <functional> // std::plus c++14
 
#ifndef FBC_MESSY_TEST_TRANSFROM_HPP_
#define FBC_MESSY_TEST_TRANSFROM_HPP_

int test_transform1();
int test_transform2();

#endif // FBC_MESSY_TEST_TRANSFROM_HPP_

using namespace std;

int test_transform1()
{
	std::string s("Hello");
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
	std::cout << s << std::endl; // HELLO

	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	std::cout << s << std::endl; // hello

	std::vector<int> arr{ 1, 3, 5 };
	std::vector<int> arr2{ 1, 3, 5 };
	std::vector<int> arr3{ 1, 3, 5 };
 
	std::transform(arr.begin(), arr.end(), arr.begin(),
		[](int d) -> int {return d * 5; }); // for_each
	for (auto value : arr) {
		std::cout << value << "    "; // 5 15 25
	}
	std::cout<<std::endl;

	std::for_each(arr2.begin(), arr2.end(), [](int& a) {a *= 5; });
	for (auto value : arr2) {
		std::cout << value << "    "; // 5 15 25
	}
	std::cout << std::endl;
 
	for (auto& value : arr3) {
		value *= 5;
	}
	for (auto value : arr3) {
		std::cout << value << "    "; // 5 15 25
	}
	std::cout << std::endl;
 
	std::vector<std::string> names = { "hi", "test", "foo" };
	std::vector<std::size_t> name_sizes;
 
	///
	std::transform(names.begin(), names.end(), std::back_inserter(name_sizes),
		[](std::string name) { return name.size(); });
	for (auto value : name_sizes) {
		std::cout << value << "    "; // 2 4 3
	}
	std::cout << std::endl;
 
	std::for_each(name_sizes.begin(), name_sizes.end(), [](std::size_t name_size) {
		std::cout << name_size << "    "; // 2 4 3
	});
	std::cout << std::endl;
 
	return 0;
}
 
 
// reference: http://www.cplusplus.com/reference/algorithm/transform/
static int op_increase(int i) { return ++i; }
 
int test_transform2()
{
	std::vector<int> foo;
	std::vector<int> bar;
 
	// set some values:
	for (int i = 1; i<6; i++)
		foo.push_back(i * 10); // foo: 10 20 30 40 50
 
	bar.resize(foo.size()); // allocate space
 
	std::transform(foo.begin(), foo.end(), bar.begin(), op_increase);
	// bar: 11 21 31 41 51
 
	// std::plus adds together its two arguments:
	std::transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
	// foo: 21 41 61 81 101
 
	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << ' ' << *it; // 21 41 61 81 101
	std::cout << '\n';
 
	return 0;
}


int main() {
    cout << "test_transform1...\n";
    test_transform1();
    cout << "\n\ntest_transform2...\n";
    test_transform2();
    system("pause");
    return 0;
}

