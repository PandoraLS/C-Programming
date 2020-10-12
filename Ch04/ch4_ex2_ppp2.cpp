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
�ο����ӣ�[PPP2](https://github.com/Jtaim/Programming-Principles-and-Practice-Using-Cpp)
*/

#include "std_lib_facilities.h"

int main() {
    
    constexpr char termination = '|';
    vector<double> temperatures;        // temperatures
    cout << "����һЩ �¶� ����, ȷ����ֵ. " << termination << " to exit \n";
    
    for (char c{}; cin.get(c) && c != termination; c = '\0') {
        cin.putback(c);
        for (double temperature{}; cin >> temperature;) {
            temperatures.push_back(temperature);
        }
        // ʹ��txt�ļ���ʱ��EOF�ᱻ����
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

    // ������ֵ
    if (!temperatures.empty()) {
        double sum = accumulate(temperatures.begin(), temperatures.end(), 0.0);     // ������������accumulate�ĳ�ʼֵ
        cout << "ƽ��ֵ��" << sum / temperatures.size() << endl;
        sort(temperatures.begin(), temperatures.end());
        if ((temperatures.size() % 2) > 0) {
            cout << "��ֵ��" << temperatures[temperatures.size() / 2] << endl;
        } else {
            cout << "��ֵ��" << (temperatures[temperatures.size() / 2 - 1] + temperatures[temperatures.size() / 2]) / 2.0 << endl;
        }
    } else {
        cout << "no data found \n";
    }
    keep_window_open();
    return 0;
}

