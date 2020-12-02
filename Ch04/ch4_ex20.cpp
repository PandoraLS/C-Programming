/*
 * @Author: seenli 
 * @Date: 2020-12-02 18:34:01 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-02 19:55:26
 */

/*
    Section 4 exercise 20.
    Modify exercise 19 so that when you enter a name, the program will output the
    corresponding score or name not found.
*/

#include "std_lib_facilities.h"

int main() {
    using pType = pair<string, double>;
	pType name_score;
	vector<pType> ranks{{"Moe",1}, {"Larry",2}, {"Curly", 3},{"Shemp",4}};

	cout << "Enter a name to find a score.\n";
	for(auto i{ranks.begin()}; i != ranks.end(); ++i) {
		cout << i->first << (((i + 1) != ranks.end()) ? ", " : "\n");
	}

    while (true) {
        string name;
        cin >> name;
        // escape if NoName or EOF
        if (cin.eof() || name == "NoName") {
            break;
        }

        // 设置名称, 使第一个字母大写，其余字母小写
        name[0] = static_cast<unsigned char>(toupper(name[0]));
        transform(name.begin() + 1, name.end(), name.begin() + 1,
            [](char c){return static_cast<unsigned char>(tolower(c)); });

        // 检查name是否在list中
        auto itr{find_if(ranks.cbegin(), ranks.cend(),
            [&name](pType ns) {return ns.first == name;})};
        
        if (ranks.cend() != itr) {
            cout << name << "'s score is " << itr->second << ".\n";
        } else {
            cout << "Name not found. \n";
        }
    }
    
    keep_window_open();
    return 0;
}

