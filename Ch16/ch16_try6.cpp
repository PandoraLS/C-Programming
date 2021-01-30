/*
 * @Author: seenli
 * @Date: 2021-01-30 14:41:01
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-30 15:13:01
 * @FilePath: \Ch16\ch16_try6.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 16, Try This 6: get Dow Jones map example to work

#include "../includes/std_lib_facilities.h"
#include <map>
#include <numeric>

double weighted_value(const pair<string, double>& a, const pair<string, double>& b) {
    return a.second * b.second;
}



int main()
try {
    map<string, double> dow_price;
    // Dow Jones Industrial index (symbol price);
    // for up-to-date quotes see www.djindexes.com
    dow_price["MMM"] = 160.60;
    dow_price["AXP"] = 90.44;
    dow_price["T"] = 32.67;
    dow_price["BA"] = 125.06;
    dow_price["CAT"] = 89.75;
    dow_price["CVX"] = 106.02;
    
    map<string, double> dow_weight;         // Dow (symbol, weight)
    dow_weight.insert(make_pair("MMM",5.94));
    dow_weight.insert(make_pair("AXP",3.35));
    dow_weight.insert(make_pair("T",1.21));
    dow_weight.insert(make_pair("BA",4.63));
    dow_weight.insert(make_pair("CAT",3.32));
    dow_weight.insert(make_pair("CVX",3.92));

    map<string, string> dow_name;           // Dow (symbol, name)
    dow_name["MMM"] = "3M Co.";
    dow_name["AXP"] = "American Express";
    dow_name["T"] = "AT&T";
    dow_name["BA"] = "Boeing";
    dow_name["CAT"] = "Caterpillar";
    dow_name["CVX"] = "Chevron";

    typedef map<string, double>::const_iterator Dow_iterator;

    // 道琼斯指数中每家公司的账面价格
    for (Dow_iterator p = dow_price.begin(); p != dow_price.end(); ++p) {
        const string& symbol = p->first;                // 股票符号
        cout << symbol << '\t' << p->second << '\t' << dow_name[symbol] << '\n';
    }

    double dji_index = inner_product(dow_price.begin(), dow_price.end(),        // 所有的公司
                                    dow_weight.begin(),                         // 各公司权重
                                    0.0,                                        // 初始值
                                    plus<double>(),                             // add
                                    weighted_value);                            // 
    
    cout << "DJI index is " << dji_index << "\n";                       
    
    system("pause");
    return 0;
}
catch (Range_error& re) {
    cerr << "bad index: " << re.index << "\n";
    keep_window_open();
	return 1;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
	return 2;
}