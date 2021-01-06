/*
 * @Author: seenli
 * @Date: 2020-09-28 14:15:56
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-06 15:14:10
 * @FilePath: \Ch09\Chrono.h
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#ifndef CHRONO_H
#define CHRONO_H

#include<iostream>
#include<array>
#include<chrono>
#include<ctime>

namespace Chrono {
	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	
	enum class Day {
		sun, mon, tue, wed, thu, fri, sat
	};

	const std::array<int, 12> month_day{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	class Date {
		public:
			class Invalid{};						// ��Ϊ�쳣�׳�
			Date();									// Ĭ�Ϲ��캯��
			Date(int y, Month m, int d);			// ������ںϷ��Բ���ʼ��
			// Ĭ�Ͽ��������ǿ��õ�

			// ���ı����Ĳ���
			int get_day() const {return m_day;}
			Month get_month() const {return m_month;}
			int get_year() const {return m_year;}
			
			// �ı����Ĳ���
			void add_day(int n);
			void add_month(int n);
			void add_year(int n);

			// ��������
			friend bool operator==(const Date& a, const Date& b);
			friend bool operator!=(const Date& a, const Date& b);
			friend bool operator>(const Date& a, const Date& b);
			friend bool operator<(const Date& a, const Date& b);
			friend bool operator>=(const Date& a, const Date& b);
			friend bool operator<=(const Date& a, const Date& b);
			friend std::ostream& operator<<(std::ostream& os, const Date& d);
			friend std::istream& operator>>(std::istream& is, Date& dd);
			
		private:
			long m_days;		// zero = jan 1, 1970
			int m_year;
			Month m_month;
			int m_day;			// Day

			void days_from_zero();

			// ��, ��, ʱ, ��(��1��ʼ), ��(��0��ʼ), ��
			std::tm dz{0, 0, 0, 1, 0, (1970 - 1900)};
			std::time_t day_zero = std::mktime(&dz);
	};

	//help functions
	bool is_date(int y, Month m, int d);		// true for valid date
	bool leap_year(int y);						// true if y is a leap year

	Day day_of_week(const Date& d);				// day of week of d
	Date next_sunday(const Date& d);			// next Sunday after d
	Date next_weekday(const Date& d);			// next weekday after d
	Date next_workday(const Date& d);			// return next work day (mon - fri)
	int week_of_year(const Date& d);			// return week number
}
#endif		// Chrono.h

