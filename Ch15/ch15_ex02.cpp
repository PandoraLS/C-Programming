/*
 * @Author: seenli
 * @Date: 2021-01-28 14:32:37
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-28 15:01:08
 * @FilePath: \Ch15\ch15_ex02.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 15, Exercise 02: get the Jack-and-Jill example from 15.1.2 to work;
// use input from a couple of small files to test it


#include "../includes/std_lib_facilities.h"

double* get_from_jack(int* count) {
    string ifname = "ex02_in1.txt";
    ifstream ifs(ifname.c_str());
    if (!ifs) error("cannot open input file ", ifname);

    // 首先优雅地将输入读入向量
    vector<double> v;
    double d;
    while (ifs >> d) v.push_back(d);

    *count  = v.size();
    double* data = new double[*count];
    for (int i = 0; i < v.size(); ++i) {
        data[i] = v[i];
    }
    return data;
}

vector<double>* get_from_jill() {
    string ifname = "ex02_in2.txt";
    ifstream ifs(ifname.c_str());
    if (!ifs) error("cannot open input file ", ifname);

    vector<double>* v = new vector<double>;
    double d;
    while (ifs >> d) (*v).push_back(d);

    return v;
}

// 返回一个指针，指向[first,last]中有最高值的元素
double* high(double* first, double* last) {
    double h = -1;
    double* high;
    for (double* p = first; p != last; ++p) {
        if (h < *p) {high = p; h = *p;}
    }
    return high;
}

int main()
try {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data, jack_data + jack_count);
    vector<double>& v = *jill_data;
    double* jill_high = high(&v[0], &v[0] + v.size());

    cout << "Jill's max: " << *jill_high << "; Jack's max: " << *jack_high << endl;

    delete[] jack_data;
    delete jill_data;

    system("pause");
    return 0;
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
