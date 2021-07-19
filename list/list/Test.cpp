#include <iostream>
#include "list.h"

using namespace std;

namespace bit
{
	void TestList1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
	}
	struct Point
	{
		int x;
		int y;
	};

	void TestList2()
	{
		list<Point> lt;
		lt.push_back({ 1, 2 });
		lt.push_back({ 3, 3 });
		lt.push_back({ 5, 6 });
		list<Point>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << it->x << ":" << it->y << endl;
			//cout << (*it).x << ":" << (*it).y << endl;
			++it;
		}
		cout << endl;
	}
}

int main()
{
	bit::TestList2();
	return 0;
}