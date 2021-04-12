#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		cout << "Date(int year, int month, int day)" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	//~Date()
	//{
	//	// ��������Date����û����Ҫ�������Դ
	//	// �����ϸ���˵Date����Ҫд������������Ϊ���ǲ�д��������Ĭ�����ɾͿ�����
	//	cout << "~Date()" << endl;
	//}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	// Ĭ����������������������Ͳ�����
	int _year;  
	int _month;
	int _day;

	// Ĭ����������������Զ�������Ҫ����ģ�����������������
	String _str;
};

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		cout << "Stack(int capacity = 4)" << endl;
//
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	// ��Date��û����Դ��Ҫ�������Բ���Ҫ�Լ�ʵ����������
//	// ��Stack��һ��Ҫ�����ͷ���Դ������һ��Ҫ�Լ�ʵ����������
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

int main()
{
	Date d1;

	/*Stack st;*/

	return 0;
}

//class Time
//{
//public:
//	Time(int hour = 1, int minute = 2, int second = 3)
//	{
//		cout << "Time()" << endl;
//		_hour = hour;
//		_minute = minute;
//		_second = second;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// ��������(��������)
//	int _year;
//	int _month;
//	int _day;
//	
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

//class Date
//{
//public:
//
//	/*Date(int year, int month, int day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date()
//	{
//		cout << "Date()" << endl;
//
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}*/
//
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	/*void Init(int year, int month, int day)
//	{
//		cout << "this:" << this << endl;
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}*/
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Stack
//{
//public:
//	// ���캯��
//	//Stack()
//	//{
//	//	_a = (int*)malloc(sizeof(int)*4);
//	//	_size = 0;
//	//	_capacity = 4;
//	//}
//
//	//Stack(int capacity)
//	//{
//	//	_a = (int*)malloc(sizeof(int) * capacity);
//	//	_size = 0;
//	//	_capacity = capacity;
//	//}
//
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	//Stack(int* a, int size, int capacity);  ��ʵ��
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};

//int main()
//{
//	// ��Ҫ�ǣ�������(����)�����ͳ�ʼ����
//	// ����ûд��������Ĭ�������˹��캯������������d1�����ֵ�������ֵ
//	// ˵��Ĭ�ϵĹ��������ﲻ�У���Ҫ�����Լ�д
//	Date d1;
//
//	d1.Print();
//
//	Date d2(2021, 2, 2);
//	d2.Print();
//
//	//Stack st1;
//	//Stack st2(10);
//
//	return 0;
//}

//class A
//{
//public:
//	void PrintA(/* A* this */)
//	{
//		cout << this->_a << endl;
//	}
//	void Show(/* A* this */)
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* a = nullptr;
//	//a->PrintA();
//	a->Show();
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		cout << "this:" << this << endl;
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	void Print()
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
//int main()
//{
//	Date d1;
//	d1.Init(2021, 2, 2);
//	cout << "&d1: " << &d1 << endl;
//	/*d1.Print();*/
//
//	Date d2;
//	d2.Init(2021, 2, 3);
//	cout << "&d2: " << &d2 << endl;
//	/*d2.Print();*/
//
//	return 0;
//}

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	char _a;
//};
//
//// ���н��г�Ա����
//class A2 {
//public:
//	void f2() {}
//};
//
//// ����ʲô��û��---����
//class A3
//{};
//
//int main()
//{
//
//	//A a;
//	//cout << sizeof(a) << endl;
//	//cout << sizeof(A) << endl;
//
//	// ��Ա��������ÿ�������Ƕ����ģ���Ա��������ÿ�������ǹ���
//	// �����Ĵ�С��ֻ�����Ա����+�ڴ�������
//	//a1._a;		// �����ǵ�������ȥ��_a
//	//a2._a;
//
//	// �����1��byte��Ϊ��ռλ����ʾʵ�������Ķ�����ڣ����洢����
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	//A2 aa2;
//	//A2 aaa2;
//	//cout << &aa2 << endl;
//	//cout << &aaa2 << endl;
//
//	return 0;
//}