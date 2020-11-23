/*
 * @Author: seenli 
 * @Date: 2020-10-09 13:11:02 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-23 21:52:52
 */


#include <cfloat>
#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // 终止符
    const string instructions{"输入1个double型数字＋单位 或 输入 " + string{terminationChar} + " 终止输入."};
    const unordered_map<string, double> convert {
        {"m", 1.0},       // convert to cm
        {"cm", 0.01},       // leave as is
        {"in", 0.0254},       // convert to cm
        {"ft", 12.0 * 0.0254} // convert to cm
    };
    
    vector<double> enteredMeasurements;
    cout << instructions << "\n";
    char c{};
    while (cin.get(c) && c != terminationChar) {
        cin.putback(c);                 // 将c放回输入流

        // get number
        static double enteredMeasurement{};
        cin >> enteredMeasurement;
        if (!cin) {
            cin.clear();                // 复原错误标志位
            enteredMeasurement = 1.0;   // 如果没有输入number, 默认设置为1
        }

        // get unit of measure
        static string unitOfMeasure;
        cin >> unitOfMeasure;

        // 检查计量单位的有效性并进行转换
        auto itr{convert.find(unitOfMeasure)};
        
        // 转换计量单位 to cm 然后存储到vector中
        if (itr != convert.end()) {
            static double convertedMeasurement{};
            convertedMeasurement = enteredMeasurement * itr->second;
            enteredMeasurements.push_back(convertedMeasurement);
            cout << enteredMeasurement << unitOfMeasure << " converted to " << convertedMeasurement << "m\n";
        } else if (unitOfMeasure.find(terminationChar) != string::npos) {   // string::npos 表示 non-position
            break;
        } else {
            cout << "Entry was an invalid unit of measure or termination, please try again. \n";
        }
        cout << instructions << '\n';
    }
    cout << "termination '" << terminationChar << "' found \n";
    
    // 输出measurements
    if (!enteredMeasurements.empty()) {
        sort(enteredMeasurements.begin(), enteredMeasurements.end());
        cout << "输入数据的数量：" << enteredMeasurements.size() << '\n';
        cout << "输入数据最小值：" << enteredMeasurements.front() << "m\n";
        cout << "输入数据最大值：" << enteredMeasurements.back() << "m\n";
        cout << "有效输入求和：  " << accumulate(enteredMeasurements.cbegin(), enteredMeasurements.cend(), 0.0) << "m\n";
    }
    keep_window_open();
    return 0;
}
