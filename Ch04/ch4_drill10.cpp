/*
 * @Author: seenli 
 * @Date: 2020-10-09 13:58:00 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-09 14:03:19
 */


#include <cfloat>
#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // ��ֹ��
    const string instructions{"����1��double�����֣���λ �� ���� " + string{terminationChar} + " ��ֹ����."};
    // constexpr double tolerance = 1.0 / 100;     // ����
    const unordered_map<string, double> convert {
        {"m", 1.0},       // leave as is 
        {"cm", 0.01},       // convert to cm
        {"in", 0.0254},       // convert to cm
        {"ft", 12.0 * 0.0254} // convert to cm
    };
    
    vector<double> enteredMeasurements;
    cout << instructions << "\n";
    char c{};
    while (cin.get(c) && c != terminationChar) {
        cin.putback(c);                 // ��c�Ż�������

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
            enteredMeasurements.push_back(convertedMeasurement);
            cout << enteredMeasurement << unitOfMeasure << " converted to " << convertedMeasurement << "m\n";
        } else if (unitOfMeasure.find(terminationChar) != string::npos) {   // string::npos���Ա�ʾ�ַ���������λ��
            break;
        } else {
            cout << "Entry was an invalid unit of measure or termination, please try again. \n";
        }
        cout << instructions << '\n';
    }
    cout << "termination '" << terminationChar << "' found \n";
    
    // ���measurements
    if (!enteredMeasurements.empty()) {
        cout << "Values collected: \n";
        for (const auto i : enteredMeasurements) {
            cout << i << "m" << endl;
        }
        sort(enteredMeasurements.begin(), enteredMeasurements.end());
        cout << "�������ݵ�������" << enteredMeasurements.size() << '\n';
        cout << "����������Сֵ��" << enteredMeasurements.front() << "m\n";
        cout << "�����������ֵ��" << enteredMeasurements.back() << "m\n";
        cout << "��Ч������ͣ�  " << accumulate(enteredMeasurements.cbegin(), enteredMeasurements.cend(), 0.0) << "m\n";
    }

    keep_window_open();
    return 0;
}