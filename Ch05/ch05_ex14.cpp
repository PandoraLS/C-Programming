/*
 * @Author: seenli
 * @Date: 2020-12-14 13:41:46
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-14 14:44:52
 * @FilePath: \Ch05\ch05_ex14.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
Section 5 exercise 14
read (day-of-the-week,value) pairs, collect values for each day in a separate vector.
Ignore illegal days, but accept common synonyms.
escape by "q 5" for day value entry
Print sum and list of values for each day when there is no more input
count of and output rejected entries.
*/

#include "std_lib_facilities.h"

using pType = pair<vector<string>, vector<int>>;
using vType = vector<pType>;
using numType = pType::second_type::value_type;
numType add (numType si_a, numType si_b);

int main()
try {
    const string termination{"q"};

    vType weekdays{
        { {"sun","sunday"   }, {} },
        { {"mon","monday"   }, {} },
        { {"tue","tuesday"  }, {} },
        { {"wed","wednesday"}, {} },
        { {"thu","thursday" }, {} },
        { {"fri","friday"   }, {} },
        { {"sat","saturday" }, {} }
    };

    unsigned rejects{};     // 拒绝数量 星期和数值都输错的情况下 拒绝数会加2
    cout << "Enter days of the week (Mon or Monday) and a value. Enter q to exit. " << endl;
    while (true) {
        string day;
        cin >> day;
        for (auto& c: day) {
            c = narrow_cast<char>(tolower(c));
        }

        // 检查match的day
        auto validDay{weekdays.begin()};
        for (; validDay < weekdays.end(); ++validDay) {
            bool found{false};
            for (auto d : validDay->first) {
                if (d == day) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        // 么有发现day, 检查是否有终止符
        if (validDay == weekdays.end()) {
            if (day == termination) {
                // stop while loop
                break;
            }
            ++rejects;
        }

        // 查找对应的value
        else {
            numType value{};
            if (!(cin >> value)) {
                cin.clear();
                // 检查是否overflowed
                if (value > numeric_limits<numType>::max() || 
                    value < numeric_limits<numType>::min()) {
                    error("Entered number overflowed number type!");        
                }
                ++rejects;
            } else {
                validDay->second.push_back(value);
            }
        }
    }

    // 打印结果
    cout << endl;
    for (auto d : weekdays) {
        numType sum{};
        for (auto num : d.second) {
            sum = add(sum, num);
        }
        cout << left << setfill('.') << setw(20) << d.first.at(1) << " " << sum << endl;
    }
    cout << "\n\n" << left << setfill('.') << setw(20) << "rejects" << " " << rejects << endl;
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

// 四则运算的越界判断(有符号整型)
// https://wiki.sei.cmu.edu/confluence/display/c/INT32-C.+Ensure+that+operations+on+signed+integers+do+not+result+in+overflow
/**
 * @description: add function
 * @param {two number} 
 * @return {sum of two number}
 * @error: element overflow
 */
numType add(numType si_a, numType si_b) {
    numType sum{};
    if (((si_b > 0) && (si_a > (numeric_limits<numType>::max() - si_b))) ||
        ((si_b < 0) && (si_a < (numeric_limits<numType>::min() - si_b)))) {
            error("overflow error");
    } else {
        sum = si_a + si_b;
    }
    return sum;
}
