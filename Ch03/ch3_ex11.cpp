/*
 * @Author: seenli 
 * @Date: 2020-10-04 16:36:30 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-04 16:53:52
 */

#include "std_lib_facilities.h"

int getInput(){
    int val{};
    if(!(cin >> val)){
        simple_error("Invalid integer value. \n");
    }
    return val;
}

int main() {
    cout << "输入一些金额数目：\n";
    int penny{}, nickel{}, dime{}, quarter{}, half_dollar{}, dollar{};
    cout << "Enter number of pennies: ";
	penny = getInput();
	cout << "Enter number of nickels: ";
	nickel = getInput();
	cout << "Enter number of dimes: ";
	dime = getInput();
	cout << "Enter number of quarters: ";
	quarter = getInput();
	cout << "Enter number of half dollars: ";
	half_dollar = getInput();
	cout << "Enter number of dollar coins: ";
    dollar = getInput();

    string denomination;        // 面额
    if (penny > 0) {
        denomination = (penny == 1 ? "penny" : "pennies");
        cout << "you have " << penny << " " << denomination << endl;
    }

    if (nickel > 0) {
        denomination = (nickel == 1 ? "nickel" : "nickels");
        cout << "you have " << nickel << " " << denomination << endl;
    }

    if (dime > 0) {
        denomination = (dime == 1 ? "dime" : "dimes");
        cout << "you have " << dime << " " << denomination << endl; 
    }

    if (quarter > 0) {
        denomination = (quarter == 1 ? "quarter" : "quarters");
        cout << "you have" << quarter << " " << denomination << endl;
    }

    if (half_dollar > 0) {
        denomination = (half_dollar == 1 ? "half dollar" : "half dollars");
        cout << "you have" << half_dollar << " " << denomination << endl;
    }

    if (dollar > 0) {
        denomination = (dollar == 1 ? "dollar" : "dollars");
        cout << "you have" << dollar << " " << denomination << endl;
    }

    int total{};
    total = penny + nickel * 5 + dime * 10 + quarter * 25 + half_dollar * 50 + dollar * 100;
    cout << "your total is $" << fixed  << setprecision(3) << total / 100.0 << endl;
    keep_window_open();
    return 0;
}