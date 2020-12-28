/*
 * @Author: seenli
 * @Date: 2020-12-26 16:55:04
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-28 12:37:41
 * @FilePath: \Ch06\ch06_ex08.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
Section 6 exercise 8
Rewrite Section 5 exercise 12 Bulls and Cows game to use 4 letters not 4 numbers.
*/

#include "std_lib_facilities.h"

using vType = vector<char>;
bool get_guesses(vType& input, const char term);
int get_bulls(const vType& guesses, vType& setSequence);
int get_cows(const vType& guesses, vType& setSequence);
const vType::value_type foundMark = '?';

int main()
try {
    const char termination = '|';
    vType const setLetters{'a', 'b', 'c', 'd'};
    vType guesses{};
    guesses.reserve(setLetters.size());

    cout << "Guess " << setLetters.size() << " letters in the range of a - z to guess what I have.\n";
    cout << "If guess a correct letter and the correct location will get a Bull.\n";
    cout << "If guess a correct letter but not the correct location then will get a Cow.\n";
    cout << "Example: My set is abcd and your guess was acbe, so there are 2 Cows (b and c)  1 Bull (a).\n\n";
    cout << "Enter your guess.  To quit enter |.\n";

    while (get_guesses(guesses, termination)) {
        if (guesses == setLetters) {
            cout << "you have " << setLetters.size() << " Bulls, Congratulations!\n";
            break;
        } else {
            auto temp = setLetters;
            auto bulls = get_bulls(guesses, temp);
            auto cows = get_cows(guesses, temp);
            
            cout << "The result is " << cows << (cows == 1 ? " Cow" : " Cows");
            cout << " and " << bulls << (bulls == 1 ? " Bull": " Bulls") << ". Try again" << endl;
            guesses.clear();
        }
    }
    cout << "Bye\n";
    keep_window_open();
    return 0;
}

catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown error" << endl;
    keep_window_open();
    return 2;
}


/**
 * @description: 获取用户输入的字母
 * @input: vType用来存放有效guess
 * @output: true:有效guess, false: 无效guess
 * @error: 无效guess或终止符
 */
bool get_guesses(vType& input, const char term) {
    for (vType::size_type itr = 0; itr < input.capacity(); ++itr) {
        char guess{};
        cin >> guess;
        
        // 检查终止符
        if (guess == term) {
            return false;
        }
        else if (isalpha(guess)) {          // 将字符放进vector中
            vType::value_type i = guess;
            input.push_back(i);
        } else {
            error("Bad entry data!");
        }
    }
    return !input.empty();
}


/* function to bulls.
INPUT: vType reference to user input guesses.
	   vType reference to number to guess.
OUPUT: int for number of bulls found
ERROR: no error.
modifies set sequence by setting matching elements to type max number
*/
int get_bulls(const vType& guesses, vType& setSequence)
{
	int bulls{};
	auto j{setSequence.begin()};
	for(auto i{guesses.cbegin()}; i < guesses.cend(); ++i, ++j){
		if(*i == *j){
			++bulls;
			*j = foundMark;     // foundMark标记走过的部分，且符合bulls条件的部分
            // 执行完这一步之后，符合bulls条件的部分已经被标记为foundMark，后续cows条件应该是剔除掉bulls之后再进行统计
            // 所以需要foundMark将bulls的先标记了
		}
	}
	return bulls;
}


/* function to cows.
INPUT: vType reference to user input guesses.
	   vType reference to number to guess.
OUPUT: int for number of cows found
ERROR: no error.
modifies set sequence by setting matching elements to type max number
*/
int get_cows(const vType& guesses, vType& setSequence)
{
	int cows{};
	for(auto j{setSequence.begin()}; j < setSequence.end(); ++j){
		for(auto i{guesses.cbegin()}; i < guesses.cend(); ++i){
			if(*i == *j){
				++cows;
				*j = foundMark;
				break;
			}
		}
	}
	return cows;
}
