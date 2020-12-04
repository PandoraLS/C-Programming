/*
 * @Author: seenli 
 * @Date: 2020-12-04 20:38:49 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-04 22:47:07
 */

/*
    sect 5 exercise 5
    Celsius to Kelvin converter
    Added Kelvin to Celsius converter
*/


#include "std_lib_facilities.h"

// 将摄氏转换为开式
double ctok(double c) {
    if (c < -273.15) {
        // 抛出error
        error("不可以低于绝对零度!");
    }
    constexpr double conversion_constant{273.15};
    double celsiusToKelvin{c + conversion_constant};
    return celsiusToKelvin;
}

// 将开式转换为摄氏
double ktoc(double k) {
    if (k < 0) {
        // 抛出error
        error("不可以低于绝对零度!");
    }
    constexpr double conversion_constant{273.15};
    double kelvinToCelsius{k - conversion_constant};
    return kelvinToCelsius;
}

int main() {
    using pType = pair<double, char>;
    pType inputTemperature{};

    try {
        cout << "输入temperature 和 单位(c = Celsius, k = Kelvin)" << endl;;

        // 获取温度
        if (!(cin >> inputTemperature.first)) {
            error("输入非法数字!");
        }

        // 获取单位
        cin >> inputTemperature.second;
        inputTemperature.second = narrow_cast<char, int>(tolower(inputTemperature.second));
        
        // 转换温度
        pType temperatureConverted{};
        switch (inputTemperature.second)
        {
        case 'c':
            temperatureConverted.first = ctok(inputTemperature.first);
            temperatureConverted.second = 'k';
            break;
        case 'k':
            temperatureConverted.first = ktoc(inputTemperature.first);
            temperatureConverted.second = 'c';
            break;
        default:
            error("未知温度单位");
        }

        cout << "转换温度: " << temperatureConverted.first << temperatureConverted.second << endl;
        keep_window_open();
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
    return 0;
}


