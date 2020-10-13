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
    int count{1};       // ���������ĸ���, 2�Ѿ�����¼
    int i{3};           // i������������ÿ����
    int n{};            // �������ջ����n����
    cout << "�����һ������n, ��������n��������\n";
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