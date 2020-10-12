/*
 * @Author: seenli 
 * @Date: 2020-10-12 18:16:26 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-12 19:52:24
 */

/*
Section 4 exercise 10.
 Write a program that plays the game ��Rock, Paper, Scissors.��
 If you are not familiar with the game do some research (e.g., on the web using Google).
 Research is a common task for programmers. Use a switch-statement to solve this exercise.
 Also, the machine should give random answers (i.e., select the next rock, paper, or scissors randomly).
 Real randomness is too hard to provide just now, so just build a vector with a sequence of values to be
 used as ��the next value.�� If you build the vector into the program, it will always play the same game,
 so maybe you should let the user enter some values.
 Try variations to make it less easy for the user to guess which move the machine will make next.
*/

#include "std_lib_facilities.h"

int main() {
    random_device rd;                               // ���ڻ�ȡ�����������
    mt19937 gen(rd());                              // ÷ɭ��ת�㷨ȷ��α�����
    uniform_int_distribution<> dis(0, 2);           // ��ɢ���ȷֲ�, ��Χ0~2

    vector<string> rps{"ROCK", "PAPER", "SCISSORS"};
    
    bool playAgain{false};
    do {
        cout << "ѡ��  (0) for Rock, (1) for Paper, (2) for Scissors\n";
        // ��������Ƿ����
        int pSelect {};
        if (!(cin >> pSelect) || pSelect > 2) {
            simple_error("selected r/p/s poorly");
        }
        auto cSelect{dis(gen)};     // ֻ��3��ѡ�� ��0��1��2�����ѡ��
        cout << "Your selection was " << rps.at(pSelect) << ", the computer selected " << rps.at(cSelect) << endl;
        cout << "\nWould you like to play again (y or n)" << endl;
        char c;
        cin >> c;
        // �����ʵ�����
        c == 'y' ? playAgain = true : playAgain = false;
    } while (playAgain);
    
    keep_window_open();
    return 0;
}
