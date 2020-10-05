/*
 * @Author: seenli 
 * @Date: 2020-10-05 14:59:29 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-05 15:16:06
 */


#include "std_lib_facilities.h"

int main() {
    constexpr double yen_to_dollar {113.21};
    constexpr double euro_to_dollar {0.88};
    constexpr double pound_to_dollar {0.77};

    double amount {1.0};
    string currency;
    cout << "请输入一个数额并紧跟着货币, 以转换为dollar: \n";
    cout << "yen, euro, or pound \n";

    if (!(cin >> amount)) {
        simple_error("Incorrect amountry entry");
    }

    cin >> currency;
    if (currency == "yen") {
        cout << amount << " " << currency << " == $" << 1 / yen_to_dollar * amount << endl;
    } else if (currency == "euro") {
        cout << amount << " " << currency << " == $" << 1 / euro_to_dollar * amount << endl;
    } else if (currency == "pound") {
        cout << amount << " " << currency << " == $" << 1 / pound_to_dollar * amount << endl;
    } else {
        cout << "未知货币 called " << currency << endl;
    }

    keep_window_open();
    return 0;
}