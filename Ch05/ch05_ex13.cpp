/*
 * @Author: seenli
 * @Date: 2020-12-14 11:44:09
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-14 13:39:34
 * @FilePath: \Ch05\ch05_ex13.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
Section 5 exercise 13
Bulls and Cows game.
random generate the numbers to guess
Guess the 4 numbers range(0 to 9)
*/

#include "std_lib_facilities.h"

using vType = vector<int>;
bool get_guesses(vType& input, const char term);
int get_bulls(const vType& guesses, vType& setSequence);
int get_cows(const vType& guesses, vType& setSequence);
const vType::value_type foundMark = numeric_limits<vType::value_type>::max();
bool try_again(const string&);

int main()
try {
    const char termination = '|';
    const int guessSize = 4;        // 设置需要guess的数
    vType setNumbers;
    setNumbers.reserve(guessSize);
    vType guesses{};

    guesses.reserve(guessSize);

    random_device rd;
    // 梅森旋转法产生伪随机数
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 9);

    cout << "Guess " << guessSize << " numbers in the range of 0 - 9 to guess what I have.\n";
	cout << "If guess a correct number and the correct location will get a Bull.\n";
	cout << "If guess a correct number but not the correct location then will get a Cow.\n";
	cout << "Example: My set is 2345 and your guess was 5248, so there are 2 Cows (5 and 2)  1 Bull (4).\n\n";

    do {
        cout << "Enter your guess. To quit enter '" << termination << "'. \n\n";
        // Will be used to obtain a seed for the random number engine

        // 创建guessSize个随机数
        for (int i{0}; i < guessSize; ++i) {
            setNumbers.push_back(dis(gen));
        }

        while(get_guesses(guesses, termination)) {
            if (guesses == setNumbers) {
                cout << "You have " << setNumbers.size() << " Bulls, Congratulations!" << endl;
                break;
            } else {
                auto temp = setNumbers;
                auto bulls = get_bulls(guesses, temp);
                auto cows = get_cows(guesses, temp);

                cout << "The result is " << cows << (cows == 1 ? " Cow": " Cows");
                cout << " and " << bulls << (bulls == 1 ? " Bull" : " Bulls") << ". Try again. \n";
                guesses.clear();        // clear for new set of guesses
            }
        }

        guesses.clear();        // reset vectors
        setNumbers.clear();
    } while (try_again("Would you like to try again (y or n). \n"));

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

/**
 * @description: function to get user input for a yes or no answer.
 * @input: string for message you want displayed.
 * @output: bool
 * @error: none
 */
bool try_again(const string& s) {
    cout << s;
    char again{};
    cin >> again;
    again = narrow_cast<char, int>(tolower(static_cast<unsigned char>(again)));
    if (again == 'y') {
        return true;
    }
    cout << "Thanks for play, bye." << endl;
    return false;
}

