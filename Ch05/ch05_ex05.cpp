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

// ������ת��Ϊ��ʽ
double ctok(double c) {
    if (c < -273.15) {
        // �׳�error
        error("�����Ե��ھ������!");
    }
    constexpr double conversion_constant{273.15};
    double celsiusToKelvin{c + conversion_constant};
    return celsiusToKelvin;
}

// ����ʽת��Ϊ����
double ktoc(double k) {
    if (k < 0) {
        // �׳�error
        error("�����Ե��ھ������!");
    }
    constexpr double conversion_constant{273.15};
    double kelvinToCelsius{k - conversion_constant};
    return kelvinToCelsius;
}

int main() {
    using pType = pair<double, char>;
    pType inputTemperature{};

    try {
        cout << "����temperature �� ��λ(c = Celsius, k = Kelvin)" << endl;;

        // ��ȡ�¶�
        if (!(cin >> inputTemperature.first)) {
            error("����Ƿ�����!");
        }

        // ��ȡ��λ
        cin >> inputTemperature.second;
        inputTemperature.second = narrow_cast<char, int>(tolower(inputTemperature.second));
        
        // ת���¶�
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
            error("δ֪�¶ȵ�λ");
        }

        cout << "ת���¶�: " << temperatureConverted.first << temperatureConverted.second << endl;
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


