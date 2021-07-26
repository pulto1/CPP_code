#include "Queue.h"
#include "Stack.h"
#include <queue>

using namespace std;

void test_priority_queue()
{
	// 默认是大的优先级高
	priority_queue<int> pq;
	pq.push(1);
	pq.push(5);
	pq.push(3);
	pq.push(0);
	pq.push(6);
	pq.push(3);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

class Less
{
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

struct Goods
{
	int price;
	int saleNum;
	// ...
};

struct LessGoodsPrice
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1.price < g2.price;
	}
};

struct LessGoodsSaleNum
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1.saleNum < g2.saleNum;
	}
};

void TestSort()
{
	vector<Goods> v = { { 1, 3 }, { 5, 2 }, { 2, 3 } };
	sort(v.begin(), v.end(), LessGoodsPrice());
	sort(v.begin(), v.end(), LessGoodsSaleNum());
}

int main()
{
	/*bit::test_stack();
	bit::test_queue();*/

	/*test_priority_queue();*/

	Less ls;
	cout << ls(1, 2);
	return 0;
}