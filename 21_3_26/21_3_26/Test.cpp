#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

namespace bit
{
	class string
	{
	public:
		//构造函数
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//析构函数
		~string()
		{
			delete[]_str;
			_str = nullptr;
		}

		//拷贝构造函数
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		//赋值运算符重载
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(_str, tmp._str);
			}

			return *this;
		}
	private:
		char* _str;
	};
}

int main()
{
	bit::string s1 = "hello world";
	bit::string s2 = "how are you";
	s1 = s2;
	/*bit::string s2(s1);*/
	return 0;
}