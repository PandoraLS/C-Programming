/*
 * @Author: seenli
 * @Date: 2020-12-13 16:31:29
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-13 17:59:29
 * @FilePath: \Ch05\ch05_ex12.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
Section 5 exercise 12
Bulls and Cows game.
Guess the 4 numbers range(0 to 9)
*/

#include "std_lib_facilities.h"

using vType = vector<int>;
bool get_guesses(vType& input, const char term);
int get_bulls(const vType& guesses, vType& setSequence);
int get_cows(const vType& guesses, vType& setSequence);
const vType::value_type foundMark = numeric_limits<vType::value_type>::max();

int main()
try {
    const char termination{'|'};

    vType const setNumbers{2, 3, 4, 5};
    vType guesses{};
    guesses.reserve(setNumbers.size());

    cout << "Guess " << setNumbers.size() << " numbers in the range of 0~9 to guess what I have" << endl;
    cout << "If guess a correct number and the correct location will get a Bull.\n";
	cout << "If guess a correct number but not the correct location then will get a Cow.\n";
	cout << "Example: My set is 2345 and your guess was 5248, so there are 2 Cows (5 and 2)  1 Bull (4).\n\n";
	cout << "Enter your guess.  To quit enter '" << termination << "'.\n";

    while(get_guesses(guesses, termination)) {
        if (guesses == setNumbers) {
            cout << "You have " << setNumbers.size() << " Bulls, Congratulations!\n";
            break;
        } else {
            auto temp = setNumbers;
            auto bulls = get_bulls(guesses, temp);
            auto cows = get_cows(guesses, temp);
            
            cout << "The result is " << cows << (cows == 1 ? " Cow" : " Cows");
            cout << " and " << bulls << (bulls == 1 ? " Bull" : " Bulls") << ". Try again" << endl;
            guesses.clear();            // 清除标志位 for 下一次输入
        }
    }

    cout << "Bye" << endl;
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!" << endl;
    keep_window_open();
    return 2;
}


/**
 * @description: function to get user input for guesses or termination.
 * @input: vType reference to place valid guesses in.
 * @output: bool true = got valid guesses
 *          bool false = got valid termination.
 * @error: invalid guess or termination.
 */
bool get_guesses(vType& input, const char term) {
    for (vType::size_type itr = 0; itr < input.capacity(); ++itr) {
        char guess{};
        cin >> guess;
        // check for valid number or escape entry
        if (guess == term) {
            return false;
        } else if (isdigit(guess)) {                //convert number char to integer and place into a vector
            vType::value_type i = guess - '0';      // '9'(57) - '0'(48) provides 0 to 9
            input.push_back(i);
        } else {
            error("Bad entry data!");
        }
    }
    return !input.empty();
}


/**
 * @description: function to bulls.modifies set sequence by setting matching elements to type max number
 * @input:  vType reference to user input guesses.
 *          vType reference to number to guess.
 * @output: int for number of bulls found
 * @error: no error.
 */
int get_bulls(const vType& guesses, vType& setSequence) {
    int bulls{};
    auto j{setSequence.begin()};
    auto i{guesses.cbegin()};
    for (; i < guesses.cend(); ++i, ++j) {
        if (*i == *j) {
            ++bulls;
            *j = foundMark; // 这里凡是查找到的值都设置为最大值, 因为后续还需要查找符合条件的cows
        }
    }
    return bulls;
}


/**
 * @description: function to cows.modifies set sequence by setting matching elements to type max number
 *               该程序运行在get_bulls()之后   
 * @input: vType reference to user input guesses.
           vType reference to number to guess.
 * @output: int for number of cows found
 * @error: no error. 
 */
int get_cows(const vType& guesses, vType& setSequence) {
    int cows{};
    for (auto j{setSequence.begin()}; j < setSequence.end(); ++j) {
        for (auto i{guesses.cbegin()}; i < guesses.cend(); ++i) {
            if (*i == *j) {
                ++cows;
                *j = foundMark;
                break;
            }
        }
    }
    return cows;
}

