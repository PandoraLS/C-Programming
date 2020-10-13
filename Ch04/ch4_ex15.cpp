/*
 * @Author: seenli 
 * @Date: 2020-10-13 14:17:03 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-13 16:09:12
 */

/*
 Section 4 exercise 15.
 A program that takes an input value n and then finds the first n primes
*/

#include "std_lib_facilities.h"

int main() {
    vector<int> primes{2};
    int count{1};       // 计数质数的个数, 2已经被记录
    int i{3};           // i用来后续索引每个数
    int n{};            // 程序最终会输出n个数
    cout << "请输出一个数字n, 程序会输出n个素数：\n";
    if (!(cin >> n)) {
        simple_error("Invalid input");
    }

    while (count < n) {
        bool isPrime{true};
        for (auto prime : primes) {
            if (i % prime == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
            count++;
        }
        i++;
    }

    int j{1};
    for (auto prime: primes) {
        if (j % 10){
            cout << prime << "\t";
        } else {
            cout << prime << endl;
        }
        j++;
    }
    cout << "\n";
    keep_window_open();
    return 0;
}