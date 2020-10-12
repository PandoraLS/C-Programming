/*
 * @Author: seenli 
 * @Date: 2020-10-12 19:52:43 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-12 22:16:53
 */

/*
Section 4 exercise 11.
 Create a program to find all the prime numbers between 1 and 100.
 One way to do this is to write a function that will check if a number is prime
 (i.e., see if the number can be divided by a prime number smaller than itself)
 using a vector of primes in order (so that if the vector is called primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.).
 Then write a loop that goes from 1 to 100, checks each number to see if it is a prime, and stores each prime found in a vector.
 Write another loop that lists the primes you found.
 You might check your result by comparing your vector of prime numbers with primes. Consider 2 the first prime.
*/


#include "std_lib_facilities.h"

int main() {
    constexpr int max{100};
    vector<int> primes{2};
    
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
    for (auto x: primes) {
        if (j % 10) {       // 取余非零
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
