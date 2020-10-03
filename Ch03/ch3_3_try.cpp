/*
 * @Author: seenli 
 * @Date: 2020-10-03 12:40:08 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-03 13:16:31
 */

/*
Section 3.3 try this exercise
Get the ��name and age�� example to run.
Then, modify it to write out the age in months:
read the input in years and multiply (using the * operator) by 12.
Read the age into a double to allow for children who can be very
proud of being five and a half years old rather than just five.
*/

#include "std_lib_facilities.h"

int main(){
    constexpr double monthsInYear{12.0}; // constexpr ���εĳ������ʽ�ڱ����ڼ�Ϳ��Լ������
    constexpr double minAge{0.0};
    constexpr double maxAge{130.0};
    
    cout << "������first name: ";
    string first_name;
    cin >> first_name;

    cout << "������ age: ";
    double age{minAge};
    while (cin >> age){
        if (age < minAge || age > maxAge) {
            cout << "����Ƿ�, �����ԣ�" << endl;
        } else {
            break;
        }
    }
    cout << "Hello, " << first_name << " you are " << age * monthsInYear << " months old" << endl;
    keep_window_open();
    return 0;
}
