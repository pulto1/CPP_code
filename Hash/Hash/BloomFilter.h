#include "BitSet.h"
#include <string>

using namespace std;

struct StrHash1 //仿函数，通过内部的哈希算法，求出字符串在哈希表中的映射位置
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			//hash += ch;
			hash = hash * 131 + ch;
		}

		return hash;
	}
};

struct StrHash2
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash = 65599 * hash + ch;
			//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
		}
		return hash;
	}
};

struct StrHash3
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		size_t magic = 63689;
		for (auto ch : s)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;

		return hash;
	}
};

template<size_t N, class K = string,
class HashFunc1 = StrHash1,
class HashFunc2 = StrHash2,
class HashFunc3 = StrHash3>
class BloomFilter
{
public:
	BloomFilter()
		:_bs(N*4)
		, _n(N*4)
	{}
	void Set(const K& key)
	{
		HashFunc1 hf1;
		size_t i1 = hf1(key) % _n; //%_n防止超出范围
		_bs.set(i1);

		HashFunc2 hf2;
		size_t i2 = hf2(key) % _n;
		_bs.set(i2);

		HashFunc3 hf3;
		size_t i3 = hf3(key) % _n;
		_bs.set(i3);
		cout << i1 << "--" << i2 << "--"<<i3<<endl;
	}

	// 一般不支持删除，删除可能存在把其他值也干掉了
	void Reset(const K& key);

	bool Test(const K& key)
	{
		HashFunc1 hf1;
		size_t i1 = hf1(key) % _n;
		if (!_bs.test(i1))
		{
			return false;
		}

		HashFunc2 hf2;
		size_t i2 = hf2(key) % _n;
		if (!_bs.test(i2))
		{
			return false;
		}

		HashFunc3 hf3;
		size_t i3 = hf3(key) % _n;
		if (!_bs.test(i3))
		{
			return false;
		}

		return true;
	}
private:
	bit::bitset<N> _bs; //布隆过滤器使用位图存储的
	size_t _n; //表的大小，防止映射位置超出范围
};

void TestBloomFilter()
{
	BloomFilter<10> bf;
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html");
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/2528154.html");
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/2528156.html");
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/2528165.html");
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/2528167.html");
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/2528168.html");
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/2528169.html");
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/252816.html");
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/252817.html");
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/252818.html");
	bf.Set("https://www.cnblogs.com/-clq/archive/2012/05/31/252819.html");


	cout << bf.Test("https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html")<< endl;
	cout << bf.Test("https://www.cnblogs.com/-clq/archive/2012/05/31/2528154.html") << endl;
	cout << bf.Test("https://www.cnblogs.com/-clq/archive/2012/05/31/2528156.html") << endl;
	cout << bf.Test("https://www.cnblogs.com/-clq/archive/2012/05/31/2528165.html") << endl<<endl;

	cout << bf.Test("https://www.cnblogs.com/-clq/archive/2012/05/31/2528166.html") << endl;
	cout << bf.Test("https://www.cnblogs.com/-clq/archive/2012/05/31/2528135.html") << endl;
}