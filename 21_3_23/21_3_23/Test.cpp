#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class string
{
public:
	string(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	~string()
	{
		delete[]_str;
		_str = nullptr;
	}

	string(const string& s)
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	string& operator=(const string& s)
	{
		if (_str != s._str)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		return *this;
	}

	/*string()
		:_str(nullptr)
	{}

	string()
		:_str(new char[1])
	{
		_str[0] = '\0';
	}

	string(const char* str)
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}*/
	/*string(const char* str)
		:_str(str)
	{};*/

private:
	char* _str;
};

namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		~string()
		{
			delete[]_str;
			_str = nullptr;
		}

		string(const string& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)
		{
			if (_str != s._str)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}

			return *this;
		}

		/*string()
			:_str(nullptr)
		{}

		string()
			:_str(new char[1])
		{
			_str[0] = '\0';
		}

		string(const char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}*/
		/*string(const char* str)
			:_str(str)
		{};*/

	private:
		char* _str;
	};
}

int main()
{
	bit::string s1 = "hello world";
	bit::string s2 = "i love you";
	s1 = s2;
	/*bit::string s2(s1);*/
	/*bit::string s2;*/
	
	return 0;
}

//class Solution {
//public:
//    bool isLetter(char c)
//    {
//        if ((c >= '0' && c <= '9')
//            || (c >= 'A' && c <= 'Z')
//            || (c >= 'a' && c <= 'z'))
//        {
//            return true;
//        }
//
//        return false;
//    }
//
//    bool isPalindrome(string s)
//    {
//        for (auto& e : s)
//        {
//            if (e >= 'A' && e <= 'Z')
//                e += 32;
//        }
//
//        int left = 0;
//        int right = s.size() - 1;
//        while (left < right)
//        {
//            while (left < right && !isLetter(s[left]))
//            {
//                ++left;
//            }
//
//            while (left < right && !isLetter(s[right]))
//            {
//                --right;
//            }
//
//            if (s[left] != s[right])
//                return false;
//
//            ++left;
//            --right;
//        }
//
//        return true;
//    }
//};