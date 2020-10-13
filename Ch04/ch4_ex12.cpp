/*
 * @Author: seenli 
 * @Date: 2020-10-12 21:18:52 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-13 00:37:38
 */

#include "std_lib_facilities.h"

int main() {
    vector<int> primes{2};
    int max{};
    cout << "请输入一个数字max, 程序会输出以max为上限的素数: ";

    if (!(cin >> max)) {
        simple_error("Invalid input");
    }

    for (int i{3}; i <= max; i++) {
        bool is_prime = true;
        for (auto prime : primes) {
            if (i % prime == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
        }
    }

    int j{1};
    // 打印素数
    for (auto x : primes) {
        if (j % 10) {
            cout << x << '\t';
        } else {
            cout << x << endl;
        }
        j++;
    }

    cout << '\n';
    keep_window_open();
    return 0;
}
