/*
 * @Author: seenli 
 * @Date: 2020-10-13 00:41:57 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-13 01:14:15
 */

/*
Section 4 exercise 13.
 Create a program to find all the prime numbers between 1 and 100.
 There is a classic method for doing this, called the “Sieve of Eratosthenes.”
 If you don’t know that method, get on the web and look it up. Write your program using this method.
 https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 https://www.geeksforgeeks.org/sieve-of-eratosthenes/
*/

#include "std_lib_facilities.h"

void SieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        // 如果 prime[p]未改变(仍是true), then it is a prime
        if (prime[p] == true) {
            // 将所有大于p的倍数或者等于 p^2 的数都标记为false
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false;
        }
    }

    // 打印所有的prime numbers
    for (int p{2}; p <= n; p++) {
        if (prime[p])
            cout << p << " ";
    }
}

int main() {
    vector<int> primes{2};
    int max{};
    cout << "请输入一个数字max, 程序会输出以max为上限的素数: ";

    if (!(cin >> max)) {
        simple_error("Invalid input");
    }
    SieveOfEratosthenes(max);
    cout << '\n';
    keep_window_open();
    return 0;
}

