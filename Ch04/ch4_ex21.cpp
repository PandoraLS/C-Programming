/*
 * @Author: seenli 
 * @Date: 2020-12-02 19:56:21 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-02 20:23:13
 */


#include "std_lib_facilities.h"

int main() {

    using pType = pair<string, double>;
    pType name_score;
    vector<pType> ranks{{"Moe", 1}, {"Larry", 3}, {"Curly", 3}, {"Shemp", 4}};

    cout << "Enter a score to find a name. \n";
    for (auto i{ranks.begin()}; i != ranks.end(); i++) {
        cout << i->second << (((i + 1) != ranks.end()) ? ", " : "\n");
    }

    double score{};
    if (cin >> score) {
        // 查找到所有have that score的
        vector<vector<pType>::iterator> itrs;
        for (auto itr = ranks.begin();  itr < ranks.end(); itr++) {
            if (itr->second == score) {
                itrs.push_back(itr);
            }
        }

        // 是否match
        if (!itrs.empty()) {
            for (auto itr : itrs) {
                cout << "Name: " << itr->first << "\tScore: " << itr->second << endl;
            }
        } else {
            cout << "No matching names with a score of " << score << ".\n";
        }
    } else {
        cout << "Invalid score entered! \n";
    }

    keep_window_open();
    return 0;
}

