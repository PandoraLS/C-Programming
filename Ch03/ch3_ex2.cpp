/*
 * @Author: seenli 
 * @Date: 2020-10-03 20:27:21 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-03 20:44:30
 */

#include "std_lib_facilities.h"

int main(){
    cout << "����Ӣ�EOF �� Ctrl-Z �˳� \n";
    double miles {};
    if (cin >> miles){
        cout << miles << " Ӣ�� = " << miles * 1.609 << " ����" << endl;
    } else {
        simple_error("Invalid entry");  // ����ֱ�Ӿ��˳���
    }
    
    keep_window_open();
    return 0;
}