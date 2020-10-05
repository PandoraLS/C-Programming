/*
 * @Author: seenli 
 * @Date: 2020-10-05 20:47:16 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-05 21:37:08
 */

#include "std_lib_facilities.h"

int main() {
    const vector<string> dislikedWords {"broccoli", "peas", "spinach"};
    vector<string> words;

    // �����Կո����ĵ���
    for (string word; cin >> word;) {
        for (auto& c: word){
            c = static_cast<unsigned char>(tolower(c));
        }
        for (const auto str: dislikedWords) {
            if (str == word) {
                word = "BLEEP";
            }
        }
        words.push_back(word);      // ��word����words��
    }

    cout << "Numbers of words: " << words.size() << endl;
    for (auto str: words) {
        cout << str << " ";
    }
    cout << endl;
    
    keep_window_open();
    return 0;
}