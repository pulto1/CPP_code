#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
		:_a(new T[4])
		, _size(0)
		, _capacity(4)
	{}

	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_capacity = _size = 0;
	}

	void Push(const T& x); //��������

private:
	T* _a;
	int _size;
	int _capacity;
};

//��ģ���Ա��������
template<class T>
void Stack<T>::Push(const T& x)
{
	...
}

int main()
{
	Stack<int> st1;  // <==== int 
	Stack<double> st2;  // <==== double
	return 0;
}

//typedef int Elemtype;
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_a(new Elemtype[4])
//		, _size(0)
//		, _capacity(4)
//	{}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_capacity = _size = 0;
//	}
//
//private:
//	Elemtype* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st1;  // <==== int 
//	Stack st2;  // <==== double
//	return 0;
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// ͨ�üӷ�����
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2);      // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
//
//	return 0;
//}

//void Test()
//{
//	Add(1, 2);   // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//}

//int main()
//{
//	int i = 10;
//	double d = 3.14;
//	Add<int>(i, d);
//
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	int i1 = 2;
//	int i2 = 3;
//	Swap(i1, i2);
//
//	double d1 = 2.3;
//	double d2 = 3.4;
//	Swap(d1, d2);
//
//	char c1 = 'A';
//	char c2 = 'B';
//	Swap(c1, c2);
//
//	return 0;
//}
//int main()
//{
//	void* p = malloc(1024u * 1024 * 1024 * 2);
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date():" << this << endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date():" << this << endl;
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
//	Date* arr = (Date*)operator new(sizeof(Date) * 3);
//	new(arr)Date(2021, 3, 11);
//	new(arr + 1)Date(2021, 3, 12);
//	new(arr + 2)Date(2021, 3, 13);
//
//	arr->~Date();
//	(arr + 1)->~Date();
//	(arr + 2)->~Date();
//
//	operator delete(arr);
//	/*Date* p1 = new Date(2021, 3, 11);*/
//	/*Date* p2 = new Date[3];*/
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date():" << this << endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date():" << this << endl;
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
//	int* p1 = new int;
//	Date* p2 = new Date;
//
//	delete p1;
//	delete p2;
//	return 0;
//}

//
//int main()
//{
//	int* p1 = (int*)malloc(0x7fffffff);
//	int* p2 = (int*)operator new(0x7fffffff);
//
//	free(p1);
//	operator delete(p2);
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date():" << this << endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date():" << this << endl;
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
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = (int*)operator new(sizeof(int));
//
//	int* p3 = (int*)malloc(sizeof(Date));
//	int* p4 = (int*)operator new(sizeof(Date));
//
//	free(p1);
//	operator delete(p2);
//	free(p3);
//	operator delete(p4);
//	return 0;
//}

//int main()
//{
//	Date* p1 = (Date*)malloc(sizeof(Date));
//	Date* p2 = (Date*)malloc(sizeof(Date) * 3);
//
//	Date* p3 = new Date;
//	Date* p4 = new Date[3];
//	Date* p5 = new Date(2021, 3, 11);
//
//	free(p1);
//	free(p2);
//
//	delete p3;
//	delete[] p4;
//	delete p5;
//
//	return 0;
//}