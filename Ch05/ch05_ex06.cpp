/*
 * @Author: seenli 
 * @Date: 2020-12-04 22:31:01 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-04 23:02:40
 */

/*
sect 5 exercise 6
Celsius to Fahrenheit converter
Fahrenheit to Celsius converter
f = c * ( 9.0 / 5.0) + 32.0
c = (f - 32.0) / (9.0 / 5.0)
*/

#include "std_lib_facilities.h"

// ������ת��Ϊ����
double ctof(double c) {
    if (c < -273.15) {
        error("���ܵ��ھ������!");
    }
    double celsiusToFahrenheit{9.0 / 5.0 * c + 32.0};
    return celsiusToFahrenheit;
}

// ������ת��Ϊ����
double ftoc(double f) {
    double fahrenheitToCelsius{5.0 / 9.0 * (f - 32.0)};
    if (fahrenheitToCelsius < -273.15) {
        error("���ܵ��ھ������!");
    }
    return fahrenheitToCelsius;
}

int main()
try {
    using pType = pair<double, char>;
    pType inputTemperature{};

    cout << "�������¶Ⱥ͵�λ (c = Celsius, f = Fahrenheit)" << endl;
    
    // ��ȡ�¶�
    if (!(cin >> inputTemperature.first)) {
        error("������¶�Ӧ��Ϊ����!");
    }

    // ��ȡ��λ
    cin >> inputTemperature.second;
    inputTemperature.second = narrow_cast<char, int>(tolower(inputTemperature.second));

    // �¶�ת��
    pType temperatureConverted{};
    switch (inputTemperature.second)
    {
    case 'c':
        temperatureConverted.first = ctof(inputTemperature.first);
        temperatureConverted.second = 'f';
        break;
    case 'f':
        temperatureConverted.first = ftoc(inputTemperature.first);
        temperatureConverted.second = 'c';
        break;
    default:
        error("δ֪���͵ĵ�λ!");
    }

    cout << "converted temperature is " << temperatureConverted.first << temperatureConverted.second << endl;

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

