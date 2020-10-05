/*
 * @Author: seenli 
 * @Date: 2020-10-05 15:23:21 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-05 20:20:07
 */

#include "std_lib_facilities.h"

int main() {
    const vector<pair<const string, const double>> convertRate {
        {"yen", 113.21},
        {"euro", 0.88}, 
        {"pound", 0.77},
        {"danish krone", 6.55},
        {"yuan", 6.89}
    };

    cout << "请输入一个数额并紧跟着货币, 以转换为dollar: \n";

    // 将可选currency提示输出
    for (auto i{convertRate.begin()}; i < convertRate.end(); ++i) {
        if (i + 1 == convertRate.end()) {
            cout << "or " << i->first << endl;
        } else {
            cout << i->first << ", ";
        }
    }

    // get 货币金额
    double amount {1.0};
    if (!(cin >> amount)) {
        simple_error("entered amount unknown");
    }

    // get currency to convert
    string currency;

    cin >> ws;          // 删除之前的空白符 whitespace
    getline(cin, currency);     // 接收一个字符串, 可以接收空格并输出
    
    // 将输入的currency(字符串)转换为小写
    for (auto& c: currency) {
        c = static_cast<unsigned char>(tolower(c));
    }

    // find conversion type
    auto conversion{convertRate.size()};
    for (auto i{convertRate.begin()}; i < convertRate.end(); ++i) {
        if (i->first == currency) {
            conversion = i - convertRate.begin();
            break;
        }
    }

    // 获取conversion amount
    switch (conversion)
    {
    case 0:
        cout << amount << " " << currency << " == $" << 1 / convertRate.at(conversion).second * amount << endl;
        break;
    case 1:
        cout << amount << " " << currency << " == $" << 1 / convertRate.at(conversion).second * amount << endl;
        break;
    case 2:
        cout << amount << " " << currency << " == $" << 1 / convertRate.at(conversion).second * amount << endl;
        break;
    case 3:
        cout << amount << " " << currency << " == $" << 1 / convertRate.at(conversion).second * amount << endl;
        break;
    case 4:
        cout << amount << " " << currency << " == $" << 1 / convertRate.at(conversion).second * amount << endl;
        break;
    default:
        simple_error("unknown conversion type");
    }
    
    keep_window_open();
    return 0;
}
