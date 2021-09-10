#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int x = 0;
	int nworks;
	cin >> nworks;
	mutex mtx; //����ֲ���
	vector<thread> vthreads(nworks);

	for (auto& td : vthreads)
	{
		td = thread([&]() //��lambda���Ǵ����߳�
			{
				mtx.lock();
				for (int i = 0; i < 100000; ++i)
				{
					++x;
				}
				mtx.unlock();
			});
	}

	for (auto& td : vthreads)
	{
		td.join();
	}

	cout << x << endl;

	return 0;
}

//struct Goods
//{
//	string _name;
//	double _price;
//	// ...
//};
//
//struct PriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//
//struct PriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//
//int main()
//{
//	Goods gds[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, { "����", 1.5 } };
//
//	//�º���
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), PriceLess());
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), PriceGreater());
//
//	//lambda���ʽ
//	auto c1 = [](const Goods& g1, const Goods& g2)->bool{return g1._price < g2._price; };
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), c1);
//	auto c2 = [](const Goods& g1, const Goods& g2)->bool{return g1._price > g2._price; };
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), c2);
//
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2;
//
//	auto swap1 = [a, b]()mutable{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//
//	swap1();
//	cout << a << endl;
//	cout << b << endl;
//
//	auto swap2 = [&a, &b](){
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//
//	swap2();
//	cout << a << endl;
//	cout << b << endl;
//
//	//// ��׽�б�[] �����б�() ����ֵ����->type ����{}
//	//auto min1 = [](int x, int y)->int{
//	//	return x < y ? x : y;
//	//};
//	//
//	//cout << min1(a, b) << endl;
//
//	//// ��׽��ǰ��������������ı���a��b
//	//auto min2 = [a, b]()->int {
//	//		return a < b ? a : b;
//	//	};
//	//	
//	//cout << min2() << endl;
//	return 0;
//}

//mutex mtx;
//
//void func(int n, int* px)
//{
//	mtx.lock();
//	for (int i = 0; i < n; ++i)
//	{
//		++* px;
//	}
//	mtx.unlock();
//}
//
//int main()
//{
//	int x = 0;
//	int nworks;
//	cin >> nworks;
//	vector<thread> vthreads(nworks);
//
//	for (auto& td : vthreads)
//	{
//		td = thread(func, 100000, &x);
//	}
//
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//
//	cout << x << endl;
//
//	return 0;
//}

//void func(int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		cout << i << " ";
//	}
//
//	cout << endl;
//}
//
//int main()
//{
//	thread t1(func, 10);
//	thread t2(func, 10);
//
//	thread t3;
//
//	cout << "t3��ʼ��" << endl;
//	t3 = thread(func, 20);
//
//	t1.join();
//	t2.join();
//	t3.join();
//
//	return 0;
//}