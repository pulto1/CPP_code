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

	// �������� -- ���
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;

		strcpy(_str, s._str);
	}

	// �ƶ����� -- ǳ����
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;
		std::swap(_str, s._str);
	}

	// ������ֵ -- ���
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

	// �ƶ���ֵ -- ǳ����
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

//  ��ֵ����������
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
//	//// �����Ż�������Ӧ�������ο������죬�����������Ż���һ��
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
//	//// ���������ĳ��� ������ֵ���õ��ƶ�������ƶ���ֵ��Ч�����ܵõ���������
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
//	// ��ֵ����һ���Ǹ���ֵȡ����
//
//	const int& lr2 = int(1);
//	// const ��ֵ����Ҳ���Ը���ֵȡ����
//
//	int&& rr1 = int(1);
//	// ��ֵ����һ���Ǹ���ֵȡ����
//
//	// ?why ���潲���ڻ�����
//	int&& rr2 = move(val);
//	// ��ֵ���ò���ֱ�Ӹ���ȡ���������ǿ��Ը�move(��ֵ)
//
//	return 0;
//}

//  Ĭ�ϳ�Ա��������  �˽�һ��
// defalut  ��������  -�� һ����ԵĹ��캯��
// delete   ��������  -�� һ����Ե��ǿ������츳ֵ
// C++98 ������/�����Ƽ��� -> ֻ������ʵ��(��ֹ��������Ĭ�ϵ�) + ������˽�У���ֹ���������ⶨ�壩
// C++11 �ṩdelete���÷�����ʵ�ָ��򵥸��������
//class A
//{
//public:
//	 A(int a)
//		: _a(a)
//	{}
//	// ��ʽȱʡ���캯�����ɱ���������
//	A() = default;
//
//	// �����������������ж���ʱ�ñ���������Ĭ�ϸ�ֵ���������
//	A& operator=(const A& a) = default;
//private:
//	int _a = 0; // C++11 ����Ա������ȱʡֵ����Ϲ��캯����defaultʹ��
//};
//
//// A& A::operator=(const A& a) = default; //�����ⶨ��ʱ�ñ���������Ĭ�ϸ�ֵ���������

//class A
//{
//public:
//	A(int a) : _a(a)
//	{}
//
//	// ��ֹ����������Ĭ�ϵĿ������캯���Լ���ֵ���������
//	A(const A&) = delete;
//	A& operator=(const A&) = delete;
//private:
//	int _a;
//};
//int main()
//{
//	A a1(10);
//	// ����ʧ�ܣ���Ϊ����û�п������캯��
//	A a2(a1);
//	// ����ʧ�ܣ���Ϊ����û�и�ֵ���������
//	A a3(20);
//	a3 = a2;
//	return 0;
//}
