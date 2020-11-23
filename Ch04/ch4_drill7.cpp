/*
 * @Author: seenli 
 * @Date: 2020-10-06 20:23:41 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-23 21:52:46
 */

#include <cfloat>
#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // 终止符 
    const string instructions{"输入1个double型数字(带单位)或输入 " + string{terminationChar} + " 终止输入."};
    const unordered_map<string, double> convert {
        {"m", 100.0},       // convert to cm
        {"cm", 1.00},       // leave as is
        {"in", 2.54},       // convert to cm
        {"ft", 12.0 * 2.54} // convert to cm
    };
    
    cout << instructions << "\n";
    char c{};
    while (cin.get(c) && c != terminationChar) {
        cin.putback(c);                 // 将c放回输入流
        static double min{DBL_MAX};     // DBL_MAX 需要 #include <cfloat>
        static double max{DBL_MIN};

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
            cout << enteredMeasurement << unitOfMeasure << " converted to " << convertedMeasurement << "cm\n";
            if (min > convertedMeasurement) {
                min = convertedMeasurement;
                cout << convertedMeasurement << "cm is the smallest so far \n\n";
            }
            if (max < convertedMeasurement) {
                max = convertedMeasurement;
                cout << convertedMeasurement << "cm is the largest sof far \n\n";
            }
        } else if (unitOfMeasure.find(terminationChar) != string::npos) {   
            // string::npos 表示 non-position
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
