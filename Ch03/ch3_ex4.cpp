/*
 * @Author: seenli 
 * @Date: 2020-10-03 20:44:57 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-03 21:18:08
 */

#include "std_lib_facilities.h"

int main()
{
    cout << "������������";
    int val1{}, val2{};

    // �������ֵ
    int minValue{}, maxValue{}, sum{}, difference{}, product{}, quotient{};
    if (cin >> val1 >> val2)
    {
        if (val1 > val2)
        {
            maxValue = val1;
            minValue = val2;
        }
        else
        {
            maxValue = val2;
            minValue = val1;
        }

        sum = val1 + val2;
        difference = val1 - val2;
        product = val1 * val2;
        if (val2 != 0)
        {
            quotient = val1 / val2;
        }
        else
        {
            simple_error("division by 0");
        }

        cout << "���ֵ: " << maxValue << "\n"
            << "��Сֵ��" << minValue << "\n"
            << "��: " << sum << "\n"
            << "��: " << difference << "\n"
            << "��: " << product << "\n"
            << "��: " << quotient << endl;
    } else {
        simple_error("Invalid input");
    }

    keep_window_open();
    return 0;
}