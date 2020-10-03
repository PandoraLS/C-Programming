/*
 * @Author: seenli 
 * @Date: 2020-10-03 15:19:09 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-03 15:27:10
 */

/*
 * Section 3.5
 */

#include "std_lib_facilities.h"
int main(){
    string previous = " ";
    string current;
    while (cin >> current){
        if (previous == current)
            cout << "ÖØ¸´µ¥´Ê£º" << current << endl;
        previous = current;
    }
    keep_window_open();
    return 0;
}