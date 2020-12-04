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

// ������ת��Ϊ��ʽ
double ctok(double c) {
    // �����������¶ȵ���-273.15ʱ���׳�����
    if (c < -273.15) {
        error("can not be below absolute zero !\n");
    }
    constexpr double conversion_constant{273.15};
    double celsiusToKelvin{c + conversion_constant};
    return celsiusToKelvin;
}

int main()
try{
    cout << "���������¶ȣ�ת��Ϊ��ʽ�¶�" << endl;
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

