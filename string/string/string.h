#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		////拷贝构造传统写法
		//string(const string& s)
		//{
		//	_size = s._size;
		//	_capacity = s._capacity;
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, s._str);
		//}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//拷贝构造现代写法
		string(const string& s)
			:_str(nullptr)
			, _capacity(0)
			, _size(0)
		{
			string tmp(s._str);
			swap(tmp);
			/*swap(_str, tmp._str);
			swap(_size, tmp._size);
			swap(_capacity, tmp._capacity);*/
		}

		////赋值运算符重载传统写法
		//string& operator=(const string& s)
		//{
		//	if (_str != s._str)
		//	{
		//		delete[] _str;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//		_str = new char[_capacity + 1];
		//		strcpy(_str, s._str);
		//	}

		//	return *this;
		//}

		//赋值运算符重载现代写法
		string& operator=(string s)
		{
			swap(s);
			/*swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);*/

			return *this;
		}

		char& operator[](size_t i)
		{
			assert(i < _size);
			
			return _str[i];
		}

		 char operator[](size_t i) const
		{
			assert(i < _size);

			return _str[i];
		}

		size_t size()
		{
			return _size;
		}

		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}

			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}

				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}

				_str[n] = '\0';
				_size = n;
			}
		}

		void push_back(char ch)
		{
			/*if (_size == _capacity)
			{
				reserve(2 * _capacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';*/
			insert(_size, ch);
		}

		void append(const char* str)
		{
			/*size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;*/
			insert(_size, str);
		}

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 8 : _capacity * 2;
				reserve(newcapacity);
			}

			////错误写法，死循环
			//int end = _size;
			//while (end >= (int)pos)
			//{
			//	_str[end + 1] = _str[end];
			//	--end;
			//}

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			_size++;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + len + 1;
			while (end > pos + len)
			{
				_str[end - 1] = _str[end - len - 1];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		string& operator+=(const string& s)
		{
			append(s._str);
			return *this;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}

			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* sub, size_t pos = 0)
		{
			const char* ret = strstr(_str + pos, sub);
			if (ret == nullptr)
			{
				return npos;
			}

			else
			{
				return ret - _str;
			}
		}

		const char* c_str()
		{
			return _str;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		static const size_t npos;
	};

	const size_t string::npos = -1;

	bool operator>(const string& s1, const string& s2)
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < s1.size() && i2 < s2.size())
		{
			if (s1[i1] > s2[i2])
			{
				return true;
			}

			else if (s1[i1] < s2[i2])
			{
				return false;
			}

			else
			{
				++i1;
				++i2;
			}
		}

		if (i1 < s1.size())
		{
			return true;
		}

		else if (i2 < s1.size())
		{
			return false;
		}

		else
		{
			return false;
		}
	}

	bool operator==(const string& s1, const string& s2)
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < s1.size() && i2 < s2.size())
		{
			if (s1[i1] > s2[i2])
			{
				return false;
			}

			else if (s1[i1] < s2[i2])
			{
				return false;
			}

			else
			{
				++i1;
				++i2;
			}
		}

		if (i1 == s1.size() && i2 == s1.size())
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.resize(0);
		char ch;
		while (1)
		{
			/*cin >> ch;*/   //error
			in.get(ch);
			if (ch == ' ' || ch == '\n')
			{
				break;
			}

			else
			{
				s += ch;
			}
		}

		return in;
	}
}
