/*
 * @Author: seenli 
 * @Date: 2020-10-03 16:41:51 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-03 20:26:36
 */

#include "std_lib_facilities.h"

int main(){
    constexpr unsigned minAge{0};
    constexpr unsigned maxAge{130};
    
    cout << "Enter the name of the person you want to write to: \n";
    string first_name;
    cin >> first_name;
    cout << "Dear " << first_name << ",\n";
    cout << "\tHow are you? I am fine. I miss you.\n";
    
    cout << "Enter a friends name:\n";
    cin >> first_name;
    cout << "Have you seen " << first_name << " lately?\n";
    cout << "What is your friends gender?" << "(Enter m for male and f for female) \n";
    char gender {}; // 默认初始化为0
    while (cin >> gender){
        // 进行类型转换的原因是，tolower()的返回值是int型的，并给出了转换警告
        gender = static_cast<unsigned char>(tolower(gender));
        if(gender == 'm' || gender == 'f'){
            cout << "If you see " << first_name
                << " ask " << ((gender == 'm') ? "him" : "her") << " to call me.\n";
            break;
        }
        cout << "未识别 gender" << gender << ", please reenter: ";
    }

    cout << "How old are you?\n";
    int age{};      // 默认初始化为0
    // 检查age是否合法
    if(cin >> age && age > minAge && age < maxAge){
        cout << "I hear you just had a birthday and you are " << age << " years old. \n";
        if(age < 12){
            cout << "Next year you will be " << age + 1 << ".\n";
        } else if(age == 17) {
            cout << "Next year you will be able to vote. \n";
        } else if(age > 70){
            cout << "I hope you are enjoying retirement. \n";
        }
        cout << "Yours sincerely, \n\n\nJ\n";
    } else {
        simple_error("you're kidding!");
    }
    
    keep_window_open();
    return 0;
}