/*
 * @Author: seenli 
 * @Date: 2020-10-09 15:59:12 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-09 16:20:47
 */

/*
    Section 4 exercise 3.
    Read a sequence of double values into a vector.
    Think of each value as the distance between two cities along a given route.
    Compute and print the total distance (the sum of all distances).
    Find and print the smallest and greatest distance between two neighboring cities.
    Find and print the mean distance between two neighboring cities.
*/

#include "std_lib_facilities.h"

int main() {
    constexpr char termination = '|';
    vector<double> distances;
    cout << "����һЩ ���� ����, ȷ����ֵ, ƽ����, �����Сֵ. " << termination << " to exit \n";

    for (char c{}; cin.get(c) && c != termination; c = '\0') {
        cin.putback(c);
        for (double distance{}; cin >> distance;) {
            distances.push_back(distance);
        }
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

    // ����ƽ��ֵ, ��ֵ, ���ֵ
    if (!distances.empty()) {
        sort(distances.begin(), distances.end());
        double sum = accumulate(distances.begin(), distances.end(), 0.0);
        cout << "ƽ��ֵ��" << sum / distances.size() << endl;
        cout << "��Сֵ��" << distances.front() << endl;
        cout << "���ֵ��" << distances.back() << endl;
        cout << "��ͣ�" << sum << endl;
    }
    keep_window_open();
    return 0;
}

