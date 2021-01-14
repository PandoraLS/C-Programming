/*
 * @Author: seenli
 * @Date: 2021-01-13 15:59:45
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-14 15:15:36
 * @FilePath: \Ch10\ch10_ex05.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Chapter 10, exercise 05 
    write the print_year() function from 10.11.2.
*/

#include "../includes/std_lib_facilities.h"

const int not_a_reading = -7777;            // 比最小值还小
const int not_a_month = -1;

struct Day {
    vector<double> hour;
    Day();                                  // 初始化hour为not a reading
};

Day::Day(): hour(24) {
    for (int i{}; i < hour.size(); ++i) {
        hour[i] = not_a_reading;
    }
}

struct Month {                              // 一个月的温度reading
    int month;                              // [0:12) January is 0
    vector<Day> day;                        // [1:31] 一月中的天数
    Month(): month(not_a_month), day(32) {}
};

struct Year {                               // 一年的temperature readings 
    int year;                               // 公元后为正数
    vector<Month> month;                    // [0:12) January is 0
    Year(): month(12) {}                    // 每年12月
};

// 记录日期、小时、温度
struct Reading {
    int day;
    int hour;
    double temperature;
};

int month_to_int(string s);
bool is_valid(const Reading& r);
void end_of_loop(istream& ist, char term, const string& message);

istream& operator>>(istream& is, Reading& r) {
    char ch1;
    if (is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')') error("bad reading");
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

istream& operator>>(istream& is, Month& m) {
    char ch = 0;
    if (is >> ch && ch != '{') {
        is.unget();
        is.clear(ios_base::failbit);                    // failed to read a Month
        return is;
    }

    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month") error("bad start of month");
    m.month = month_to_int(mm);

    Reading r;
    int no_of_duplicate_readings = 0;
    int no_invalid_readings = 0;

    while (is >> r) {
        if (is_valid(r)) {
            if (m.day[r.day].hour[r.hour] != not_a_reading) {
                ++no_of_duplicate_readings;
            }
            m.day[r.day].hour[r.hour] = r.temperature;
        } else {
            ++no_invalid_readings;
        }
    }

    end_of_loop(is, '}', "bad end of month");
    return is;
}

// 温度的上下限
const int temperature_min = -200;
const int temperature_max = 200;

// 简单测试
bool is_valid(const Reading& r) {
    if (r.day < 1 || 31 < r.day) return false;
    if (r.hour < 0 || 23 < r.hour) return false;
    if (r.temperature < temperature_min || r.temperature > temperature_max) return false;
    return true;
}

// read a year from is into y
// format: { year 1972 ... }
istream& operator>>(istream& is, Year& y) {
    char ch;
    is >> ch;
    if (ch != '{') {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }

    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != "year") error("bad start of year");
    y.year = yy;

    while (true) {
        Month m;            // 每次都得到一个干净的m
        if (!(is >> m)) break;
        y.month[m.month] = m;
    }

    end_of_loop(is, '}', "bad end of year");
    return is;
}

void end_of_loop(istream& ist, char term, const string& message) {
    if (ist.fail()) {                               // 使用term作为终止符或分隔符
        ist.clear();
        char ch;
        if (ist >> ch && ch == term) return ;       // all is fine
        error(message);
    }
}

vector<string> month_input_tbl;                     // month_input_tbl[0]=="jan"
void init_input_tbl(vector<string>& tbl) {
    // 初始化输入表示的向量
    tbl.push_back("jan");
    tbl.push_back("feb");
    tbl.push_back("mar");
    tbl.push_back("apr");
    tbl.push_back("may");
    tbl.push_back("jun");
    tbl.push_back("jul");
    tbl.push_back("aug");
    tbl.push_back("sep");
    tbl.push_back("oct");
    tbl.push_back("nov");
    tbl.push_back("dec");
}

// 是月份的名称吗?如果是，则返回索引[0:11]，否则为-1
int month_to_int(string s) {
    for (int i{}; i < 12; ++i) {
        if (month_input_tbl[i] == s) {
            return i;
        }
    }
    return -1;
}

vector<string> month_print_tbl;                         // month_print_tbl[0]=="January"

// 初始化输出表示的向量
void init_print_tbl(vector<string>& tbl) {
    tbl.push_back("January");
    tbl.push_back("February");
    tbl.push_back("March");
    tbl.push_back("April");
    tbl.push_back("May");
    tbl.push_back("June");
    tbl.push_back("July");
    tbl.push_back("August");
    tbl.push_back("September");
    tbl.push_back("October");
    tbl.push_back("November");
    tbl.push_back("December");
}

// months [0:12)
string int_to_month(int i) {
    if (i < 0 || 12 <= i) {
        error("bad month index");
    }
    return month_print_tbl[i];
}

// 检查是否有读数可用
void print_day(ostream& ost, const Day& d, int daynum) {
    bool is_empty = true;
    for (int i{}; i < 24; ++i) {
        if (d.hour[i] != not_a_reading) {
            is_empty = false;
            break;
        }
    }
    if (is_empty) return;               // day 中没有 readings
    ost << "\n        " << daynum;
    for (int i{}; i < 24; ++i) {
        if (d.hour[i] != not_a_reading) {
            ost << "\n            " << i << ":00 ~ " << d.hour[i] << " F";
        }
    }
}

// 输出月份
void print_month(ostream& ost, const Month& m) {
    if (m.month == not_a_month) return;
    ost << "\n    " << int_to_month(m.month);
    for (int i{1}; i < 32; ++i) {
        print_day(ost, m.day[i], i);
    }
}

void print_year(ostream& ost, const Year& y) {
    ost << y.year << ' ';
    for (int i = 0; i < 12; ++i) {
        print_month(ost, y.month[i]);
    }
}

int main()
try {
    // init month
    init_print_tbl(month_print_tbl);
    init_input_tbl(month_input_tbl);

    // 打开输入文件
    cout << "请输入 input file name\n";
    string name;
    cin >> name;
    ifstream ifs(name.c_str());
    if (!ifs) error("cannot open input file", name);
    ifs.exceptions(ifs.exceptions() | ios_base::badbit);       // throw for bad()

    // 打开输出文件
    cout << "请输入output file name\n";
    cin >> name;
    ofstream ofs(name.c_str());
    if (!ofs) error("cannot open output file", name);

    // 读取任意年
    vector<Year> ys;
    while (true) {
        Year y;                 // 每次都得到一个新初始化的年份
        if (!(ifs >> y)) break;
        ys.push_back(y);
    }
    cout << "read " << ys.size() << " years of readings\n";

    for (int i{}; i < ys.size(); ++i) {
        print_year(ofs, ys[i]);
        ofs << endl;
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
