/*
 * @Author: seenli 
 * @Date: 2020-10-09 15:10:07 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-09 15:58:51
 */

/*
Section 4 exercise 2.
If we define the median of a sequence as "a number so that exactly as many elements come before
it in the sequence as come after it," fix the program in ??4.6.3 so that it always prints out a median.
Hint: A median need not be an element of the sequence.
参考链接：[PPP2](https://github.com/Jtaim/Programming-Principles-and-Practice-Using-Cpp)
*/

#include "std_lib_facilities.h"

int main() {
    
    constexpr char termination = '|';
    vector<double> temperatures;        // temperatures
    cout << "输入一些 温度 数据, 确定中值. " << termination << " to exit \n";
    
    for (char c{}; cin.get(c) && c != termination; c = '\0') {
        cin.putback(c);
        for (double temperature{}; cin >> temperature;) {
            temperatures.push_back(temperature);
        }
        // 使用txt文件的时候EOF会被捕获
        if (cin.eof() || cin.bad()) {
            break;
        }
        cin.clear();
        static string str;
        cin >> str;
        if (str.find(termination) != string::npos) {
            break;
        }
    }

    // 计算中值
    if (!temperatures.empty()) {
        double sum = accumulate(temperatures.begin(), temperatures.end(), 0.0);     // 第三个参数是accumulate的初始值
        cout << "平均值：" << sum / temperatures.size() << endl;
        sort(temperatures.begin(), temperatures.end());
        if ((temperatures.size() % 2) > 0) {
            cout << "中值：" << temperatures[temperatures.size() / 2] << endl;
        } else {
            cout << "中值：" << (temperatures[temperatures.size() / 2 - 1] + temperatures[temperatures.size() / 2]) / 2.0 << endl;
        }
    } else {
        cout << "no data found \n";
    }
    keep_window_open();
    return 0;
}

