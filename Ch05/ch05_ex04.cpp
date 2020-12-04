/*
 * @Author: seenli 
 * @Date: 2020-12-04 20:00:07 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-04 20:18:39
 */

/*
    sect 5 exercise 4
    Celsius to Kelvin converter
    throws error in function if input is below absolute 0
*/

#include "std_lib_facilities.h"

// 将摄氏转换为开式
double ctok(double c) {
    // 当所给摄氏温度低于-273.15时，抛出错误
    if (c < -273.15) {
        error("can not be below absolute zero !\n");
    }
    constexpr double conversion_constant{273.15};
    double celsiusToKelvin{c + conversion_constant};
    return celsiusToKelvin;
}

int main()
try{
    cout << "输入摄氏温度，转换为开式温度" << endl;
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
    cerr << "Oops: unknown exception!" << endl;
    keep_window_open();
    return 2;
}

