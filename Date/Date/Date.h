#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month);
	void Print();

	Date(int year = 1900, int month = 1, int day = 1);
	// �������캯��
	// d2(d1)
	//Date(const Date& d);

	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	//Date& operator=(const Date& d);

	// ��������
	//~Date();

	// d1 += 10
	Date& operator+=(int day);
	// d1 + 10
	Date operator+(int day);

	// d1 -= 10
	Date& operator-=(int day);
	// d1 - 10
	Date operator-(int day);

	// ++d1
	// d1.operator++(&d1);
	Date& operator++();

	// Ϊ�˸�ǰ��++�����Ȳ����ѣ����������++��
	// ����һ������������βΣ����������ʹ��,������Ϊ�˸�ǰ��++���ɺ����������ֿ���
	// d1++
	// d1.operator++(&d1, 0);
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	// ==���������
	bool operator==(const Date& d);

	// !=���������
	bool operator != (const Date& d);

	// >���������
	bool operator>(const Date& d);

	// <���������
	bool operator < (const Date& d);

	// >=���������
	bool operator >= (const Date& d);

	// <=���������
	bool operator <= (const Date& d);

	// d1 - d2
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};