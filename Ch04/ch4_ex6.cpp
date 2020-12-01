/*
 * @Author: seenli 
 * @Date: 2020-10-09 20:22:11 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-01 15:31:25
 */

/*
Section 4 exercise 6.
Make a vector holding the ten string values "zero", "one", . . . "nine".
Use that in a program that converts a digit to its corresponding spelled-out value; e.g., the input 7 gives the output seven.
Have the same program, using the same input loop, convert spelled-out numbers into their digit form; e.g., the input seven gives the output 7.
*/

#include "std_lib_facilities.h"

int main() {
    const vector<string> spelledNumbers {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    cout << "请输入0~9数字or其对应的英文拼写： \n";
    int number{};
    if (cin >> number) {
        if (number >= 0 && number <= 9) {
            cout << "输入的数字为" << spelledNumbers[number] << "\n\n";
        } else {
            cout << "输入的数字无法被拼写 \n";
        }
    } else {    // 说明输入的不是数字
        cin.clear();    // 清除错误标志位
        string spelledNumber;
        cin >> spelledNumber;

        // convert to lower  
        transform(spelledNumber.begin(), spelledNumber.end(), spelledNumber.begin(), [](char c) {
            return static_cast<unsigned char>(tolower(c));
        });

        // 检查是否有对应的拼写  
        auto spelledIndex = find(spelledNumbers.begin(), spelledNumbers.end(), spelledNumber);
        if (spelledIndex != spelledNumbers.end()) {
            cout << "输入数字为: " << (spelledIndex - spelledNumbers.begin()) << "\n\n";
        } else {
            cout << "could not find number. \n";
        }
    }
    keep_window_open();
    return 0;
}
