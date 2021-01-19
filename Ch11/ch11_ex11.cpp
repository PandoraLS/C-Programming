/*
 * @Author: seenli
 * @Date: 2021-01-19 15:45:54
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 16:22:10
 * @FilePath: \Ch11\ch11_ex11.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


// Chapter 11, exercise 11: write a function to return a vector of whitespace-
// separated substrings of the argument string where whitespace is regular
// whitespace plus the characters of a string argument


#include "../includes/std_lib_facilities.h"

// ���ؿհ׷��ָ�����string of s
vector<string> split(const string& s) {
    istringstream is(s);
    string ss;
    vector<string> substrings;
    while (is >> ss) substrings.push_back(ss);
    return substrings;
}

// ����ַ���s�Ƿ�����ַ�ch
bool contains(const string& s, char ch) {
    for (int i{}; i < s.size(); ++i) {
        if (s[i] == ch) {
            return true;
        }
    }
    return false;
}

// ���ؿհ׷��ֿ������ַ���of s, ���пհ׷�����ԭʼ�հ׷��Լ�������"w"�е��Զ���հ׷�
vector<string> split(const string& s, const string& w) {
    string ss = s;
    for (int i{}; i < ss.size(); ++i) {
        for (int j{}; j < w.size(); ++j) {
            if (contains(w, ss[i])) ss[i] = ' ';
        }
    }
    return split(ss);
}

// ��ӡstrings��vector
void print_vec(const vector<string> vs) {
    for (int i{}; i < vs.size(); ++i) {
        cout << vs[i] << endl;
    }
}

int main()
try {
    cout << "�������Զ���'�հ׷�', �Կհ׷�����\n";
    string w;
    getline(cin, w);
    cout << "����һЩ����, \n";
    string s;
    while (getline(cin, s)) {
        vector<string> substrings = split(s, w);
        cout << "\nYou entered: \n";
        print_vec(substrings);
        cout << "\nAnother try, �������ֹ��ctrl+z����\n";
    }
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
