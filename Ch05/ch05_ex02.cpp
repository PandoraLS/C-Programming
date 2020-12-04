/*
 * @Author: seenli 
 * @Date: 2020-12-04 19:23:22 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-04 20:14:32
 */

/*
    sect 5 exercise 2
    find errors and document
*/

#include "std_lib_facilities.h"

// 摄氏转华氏
double ctok(double c) {
    constexpr double conversion_constant{273.15};
    double celsiusToKelvin{c + conversion_constant};
    return celsiusToKelvin;
}

int main()
try{
    cout << "输入温度, 并由摄氏转开式 \n";
    double celsius{};
    cin >> celsius;
    double kelvin{ctok(celsius)};
    cout << kelvin << endl;
    keep_window_open();
    return 0;
}

catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}

catch (...) {
    cerr << "Oops: unknown exception! \n";
    keep_window_open();
    return 2;
}

