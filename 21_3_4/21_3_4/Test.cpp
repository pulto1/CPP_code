#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date(int year = 1970, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d;
	cin >> d;
	cout << d << endl;
	return 0;
}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d(2017, 12, 24);
//	d << cout;
//	return 0;
//}

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b;
//};
//class A
//{
//public:
//	void Print()
//	{
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//	}
//private:
//	// 非静态成员变量，可以在成员声明时给缺省值。
//	int a = 10;
//	B b = 20;
//	int* p = (int*)malloc(4);
//};
//
//int main()
//{
//	A a;
//	a.Print();
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		_count++;
//	}
//
//	A(const A& a)
//	{
//		_count++;
//	}
//
//	static int Getcount()
//	{
//		cout << x << endl;
//		return _count;
//	}
//private:
//	int x;
//	static int _count;
//};
//
////int _count = 0;
//int A::_count = 0;
//
//
//int main()
//{
//	/*cout << sizeof(A) << endl;*/
//
//	A a1;
//	A a2;
//	A a3;
//	A a4(a1);
//	A a5(a1);
//	A();
//
//	cout << A::Getcount() << endl;
//	cout << a1.Getcount() << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	explicit A(int a)
//		:_a(a)
//	{}
//
//	//A(const A& aa)
//	//	:_a(aa._a)
//	//{}
//
//	void Print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	/*A aa1(1);*/
//	A aa2 = 2; 
//	// 结果调用构造函数 
//	// 隐式类型转换-》 先构造一个A(2)匿名临时对象，再用这个临时对象去拷贝构造aa2
//	// 最后呢，编译器把这两个过程优化合并了，直接调了构造函数
//
//	/*aa1.Print();*/
//	aa2.Print();
//
//	//int i = 0;
//	//const double& d = i;
//
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//
//int main()
//{
//	A aa1(1);  // 他的生命周期在main函数域
//	A(2);  // 匿名对象，他的生命周期在这一行
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() 
//{
//	A aa(1);
//	aa.Print();
//}

//class Time
//{
//public:
//	Time(int hour/* = 2*/, int second/* = 32*/)
//	{
//		cout << "copy" << endl;
//		_hour = hour;
//		_second = second;
//	}
//
//	Time& operator=(const Time& t)
//	{
//		cout << "Time& operator=(const Time& t)" << endl;
//		return *this;
//	}
//
//private:
//	int _hour;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year, int month, int day, int hour, int second/*, int a*/)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		Time t(hour, second);
//		_t = t;
//		/*_a = a;*/
//	}
//
//	//Date(int year, int month, int day, int hour, int second/*int a*/)
//	//	: _year(year)
//	//	, _month(month)
//	//	, _day(day)
//	//	, _t(hour, second)
//	//{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//
//	/*const int _a;*/
//};

//class Time
//{
//public:
//	Time(int hour = 0, int second = 0)
//	{
//		cout << "Time(int hour, int second)" << endl;
//		_hour = hour;
//		_second = second;
//	}
//
//	Time& operator=(const Time& t)
//	{
//		cout << "Time& operator=(const Time& t)" << endl;
//		return *this;
//	}
//
//private:
//	int _hour;
//	int _second;
//};
//
//class Date
//{
//public:
//	/*Date(int year, int month, int day, int hour, int second)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//
//		Time t(hour, second);
//		_t = t;
//	}*/
//
//	Date(int year, int month, int day, int hour, int second)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//		, _t(hour, second)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d1(2021, 3, 4, 1, 1);
//	return 0;
//}