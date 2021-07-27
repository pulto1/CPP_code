#include <iostream>

using namespace std;

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template<class T2>
class Data<double, T2>
{
public:
	Data() { cout << "Data<int, T2>" << endl; }
private:
	double _d1;
	T2 _d2;
};

//两个参数偏特化为指针类型
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

int main()
{
	Data<int*, int*> d1;
	Data<double&, int&> d2(3.14, 7);
	return 0;
}

//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};

//int main()
//{
//	char s = 'A';
//
//	const char* sp= &s;
//	printf("%p\n", sp);
//	*sp = 'b';
//	
//	sp = nullptr;
//	printf("%p\n", sp);
//
//	return 0;
//}

//template<class T>
//bool IsEqual(T left, T right)
//{
//	return left == right;
//}
//
//bool IsEqual(char left, char right)
//{
//	cout << "char compare" << ":" << " ";
//	return left == right;
//}
//
//
////template<>
////bool IsEqual<char>(char left, char right)
////{
////	cout << "char compare" << ":" << " ";
////	return left == right;
////}
//
//int main()
//{
//	int a = 1;
//	int b = 1;
//	cout << IsEqual(a, b) << endl;
//
//	char p1 = 'a';
//	char p2 = 'b';
//	cout <<IsEqual(p1, p2) << endl;
//
//	return 0;
//}

//#define N 100;

// N是非类型模板参数
//template<class T, size_t  N>
//class Array
//{
//private:
//	T _a[N];
//};
//
//int main()
//{
//	Array<int, 100> a1;  // 100
//	int n = 1000;
//	Array<int, n> a2;  // 1000
//	// Array<int, 100>* p = new Array < int, 100 > ;
//
//	return 0;
//}