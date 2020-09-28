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
		class Invalid{};						// ��Ϊ�쳣�׳�
		Date(int y, Month m, int d);			// ������ںϷ��Բ���ʼ��
		Date();									// Ĭ�Ϲ��캯��
		// Ĭ�Ͽ��������ǿ��õ�

		// ���ı����Ĳ�����
		int year() const {return y;};
		Month month() const {return m;};
		int day() const {return d;};

		// �ı����Ĳ�����
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		
	private:
		int y;			// ���
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

