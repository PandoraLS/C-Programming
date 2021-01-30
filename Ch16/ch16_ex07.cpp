/*
 * @Author: seenli
 * @Date: 2021-01-30 16:14:10
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-30 16:39:20
 * @FilePath: \Ch16\ch16_ex07.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 16, Exercise 7: implement and test binary search for a vector<int> and a list<string>

#include "../includes/std_lib_facilities.h"

// 对带有随机访问迭代器的容器进行二分搜索
template<class Ran, class T>
bool my_binary_search(Ran first, Ran last, const T& val) {
    if (first == last) return false;                        // 序列为空
    Ran p = first + (last - first) / 2;
    if (*p == val) return true;
    if (*p < val && p + 1 != last) return my_binary_search(p, last, val);
    if (*p > val) return my_binary_search(first, p, val);
    return false;                                           // *p < val && p + 1 == last
}

// 返回两个双向迭代器之间的中间位置
template<class Bid>
Bid middle(Bid first, Bid last) {
    if (first == last) error("first == last in middle");

    // 计算距离
    int dist = 0;
    Bid p = first;
    while (p != last) {
        ++p;
        ++dist;
    }
    advance(first, dist / 2);
    return first;
}

//对带有双向迭代器的容器进行二分搜索，即不能计算两个迭代器之间的距离
template<class Bid, class T>
bool my_binary_bid_search(Bid first, Bid last, const T& val) {
    if (first == last) return false;                // 序列为空
    Bid p = middle(first, last);
    if (*p == val) return true;
    Bid p2 = last;
    --p2;
    if (*p < val && p != p2) return my_binary_bid_search(p, last, val);
    if (*p > val) return my_binary_bid_search(first, p, val);
    return false;                                   // *p<val && p==p2, i.e., we are looking at the last element
}

template<class Iter>
void print(Iter first, Iter last) {
    while (first != last) {
        cout << *first << '\n';
        ++first;
    }
}

int main()
try {
    // test for vector
    vector<int> vi;
    for (int i = 0; i<20; ++i)
        vi.push_back(2*i);
    cout << "Vector:\n";
    print(vi.begin(),vi.end());

    cout << "Enter int to find (-1 to exit): ";
    int i;
    while (cin>>i && i!=-1) {
        cout << i << " is "
            << (my_binary_search(vi.begin(),vi.end(),i) ? "" : "not ")
            << "in vi. Next int: ";
    }

    // test for list
    list<int> li(20);
    copy(vi.begin(),vi.end(),li.begin());
    cout << "\nList:\n";
    print(li.begin(),li.end());

    cout << "Enter int to find (-1 to exit): ";
    while (cin>>i && i!=-1) {
        cout << i << " is "
            << (my_binary_bid_search(li.begin(),li.end(),i) ? "" : "not ")
            << "in li. Next int: ";
    }

    system("pause");
    return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
	return 2;
}
