/*
 * @Author: seenli 
 * @Date: 2020-11-17 10:29:17 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-17 15:34:00
 */

/**
 * 乒乓缓存:https://github.com/riskingh/Cache-ping-pong/blob/master/main.cpp
 * 在运行程序的时候遇到问题，因为windows系统安装的thread是win32，所以无法使用std::thread
 * 以下代码可以在线运行，https://wandbox.org/
 * 这个属于cache ping-pong 与 ping-pong buffer 还是有一定的差别  
*/


#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

const int INF = (int)1e9;

struct A {
    int x, y;
} a;

struct B {
    int x;
    int arr[10];
    int y;
} b;

void inc(int &x) {
    for (int i = 0; i < INF; ++i)
        ++x;
}

int main() {
    std::chrono::time_point<std::chrono::system_clock> tstart, tend;
    tstart = std::chrono::system_clock::now();

    std::thread tax(inc, std::ref(a.x));
    std::thread tay(inc, std::ref(a.y));

    tax.join();
    tay.join();

    tend = std::chrono::system_clock::now();

    long long diff = std::chrono::duration_cast<std::chrono::milliseconds>(tend - tstart).count();
    std::cout << "A: " << diff << std::endl;


    tstart = std::chrono::system_clock::now();

    std::thread tbx(inc, std::ref(b.x));
    std::thread tby(inc, std::ref(b.y));

    tbx.join();
    tby.join();

    tend = std::chrono::system_clock::now();

    diff = std::chrono::duration_cast<std::chrono::milliseconds>(tend - tstart).count();
    std::cout << "B: " << diff << std::endl;

    return 0;
}