#define _CRT_SECURE_NO_WARNINGS

#include "string.h"



void print(const bit::string& s)
{
	bit::string::const_iterator it = s.begin();
	if (it != s.end())
	{
		cout << s.begin();
		it++;
	}

	cout << endl;
}

int main()
{
	bit::string s;
	s += '1';
	s += "11111";

	///*bit::*/string s1;
	//cin >> s1;
	//cout << s1 << endl;

	/*bit::string s1 = "hello world";*/
	/*bit::string s1 = "123456789";
	bit::string s2 = "1234564";
	bit::string s3 = "1234564";
	cout << (s1 > s2) << endl;
	cout << (s2 == s3) << endl;
	cout << (s1 == s3) << endl;*/
	/*cout << s1.find('2') << endl;
	cout << s1.find("67") << endl;*/
	/*s1.erase(1, 1);
	print(s1);
	s1.erase(2);
	print(s1);*/

	//s1.insert(2, "cpp");
	//print(s1);
	/*s1.insert(0, "");
	print(s1);*/
	/*string s2 = "1234";
	s2.insert(0, "");
	cout << s2 << endl;*/
	/*s1.insert(2, 'c');
	print(s1);
	s1.insert(2, 'c');
	print(s1);*/
	//s1.resize(2);
	//print(s1);
	//s1.resize(6, 'x');
	//print(s1);

	/*s1 += 'x';
	s1 += "hello world";*/
	//print(s1);

	/*for (auto& e : s1)
	{
		e += 1;
	}

	print(s1);*/

	/*print(s1);*/

	//bit::string::iterator it = s1.begin();
	//if (it != s1.end())
	//{
	//	cout << s1.begin();
	//	it++;
	//}
	//
	//	cout << endl;
	
	//for (size_t i = 0; i < s1.size(); i++)
	//{
	//	cout << s1[i];
	//}

	//cout << endl;

	/*bit::string s3 = "i love you";
	s3 = s1;
	bit::string s2(s1);*/

	return 0;
}