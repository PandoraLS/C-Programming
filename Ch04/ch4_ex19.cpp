/*
 * @Author: seenli 
 * @Date: 2020-12-02 16:32:28 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-02 19:16:38
 */

/*
    Section 4 exercise 19.
    A program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22.
    For each pair, add the name to a vector called names and the number to a vector called scores
    (in corresponding positions, so that if names[7]=="Joe" then scores[7]==17).
    Terminate input with NoName 0.
    Check that each name is unique and terminated with an error message if a name is entered twice.
    Write out all the (name, score) pairs, one per line.
*/

#include "std_lib_facilities.h"

int main() {
    using pType = pair<string, double>;
    pType name_score;
    vector<pType> ranks;
    
    cout << "Enter names and scores: " << endl;
    while (true) {
        cin >> name_score.first >> name_score.second;

        // break if EOF and !(NoName and 0)
        if (cin.good() && !(name_score.first == "NoName" && name_score.second == 0)) {
            transform(name_score.first.begin(), name_score.first.end(), name_score.first.begin(), 
                [](char name) {return static_cast<unsigned char>(tolower(name)); });

            // check if duplicated
            if (ranks.cend() != find_if(ranks.cbegin(), ranks.cend(), 
                [&name_score](pType ns){return ns.first == name_score.first; })) {
                    simple_error("found a duplicated name");
                }
            ranks.push_back(name_score);
        } else {
            break;
        }
    }

    if (!ranks.empty()) {
        // 输出所有数据
        for (const auto i: ranks) {
            cout << "name: " << i.first << "\tscore: " << i.second << endl;
        }
    } else {
        cout << "nothing entered" << endl;
    }
    
    keep_window_open();
    return 0;
}

