#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

int Date::GetMonthDay(int year, int month)
{
	static int daysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = daysArray[month];
	if (month == 2 &&
		((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		days = 29;
	}

	return days;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if (!(year >= 0 &&
		month > 0 && month < 13 &&
		day > 0 && day <= GetMonthDay(year, month)))
	{
		cout << "���ڷǷ�" << endl;
	}
}


Date& Date::operator += (int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}

	_day += day;
	// �����Ƿ�Ϸ�
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

// d1 + 10
Date Date::operator+(int day)
{
	// ��+=ʵ�֣��߼���������
	/*Date ret(*this);
	ret._day += day;
	while (ret._day > GetMonthDay(ret._year, ret._month))
	{
		ret._day -= GetMonthDay(ret._year, ret._month);
		ret._month++;
		if (ret._month == 13)
		{
			ret._year++;
			ret._month = 1;
		}
	}*/

	Date ret(*this);
	ret += day; // ret.operator+=(day);

	return ret;
}

Date& Date::operator-=(int day)
{
	return *this;
}

// ++d1  �ȼ���  d1 += 1
// d1.operator++(&d1);
// ����++֮���ֵ
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// d1++
// d1.operator++(&d1, 0);
// ����++֮ǰ��ֵ
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;

	return ret;
}

// ���븴��

// d1 == d2
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}

	return false;
}

// d1 != d2
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

// d1 >= d2
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}

// d1 < d2
bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

// d1 <= d2
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

// d1 - d2
// 1.д��
// 2.д��
// 3.д�ö����Ҹ����Ե�ά����ǿ
int Date::operator-(const Date& d)
{
	// ֮���������֮����������ò���
	Date max = *this, min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++n;
		++min;
	}

	return n * flag;
}