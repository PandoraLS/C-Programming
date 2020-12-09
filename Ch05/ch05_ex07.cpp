/*
 * @Author: seenli 
 * @Date: 2020-12-09 18:57:56 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-12-09 19:47:12
 */

/*
section 5 exercise 7.
build upon section 4 exercise 18.
Write a program to solve quadratic equations(ax^2+bx+c=0).
x = (-b +/- sqrt(b^2-4ac))/2a
Check that b^2-4ac is not less than 0.
Write a function that print out the roots of a quadratic equation, given a,b,c.
If no real roots print out a message.
*/

#include "std_lib_facilities.h"

void quadratic(const double a, const double b, const double c){
    if (a == 0.0) {
        error("a = 0; so can not derive any roots. \n");
    } else if (c == 0.0) {
        cout << "x = 0" << endl;
        cout << "x = " << -1.0 * b / a << endl;
    } else {
        auto sq{b * b - 4.0 * a * c};
        if (sq >= 0.0) {
            cout << "x = " << (-1.0 * b + sqrt(sq)) / (2.0 * a) << endl;
            cout << "x = " << (-1.0 * b - sqrt(sq)) / (2.0 * a) << endl;
        } else {
            cout << "x = (" << -1.0 * b << " + i" << sqrt(fabs(sq)) << ")/" << (2.0 * a) << endl;
            cout << "x = (" << -1.0 * b << " - i" << sqrt(fabs(sq)) << ")/" << (2.0 * a) << endl;
        }
    }
}

int main()
try{
    cout << "输入a, b, c, 解一元二次方程：" << endl;
    double a{}, b{1.0}, c{};
    if (!(cin >> a >> b >> c)) {
        error("输入的是非数字.");
    }
    quadratic(a, b, c);
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}


