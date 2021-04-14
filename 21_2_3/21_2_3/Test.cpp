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

	Date(const Date& date)
	{
		this->_year = date._year;
		this->_month = date._month;
		this->_day = date._day;
	}

	bool operator==(Date d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator>(const Date d)
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

	/*Date& operator=(Date &d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		
		return *this;
	}*/

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

//bool operator==(Date d1, Date d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

int main()
{
	Date d1(2021, 2, 3);
	Date d2;
	Date d3;
	d3 = d2 = d1;
	d1.print();
	d2.print();
	d3.print();




	/*if (d1 == d2)
	{
		cout << "true" << endl;
	}

	if (d1 > d2)
	{
		cout << ">" << endl;
	}*/

	//if (d1.operator==(d2))

	/*operator == (d1, d2);*/

	return 0;
}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st1;
//	Stack st2(st1);
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	/*Date(const Date& date)
//	{
//		cout << "调用了拷贝构造函数 ";
//		this->_year = date._year;
//		this->_month = date._month;
//		this->_day = date._day;
//	}*/
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////void f(Date d)
////{
////
////}
//
//int main()
//{
//	Date d1(2021, 2, 3);
//	//f(d1);
//
//	d1.print();
//
//	Date d2(d1);
//	d2.print();
//
//	/*Date d3 = d1;
//	d3.print();*/
//
//	return 0;
//}