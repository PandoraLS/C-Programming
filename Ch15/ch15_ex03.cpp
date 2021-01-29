/*
 * @Author: seenli
 * @Date: 2021-01-28 15:01:30
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-28 15:25:31
 * @FilePath: \Ch15\ch15_ex03.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 20, Exercise 03: look at the palindrome example (13.7); redo the
// Jack-and-Jill example using that variety of techniques.


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

// 返回指向vector v中具有最大值的指针
double* high_vec(vector<double>& v) {
    if (v.size() == 0) return 0;
    double* highest = &v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > *highest) highest = &v[i];
    }
    return highest;
}

// 返回一个指向数组arg(有n个元素)中最大值的指针
double* high_arr(double arg[], int n) {
    if (n == 0) return 0;
    double* highest = &arg[0];
    for (int i = 0; i < n; ++i) {
        if (arg[i] > *highest) highest = &arg[i];
    }
    return highest;
}

// 返回一个指针，指向[first,last)中的最高值
double* high_ptr(double* first, double* last) {
    double h = -1;
    double* high;
    for (double* p = first; p != last; ++p) {
        if (h < *p) {
            high = p;
            h = *p;
        }
    }
    return high;
}

int main()
try {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();

    // use vectors: turn jack_data into vector
    vector<double> jack_vec;
    for (int i = 0; i<jack_count; ++i)
        jack_vec.push_back(jack_data[i]);
    double* jack_high_vec = high_vec(jack_vec);
    double* jill_high_vec = high_vec(*jill_data);
    cout << "Vector: Jill's max: " << *jill_high_vec <<
        "; Jack's max: " << *jack_high_vec << "\n";

    // use arrays: turn jill_data into array
    double* jill_arr = new double[(*jill_data).size()];
    for (int i = 0; i<(*jill_data).size(); ++i)
        jill_arr[i] = (*jill_data)[i];
    double* jack_high_arr = high_arr(jack_data,jack_count);
    double* jill_high_arr = high_arr(jill_arr,(*jill_data).size());
    cout << "Array: Jill's max: " << *jill_high_arr <<
        "; Jack's max: " << *jack_high_arr << "\n";
    delete[] jill_arr;

    // use pointers
    double* jack_high_ptr = high_ptr(jack_data,jack_data+jack_count);
    vector<double>& v = *jill_data;
    double* jill_high_ptr = high_ptr(&v[0],&v[0]+v.size());

    cout << "Pointer: Jill's max: " << *jill_high_ptr <<
        "; Jack's max: " << *jack_high_ptr << "\n";

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
