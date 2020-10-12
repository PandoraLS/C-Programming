/*
 * @Author: seenli 
 * @Date: 2020-10-09 14:04:37 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-09 14:53:44
 */

/*
Section 4 Drill step 11.
1. Write a program that consists of a while-loop that (each time around the loop)
   reads in two int numbers and then prints them. Exit the program when a terminating '|' is entered.
2. Change the program to write out the smaller value is: followed by the smaller of the
   numbers and the larger value is: followed by the larger value.
3. Augment the program so that it writes the line the numbers are equal (only) if
   they are equal.
4. Change the program so that it uses double instead of int.
5. Change the program so that it writes out the numbers are almost equal after writing
   out which is the larger and the smaller if the two numbers differ by less than 1.0 / 100.
6. Now change the body of the loop so that it reads just one double each time around.
   Define two variables to keep track of which is the smallest and which is the largest
   value you have seen so far. Each time through the loop write out the value entered.
   If it’s the smallest so far, write the smallest so far after the number.
   If it is the largest so far, write the largest so far after the number.
7. Add a unit to each double entered; that is, enter values such as 10cm, 2.5in, 5ft,
   or 3.33m. Accept the four units: cm, m, in, ft. Assume conversion factors
   1m == 100cm, 1in == 2.54cm, 1ft == 12in. Read the unit indicator into a string.
   You may consider 12 m (with a space between the number and the unit) equivalent to 12m (without a space).
8. Reject values without units or with “illegal” representations of units,
   such as y, yard, meter, km, and gallons.
9. Keep track of the sum of values entered (as well as the smallest and the largest)
   and the number of values entered. When the loop ends, print the smallest, the largest,
   the number of values, and the sum of values. Note that to keep the sum, you have to
   decide on a unit to use for that sum; use meters.
10.Keep all the values entered (converted into meters) in a vector.
   At the end, write out those values.
11.Before writing out the values from the vector, sort them (that’ll make them come out
   in increasing order).
*/


#include <cfloat>
#include "std_lib_facilities.h"

int main() {
    constexpr char terminationChar = '|';       // 终止符
    const string instructions{"输入1个double型数字＋单位 或 输入 " + string{terminationChar} + " 终止输入."};
    // constexpr double tolerance = 1.0 / 100;     // 误差精度
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
        } else if (unitOfMeasure.find(terminationChar) != string::npos) {   // string::npos可以表示字符串结束的位置
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
        cout << "Values collected: \n";
        for (const auto i : enteredMeasurements) {
            cout << i << "m" << endl;
        }
        cout << "输入数据的数量：" << enteredMeasurements.size() << '\n';
        cout << "输入数据最小值：" << enteredMeasurements.front() << "m\n";
        cout << "输入数据最大值：" << enteredMeasurements.back() << "m\n";
        cout << "有效输入求和：  " << accumulate(enteredMeasurements.cbegin(), enteredMeasurements.cend(), 0.0) << "m\n";
    }

    keep_window_open();
    return 0;
}
