#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1 = "hello";

	cout << s1.c_str() << endl;
	cout << s1 << endl;

	s1.push_back('\0');
	s1.push_back('w');
	s1.push_back('o');
	s1.push_back('r');
	s1.push_back('d');

	cout << s1.c_str() << endl;
	cout << s1 << endl;
	
	//s1.push_back('!');
	//cout << s1 << endl;
	//
	//s1.append(" hi!");
	//cout << s1 << endl;

	//s1 += " wow!";
	//cout << s1 << endl;
	
	return 0;
}

//int main()
//{
//	string s1 = "1234";
//
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//
//	cout << endl;
//	/*int num = 0;
//
//	cout << *s1.rbegin() << endl;
//	cout << *(s1.rend() - 1) << endl;
//
//	string::reverse_iterator it = s1.rbegin();
//	while (it != s1.rend())
//	{
//		num *= 10;
//		num += *it - '0';
//		it++;
//	}*/
//	
//	/*cout << *s1.begin() << endl;
//	cout << *(s1.end() - 1) << endl;
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		num *= 10;
//		num += *it - '0';
//		it++;
//	}*/
//
//	///*for (size_t i = 0; i < s1.size(); i++)
//	//{
//	//	num *= 10;
//	//	num += s1[i] - '0';
//	//}*/
//
//	/*cout << num << endl;*/
//	return 0;
//}

//int main()
//{
//	string s1 = "hello world";
//
//	int capacity = s1.capacity();
//	cout << "capacity: " << s1.capacity() << endl;
//	//s1.reserve(100);
//
//	/*s1.resize(100, 'x');*/
//	s1.resize(100);
//	cout << "capacity: " << s1.capacity() << endl;
//	/*for (int i = 0; i < 100; i++)
//	{
//		s1.push_back('!');
//		if (s1.capacity() != capacity)
//		{
//			cout << "capacity: " << s1.capacity() << endl;
//			capacity = s1.capacity();
//		}
//	}*/
//
//	cout << s1 << endl;
//
//	/*cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1.empty() << endl;
//	s1.clear();
//	cout << s1.empty() << endl;*/
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3( 7, 'x');
//	string s4(s2);
//	string s5(s2, 6, 3);
//	string s6(s2, 6, 10);
//	string s7(s2, 6);
//	string s8(s2, 6, string::npos);
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//	cout << s6 << endl;
//	cout << s7 << endl;
//	cout << s8 << endl;
//
//	return 0;
//}

//template <class T>
//
//class string
//{
//public:
//	//³ÉÔ±º¯Êý
//
//private:
//	T* _str;
//	int _size;
//	int _capacity;
//};