/*
 * @Author: seenli
 * @Date: 2021-01-03 23:26:02
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-03 23:33:48
 * @FilePath: \Ch08\ch08_drill3.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


#include "std_lib_facilities.h"

namespace X
{
    int var{};

    void print() {
        cout << "Printing from namespace X the value " << var << endl;
    }
} // namespace X

namespace Y
{
    int var{};

	void print()
	{
		cout << "Printing from namespace Y the value " << var << "\n";
	}
} // namespace Y

namespace Z
{
	int var{};

	void print()
	{
		cout << "Printing from namespace Z the value " << var << "\n";
	}
}

int main() {
    X::var = 7;
    X::print();
    using namespace Y;
    var = 9;
    print();
    {
        using Z::var;
        using Z::print;
        var = 11;
        print();
    }
    print();
    X::print();
    system("pause");
    return 0;
}


