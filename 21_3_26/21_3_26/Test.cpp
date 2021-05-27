#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

namespace bit
{
	class string
	{
	public:
		//���캯��
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//��������
		~string()
		{
			delete[]_str;
			_str = nullptr;
		}

		//�������캯��
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		//��ֵ���������
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