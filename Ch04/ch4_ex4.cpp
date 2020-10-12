/*
 * @Author: seenli 
 * @Date: 2020-10-09 16:21:21 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-09 19:41:02
 */

/*
    Section 4 exercise 4.
    A program to play a numbers guessing game.
    The user thinks of a number between 1 and 100 and your program asks questions to figure out what the number is
    (e.g., "Is the number you are thinking of less than 50?").
    Your program should be able to identify the number after asking no more than seven questions.
    Hint: Use the < and <= operators and the if-else construct.
*/

#include "std_lib_facilities.h"

int main() {
    constexpr int maxRange{100};            // maximum number can select
    constexpr int minRange{1};              // minimum number can guess
    constexpr int maxGuessAttempts{7};      // maximum number of times to ask before identifying the number
    // 7次是因为  log100/log2 约等于7

    int high{maxRange};                     // 确定最大值                     
    int low{minRange};                      // 确定最小值 
    int guess{(high - low) / 2 + low};      // 确定下一次guess
    int guessAttempts{};                    // 猜测次数

    cout << "输入一个在" << low << "和" << high << "之间的数, let me try to guess it by asking some questions. \n";

    bool isFound{false};
    while (!isFound && guessAttempts < maxGuessAttempts) {
        cout << "Is your number <= " << guess << " (y or n)? ";
        char yesOrNo {};
        cin >> yesOrNo;
        yesOrNo = static_cast<unsigned char>(tolower(yesOrNo));
        if (yesOrNo == 'y' || yesOrNo == 'n') {
            guessAttempts++;
            if (yesOrNo == 'y') {
                high = guess;
            } else {
                low = guess + 1;
            }

            if (high == low) {
                isFound = true;
            } else {
                guess = (high - low) / 2 + low;
            }
        } else {
            cout << "你尚未选择一个有效答案(y or n). 请重新选择\n";
        }
    }

    if (isFound) {
        cout << "发现answer " << high << " in " << guessAttempts << " guesses. \n";
    } else {
        simple_error("超过最大猜测次数 \n");
    }

    keep_window_open();
    return 0;
}