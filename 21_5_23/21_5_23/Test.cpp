#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

//void test_map()
//{
//	map<string, string> dict;
//	dict.insert(pair<string, string>("字符串", "string"));
//	dict.insert(pair<string, string>("排序", "sort"));
//	dict.insert(pair<string, string>("排序", "xxx")); 
//	//	// 插入值时，只看有没有相同key，不看value是否相同
//
//	//dict["结束"] = "finish";
//	//dict["删除"] = "delete";
//	//dict["字符串"] = "string";
//	//dict["字符串"] = "str";
//	////dict["删除"];
//	////dict["left"] = "左边"; // 插入+修改
//	////dict["left"] = "剩余"; // 修改
//	//map<string, string>::iterator dit = dict.begin();
//	//while (dit != dict.end())
//	//{
//	//	//cout << (*dit).first << ":" << (*dit).second << endl;
//	//	cout << dit->first << ":" << dit->second << endl;
//	//	++dit;
//	//}
//
//	//dict.erase("字符串");
//	//dict.erase("字符");
//
//	for (auto& e : dict)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//
//	
//	////for (auto& s : strs)
//	////{
//	////	auto ret = countMap.find(s);
//	////	if (ret != countMap.end())
//	////	{
//	////      //(*ret).second++;
//	////		ret->second++;
//	////	}
//	////	else
//	////	{
//	////		//countMap.insert(pair<string, int>(s, 1));
//	////		countMap.insert(make_pair(s, 1));
//	////	}
//	////}
//
//	////for (auto& s : strs)
//	////{
//	////	pair<map<string, int>::iterator, bool> ret = \
//	////		countMap.insert(make_pair(s, 1));
//	////	// 插入失败，s已经在map中
//	////	if (ret.second == false)
//	////	{
//	////		ret.first->second++;
//	////	}
//	////}
//
//	//string strs[] = { "sort", "sort", "insert", "sort", "map" };
//	//map<string, int> countMap;
//	//
//	//for (auto& s : strs)
//	//{
//	//	pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(s, 0));
//	//	if(ret.second == true) //插入成功时
//	//		ret.first->second++;
//
//	//	else //插入失败时
//	//		ret.first->second++;
//	//}
//
//	/*for (auto& s : strs)
//	{
//		countMap[s]++;
//	}
//
//	for (auto& e : countMap)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}*/
//}

//void test_multiset()
//{
//	// 1、排序
//	multiset<int> ms;
//	ms.insert(1);
//	ms.insert(1);
//	ms.insert(2);
//	ms.insert(1);
//	ms.insert(5);
//	ms.insert(2);
//	ms.insert(2);
//	ms.insert(2);
//	ms.insert(3);
//
//	multiset<int>::iterator it = ms.begin();
//	while (it != ms.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//
//	cout << ms.count(1) << endl;
//	//	如果有多个相同的值，找的中序遍历第一个
//	auto pos = ms.find(2);
//	while (pos != ms.end())
//	{
//		cout << *pos << " ";
//		++pos;
//	}
//}
//
//void test_multimap()
//{
//	typedef multimap<string, string> DICT;
//	typedef multimap<string, string>::iterator DICT_IT;
//
//	//multimap<string, string> dict;
//	DICT dict;
//	dict.insert(make_pair("left", "剩余"));
//	dict.insert(make_pair("left", "左边"));
//	dict.insert(make_pair("left", "左边"));
//	dict.insert(make_pair("string", "字符串"));
//
//	DICT_IT it = dict.begin();
//	while (it != dict.end())
//	{
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//}

void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	typedef map<string, int>::iterator CountMapIt;
	map<string, int> countMap;
	for (auto& e : fruits)
	{
		countMap[e]++;
	}

	// 排序 1、vecctor+sort 2、multimap/multiset
	vector<CountMapIt> v;
	CountMapIt it = countMap.begin();
	while (it != countMap.end())
	{
		v.push_back(it);
		++it;
	}

	struct CountMapItCompare
	{
		bool operator()(const CountMapIt& it1,
			const CountMapIt& it2)
		{
			return it1->second > it2->second;
		}
	};

	sort(v.begin(), v.end(), CountMapItCompare());


	for (auto& e : v)
	{
		cout << e->first << ":" << e->second << endl;
		k--;
		if (k == 0)
		{
			break;
		}
	}
}


int main()
{
	//test_set();
	//test_map();
	//test_multiset();
	//test_multimap();

	vector<string> v = { "西瓜", "樱桃", "西瓜", "樱桃", "樱桃", "香蕉", "香蕉", "香蕉", "香蕉", "苹果", "榴莲", "榴莲", "香蕉", "香蕉", "香蕉", "香蕉", "西瓜", "西瓜", "西瓜" };
	GetFavoriteFruit(v, 3);

	return 0;
}

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		typedef map<string, int>::iterator CountMapIt;
		map<string, int> countMap;
		for (auto& e : words)
		{
			countMap[e]++;
		}

		multimap<int, string, greater<int>> sortMap;
		for (auto& e : countMap)
		{
			sortMap.insert(make_pair(e.second, e.first));
		}

		vector<string> v;
		auto rit = sortMap.begin();
		while (k--)
		{
			v.push_back(rit->second);
			++rit;
		}

		return v;
	}
};