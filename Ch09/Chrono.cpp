/*
 * @Author: seenli
 * @Date: 2020-09-28 14:30:55
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-06 18:47:14
 * @FilePath: \Ch09\Chrono.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#include "Chrono.h"

namespace Chrono {
	Date::Date(int y, Month m, int d)
		: m_year{y}, m_month{m}, m_day{d}
	{
		if(!is_date(y, m, d)) throw std::runtime_error("Invalid Date!");
		days_from_zero();
	}

	Date default_date() {
		static const Date dd{2001, Month::jan, 1};				// ��21���Ϳ�ʼ
		return dd;
	}

	Date::Date()
		: m_year{default_date().get_year()},
		  m_month{default_date().get_month()},
		  m_day{default_date().get_day()}
	{
		days_from_zero();
	}

	// �����
	void Date::add_day(const int n) {
		if (n < 0) throw std::runtime_error("cannot add negative days!");
		if (n > 0) {
			for (int i{1}; i <= n; ++i) {
				int t = m_day + 1;
				switch (m_month) {
					case Chrono::Month::feb:
						if (t <= (leap_year(m_year) ? 29 : 28)) {
							m_day = t;
						} else {
							m_month = Month::mar;
							m_day = 1;
						}
						break;
					case Chrono::Month::dec:
						if (t <= 31) {
							m_day = t;
						} else {
							m_month = Month::jan;
							m_day = 1;
							++m_year;
						}
						break;
					default:
						if (t <= month_day.at((int)m_month - 1)) {
							m_day = t;
						} else {
							m_month = Month((int)m_month + 1);
							m_day = 1;
						}
						break;
				}
			}
			days_from_zero();
		}
	}

	// add month will clamp to last day to the n month
	// ����·�, ����n���µ����һ��
	void Date::add_month(const int n) {
		if (n < 0) throw std::runtime_error("cannot add negative months!");
		if (n > 0) {
			int months = n;
			int years{};				// ��¼�ص�����ݣ����������·����������
			if (n >= 12 && n != 0) {
				int add_months{n / 12};		// ����12 �ó�ʣ�µ����
				years = add_months;			
				months -= add_months * 12;	// ����֮���������·�
			}
			
			// �����ǰ��+����ʣ�µ��·� ��Ȼ����1��
			if ((int)m_month + months > 12) {
				m_month = Month((int)m_month + months - 12);
				years += 1;
			} else {
				m_month = Month((int)m_month + months);
			}

			// ���ǰ�����Ǹ����죬��������µ����һ��
			if(m_day > month_day.at((int)m_month - 1)) {
				if(m_month == Month::feb && !leap_year(m_year)) {
					// �����2����m_year��ƽ��
					m_day = 29;
				}
				m_day = month_day.at((int)m_month - 1);
			}
			days_from_zero();
			add_year(years);
		}
	}

	// ������
	void Date::add_year(const int n) {
		if (n < 0) throw std::runtime_error("cannot add negative years!");
		if (n > 0) {
			// ע������
			if (m_month == Month::feb && m_day == 29 && !leap_year(m_year + n)) {
				// �����Ӧ����2��29�յ�ƽ��,���ʱ��3��1��ƽ��
				m_month = Month::mar;
				m_day = 1;
			}
			m_year += n;
			days_from_zero();
		}
	}

	void Date::days_from_zero() {
		std::tm now{};
		now.tm_mday = m_day;
		now.tm_mon = (int)m_month - 1;
		now.tm_year = m_year - 1900;

		std::time_t today = std::mktime(&now);
		auto n = std::chrono::system_clock::from_time_t(day_zero);
		auto t = std::chrono::system_clock::from_time_t(today);
		m_days = std::chrono::duration_cast<std::chrono::hours>(t - n).count() / 24;
	}

	// helper functions

	bool is_date(int y, Month m, int d) {
		// ����year��valid
		if (d <= 0) return false;					// day����Ϊ��
		if (Month::dec < m || m < Month::jan) return false;

		int days_in_month{31};						// �·������31��
		switch (m) {
			case Month::feb:
				days_in_month = (leap_year(y)) ? 29 : 28;
				break;
			case Month::apr:
			case Month::jun:
			case Month::sep:
			case Month::nov:
				days_in_month = 30;					// С����30��
				break;
		}

		if (days_in_month < d) return false;
		return true;
	}

	// �����ж�, ֻҪ��������֮һ��������
	// 1: �ܱ�400����
	// 2���ܱ���4���������ܱ�100����
	bool leap_year(int y) {
		if (!(y % 400)) {
			return true;
		}

		if (y % 100 && !(y % 4)) {
			return true;
		}
		return false;
	}

	bool operator==(const Date& a, const Date& b) {
		return a.m_days == b.m_days;
	}

	bool operator!=(const Date& a, const Date& b) {
		return !(a == b);
	}

	bool operator>(const Date& a, const Date& b) {
		return a.m_days > b.m_days;
	}

	bool operator<(const Date& a, const Date& b) {
		return a.m_days < b.m_days;
	}

	bool operator>=(const Date& a, const Date& b) {
		return a > b || a == b;
	}

	bool operator<=(const Date& a, const Date& b) {
		return a < b || a == b;
	}

	std::ostream& operator<<(std::ostream& os, const Date& d) {
		return os << '(' << d.m_year << ',' << (int)d.m_month << ',' << d.m_day << ')';
	}

	std::istream& operator>>(std::istream& is, Date& dd) {
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		// ����ʽ����
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
			is.clear(std::ios_base::failbit);						// ����fail bit
			return is;
		}

		dd.m_year = y;
		dd.m_month = Month(m);
		dd.m_day = d;
		return is;
	}

	Day day_of_week(const Date& d) {
		// good for �κθ��������
		int y{d.get_year()};
		int m{static_cast<int>(d.get_month())};
		static const std::array<int, 12> t{0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};		// 	����ʲô
		
		if (d.get_month() < Month::mar) {
			--y;
		}
		return Day((y + y / 4 - y / 100 + y / 400 + t.at(m - 1) + d.get_day()) % 7);
	}

	Date next_sunday(const Date& d) {
		Date date_now{d};
		Day day_now{day_of_week(d)};
		date_now.add_day(7 - (int)day_now);
		return date_now;
	}

	Date next_weekday(const Date& d) {
		Date date_now{d};
		date_now.add_day(1);
		return date_now;
	}

	Date next_workday(const Date& d) {
		Date nwd{d};
		// ����Ƿ�����ĩ
		auto day{day_of_week(d)};
		switch (day) {
			case Day::fri:
				nwd.add_day(3);
				break;
			case Day::sat:
				nwd.add_day(2);
				break;
			default:
				nwd.add_day(1);
				break;
		}
		return nwd;
	}

	int week_of_year(const Date& d) {
		Date date{d.get_year(), Month::jan, 1};
		int week_number{};
		while (d >= date) {
			date = next_sunday(date);				// ��ȡ��һ��������
			if (date.get_year() == d.get_year()) {	// �����һ�������ղ����ı����, ��week��1
				++week_number;
			} else if (date.get_day() != 1) {		// �ٶ�ÿ�ܵĵ�һ��������(ϰ��11)
				week_number = 1;
			}
		}
		return week_number;
	}
}	// Chrono
