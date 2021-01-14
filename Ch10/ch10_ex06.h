/*
 * @Author: seenli
 * @Date: 2021-01-14 15:29:05
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-14 16:06:04
 * @FilePath: \Ch10\ch10_ex06.h
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#include "../includes/std_lib_facilities.h"

// type for Roman numerals
class Roman_int {
    public:
        Roman_int();
        Roman_int(int n);
        int as_int() const;
        void set_val(int v);
    private:
        int val;
};

ostream& operator<<(ostream& os, const Roman_int& r);
istream& operator>>(istream& is, Roman_int& r);
Roman_int operator+(const Roman_int& r1, const Roman_int& r2);
Roman_int operator-(const Roman_int& r1, const Roman_int& r2);
Roman_int operator-(const Roman_int& r);
Roman_int operator*(const Roman_int& r1, const Roman_int& r2);
Roman_int operator/(const Roman_int& r1, const Roman_int& r2);
Roman_int operator%(const Roman_int& r1, const Roman_int& r2);
bool operator==(const Roman_int& r1, const Roman_int& r2);
bool operator!=(const Roman_int& r1, const Roman_int& r2);
bool operator<(const Roman_int& r1, const Roman_int& r2);
bool operator>(const Roman_int& r1, const Roman_int& r2);
bool operator<=(const Roman_int& r1, const Roman_int& r2);
bool operator>=(const Roman_int& r1, const Roman_int& r2);

const char N = 'N';
const char I = 'I';
const char V = 'V';
const char X = 'X';
const char L = 'L';
const char C = 'C';
const char D = 'D';
const char M = 'M';

// ȷ��һ���ַ��Ƿ������Ϊ�������ֵ�һ����
bool is_valid_char(char ch);

// ���ص���ĸ�������ֵ�ֵ
int get_value(char ch);

// ������ĸ�Ƿ��ظ���̫Ƶ��
bool counter_illegal(int counter, char ch);

// �����ַ����Ƿ�Ϊ��Ч���������֣�������ֵ
int roman_int_to_int(const string& s);
