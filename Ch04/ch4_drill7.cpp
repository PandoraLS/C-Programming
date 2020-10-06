/*
 * @Author: seenli 
 * @Date: 2020-10-06 20:23:41 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-06 22:06:22
 */

#include <cfloat>
#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // ��ֹ��
    const string instructions{"����1��double�����ֻ����� " + string{terminationChar} + " ��ֹ����."};
    constexpr double tolerance = 1.0 / 100;     // ����
    const unordered_map<string, double> convert {
        {"m", 100.0},       // convert to cm
        {"cm", 1.00},       // leave as is
        {"in", 2.54},       // convert to cm
        {"ft", 12.0 * 2.54} // convert to cm
    };
    
    cout << instructions << "\n";
    char c{};
    while (cin.get(c) && c != terminationChar) {
        cin.putback(c);             // ��c�Ż�������
        static double min{DBL_MAX};
        static double max{DBL_MIN};

        // get number
        static double enteredMeasurement{};
        cin >> enteredMeasurement;
        if (!cin) {
            cin.clear();                // ��ԭ�����־λ
            enteredMeasurement = 1.0;   // ���û������number, Ĭ������Ϊ1
        }

        // get unit of measure
        static string unitOfMeasure;
        cin >> unitOfMeasure;

        // ��������λ����Ч�Բ�����ת��
        auto itr{convert.find(unitOfMeasure)};
        
        // ת��������λ to cm Ȼ��洢��vector��
        if (itr != convert.end()) {
            static double convertedMeasurement{};
            convertedMeasurement = enteredMeasurement * itr->second;
            cout << enteredMeasurement << unitOfMeasure << " converted to " 
            << convertedMeasurement << "cm\n";
            if (min > convertedMeasurement) {
                min = convertedMeasurement;
                cout << convertedMeasurement << "cm is the smallest so far \n\n";
            }
            if (max < convertedMeasurement) {
                max = convertedMeasurement;
                cout << convertedMeasurement << "cm is the largest sof far \n\n";
            }
        } else if (unitOfMeasure.find(terminationChar) != string::npos) {
            break;
        } else {
            cout << "Entry was an invalid number or termination, please try again. \n";
        }
        cout << instructions << '\n';
    }
    cout << "termination '" << terminationChar << "' found \n";

    keep_window_open();
    return 0;
}
