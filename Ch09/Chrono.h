#ifndef CHRONO_H
#define CHRONO_H

#include "std_lib_facilities.h"

namespace Chrono {
	enum class Month {
		Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
	};
	enum class Day {
		Su, Mo, Tu, We, Th, Fr, Sa
	};

	class Date {
	public:
		class Invalid{};						// 作为异常抛出
		Date(int y, Month m, int d);			// 检查日期合法性并初始化
		Date();									// 默认构造函数
		// 默认拷贝操作是可用的

		// 不改变对象的操作：
		int year() const {return y;};
		Month month() const {return m;};
		int day() const {return d;};

		// 改变对象的操作：
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		
	private:
		int y;			// 年份
		Month m;
		int d;			// Day
	};

	const Date& default_date();
	Day what_dow(Date d);
	int days_in_month(Month m, int y);
	int days_in_year(int y);
	bool is_date(int y, Month m, int d);		// true for valid date
	bool leapyear(int y);						// true if y is a leap year
	Date next_workday(const Date& d);
	int week_of_year(const Date& d);
	long int days_sing_0(const Date& d);
	bool operator == (const Date& a, const Date& b);
	bool operator != (const Date& a, const Date& b);
	int operator - (Date a, Date b);
	ostream& operator << (ostream& os, Date& a);
	istream& operator >> (istream& is, Date& a);
}
#endif

