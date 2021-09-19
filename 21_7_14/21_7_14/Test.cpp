#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <string.h>

using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// 拷贝构造 -- 深拷贝
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;

		strcpy(_str, s._str);
	}

	// 移动构造 -- 浅拷贝
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;
		std::swap(_str, s._str);
	}

	// 拷贝赋值 -- 深拷贝
	String& operator=(const String& s)
	{
		cout << "String& operator=(const String& s)" << endl;
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	// 移动赋值 -- 浅拷贝
	//  s2 = String("xxxx");
	String& operator=(String&& s)
	{
		cout << "String& operator=(String&& s)" << endl;
		std::swap(_str, s._str);
		return *this;
	}

	// s1 += s2
	String& operator+=(const String& s)
	{
		//... 

		return *this;
	}

	// s1 + s2
	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);

		return strRet;
	}

	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};

//  右值引用做参数
int main()
{
	list<String> lt;
	lt.push_back("hello11111111111111111111111111"); // void push_back(_Ty&& _Val)

	String s1("hello1111111111111111111111111");
	lt.push_back(s1);    // void push_back(const _Ty& _Val)

	String s2("hello1111111111111111111111111");
	lt.push_back(move(s2));    // void push_back(const _Ty&& _Val)


	return 0;
}

//int main()
//{
//	String s1("hello");
//	String s2("world");
//
//	//String s3 = s1 + s2; 
//	//cout << endl;
//	//// 编译优化，本来应该是两次拷贝构造，编译器可能优化成一次
//	//String s4 = s1 += s2;
//
//	//////////////////////////////////////////////////////
//	String s3;
//	s3 = s1 + s2;
//
//	cout << endl;
//
//	String s4;
//	s4 = s1 += s4;
//
//	//// 类似这样的场景 有了右值引用的移动构造和移动赋值，效率你能得到极大的提高
//	//vector<vector<int>> ret1 = Solution().generate(5);
//	//vector<vector<int>> ret2;
//	//ret2 = Solution().generate(5);
//
//	return 0;
//}

//int main()
//{
//	int val = 10;
//	int& lr1 = val;  
//	// 左值引用一般是给左值取别名
//
//	const int& lr2 = int(1);
//	// const 左值引用也可以给右值取别名
//
//	int&& rr1 = int(1);
//	// 右值引用一般是给右值取别名
//
//	// ?why 后面讲了在回来看
//	int&& rr2 = move(val);
//	// 右值引用不能直接给左取别名，但是可以给move(左值)
//
//	return 0;
//}

//  默认成员函数控制  了解一下
// defalut  让你生成  -》 一般针对的构造函数
// delete   不让生成  -》 一般针对的是拷贝构造赋值
// C++98 防拷贝/防复制技术 -> 只声明不实现(防止编译生成默认的) + 声明成私有（防止别人在类外定义）
// C++11 提供delete，让防拷贝实现更简单更容易理解
//class A
//{
//public:
//	 A(int a)
//		: _a(a)
//	{}
//	// 显式缺省构造函数，由编译器生成
//	A() = default;
//
//	// 在类中声明，在类中定义时让编译器生成默认赋值运算符重载
//	A& operator=(const A& a) = default;
//private:
//	int _a = 0; // C++11 给成员变量给缺省值，配合构造函数的default使用
//};
//
//// A& A::operator=(const A& a) = default; //在类外定义时让编译器生成默认赋值运算符重载

//class A
//{
//public:
//	A(int a) : _a(a)
//	{}
//
//	// 禁止编译器生成默认的拷贝构造函数以及赋值运算符重载
//	A(const A&) = delete;
//	A& operator=(const A&) = delete;
//private:
//	int _a;
//};
//int main()
//{
//	A a1(10);
//	// 编译失败，因为该类没有拷贝构造函数
//	A a2(a1);
//	// 编译失败，因为该类没有赋值运算符重载
//	A a3(20);
//	a3 = a2;
//	return 0;
//}
