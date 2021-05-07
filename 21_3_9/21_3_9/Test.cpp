#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};

int main()
{
	Test* p1 = (Test*)malloc(sizeof(Test));
	Test* p2 = (Test*)malloc(sizeof(Test) * 3);

	Test* p3 = new Test;
	Test* p4 = new Test[3];

	free(p1);
	free(p2);

	delete p3;
	delete[] p4;

	return 0;
}

//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = (int*)malloc(sizeof(int) * 3);
//
//	int* p3 = new int;     //定义1个整型空间
//	int* p4 = new int[3];  //定义3个整型空间
//	int* p5 = new int(10); //定义单个的同时对其进行初始化
//
//	free(p1);
//	free(p2);
//
//	delete p3;    //释放单个对象
//	delete[] p4;  //释放多个对象
//	delete p5;
//
//	return 0;
//}

//class A
//{
//private:
//	static int k;
//	int h;
//public:
//	class B
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//
//	private:
//		int _a;
//	};
//};
//
//int A::k = 1;
//
//int main()
//{
//	A::B b;
//	b.foo(A());
//	return 0;
//}

//class Date; // 前置声明
//class Time
//{
//	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//		, _t(hour, minute, second)
//	{}
//	
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		cout << _t._hour << "-" << _t._minute << "-" << _t._second << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d1(2020, 3, 9, 21, 18, 32);
//	d1.print();
//	return 0;
//}