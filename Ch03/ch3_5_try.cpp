/*
 * @Author: seenli 
 * @Date: 2020-10-03 15:27:23 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-03 16:06:06
 */

#include "std_lib_facilities.h"

int main() {
    cout << "检测重复单词的程序, EOF or Ctrl-Z to exit\n";
    cout << "请输入一句话:";
    string previous;
    string current;
    unsigned wordCount{};   // 初始化为0, 统计句子中共多少单词
    while(cin >> current){
        ++wordCount;
        
        // 对current字符串中的每个字符, c是一个引用, 赋值语句将会改变current中字符的值
        // auto让编译器通过初始值来推算变量的类型
        for(auto& c: current){  
            // 将类型转换为unsigned char
            c = static_cast<unsigned char>(tolower(c));
        }
        if(previous == current){
            cout << "重复单词：" << current << endl;
        } else{
            previous = current;
        }
    }
    cout << "Total words: " << wordCount << endl;
    keep_window_open();
    
    return 0;
 }