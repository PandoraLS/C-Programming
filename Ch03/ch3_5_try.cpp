/*
 * @Author: seenli 
 * @Date: 2020-10-03 15:27:23 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-03 16:06:06
 */

#include "std_lib_facilities.h"

int main() {
    cout << "����ظ����ʵĳ���, EOF or Ctrl-Z to exit\n";
    cout << "������һ�仰:";
    string previous;
    string current;
    unsigned wordCount{};   // ��ʼ��Ϊ0, ͳ�ƾ����й����ٵ���
    while(cin >> current){
        ++wordCount;
        
        // ��current�ַ����е�ÿ���ַ�, c��һ������, ��ֵ��佫��ı�current���ַ���ֵ
        // auto�ñ�����ͨ����ʼֵ���������������
        for(auto& c: current){  
            // ������ת��Ϊunsigned char
            c = static_cast<unsigned char>(tolower(c));
        }
        if(previous == current){
            cout << "�ظ����ʣ�" << current << endl;
        } else{
            previous = current;
        }
    }
    cout << "Total words: " << wordCount << endl;
    keep_window_open();
    
    return 0;
 }