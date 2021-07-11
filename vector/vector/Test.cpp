#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "vector.hpp"

void TestVector2()
{
	bit::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.resize(3);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.resize(10);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.resize(15, 9);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	//v1.resize(0);
	//{
	//	vector<int> tmp;
	//	tmp.swap(v1);
	//}

	/*int i = int();
	cout << i << endl;*/

}

void TestVector1()
{
	bit::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	bit::vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
	}
	cout << endl;

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v1.size(); i++)
	{
		v1[i] *= 2;
		cout << v1[i] << " ";
	}
	cout << endl;
}

void TestVector3()
{
	bit::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	auto it = find(v1.begin(), v1.end(), 3);
	v1.insert(it, 30);

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector4()
{
	bit::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	bit::vector<int> v2(v1);
}

void TestVector5()
{
	bit::vector<string> v1;
	v1.push_back("111");
	v1.push_back("222");
	v1.push_back("333");
	v1.push_back("444");
	v1.push_back("555");

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//TestVector1();
	//TestVector2();
	TestVector5();
	return 0;
}