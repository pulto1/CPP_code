#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& date) // <<==== �������캯��
	{
		date.print();
		cout << "�����˿������캯�� ";
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}

	//�����÷�const��Աȡ����ַ��ֱ�Ӹ���const��Ա���ؿ�ָ�롣
	Date* operator&()
	{
		return nullptr;
	}

	const Date* operator&() const
	{
		return this;
	}

	void print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	const Date d1;
	cout << &d1 << endl;

	Date d2;
	cout << &d2 << endl;

	/*d1.print();*/
	return 0;
}