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
//	dict.insert(pair<string, string>("�ַ���", "string"));
//	dict.insert(pair<string, string>("����", "sort"));
//	dict.insert(pair<string, string>("����", "xxx")); 
//	//	// ����ֵʱ��ֻ����û����ͬkey������value�Ƿ���ͬ
//
//	//dict["����"] = "finish";
//	//dict["ɾ��"] = "delete";
//	//dict["�ַ���"] = "string";
//	//dict["�ַ���"] = "str";
//	////dict["ɾ��"];
//	////dict["left"] = "���"; // ����+�޸�
//	////dict["left"] = "ʣ��"; // �޸�
//	//map<string, string>::iterator dit = dict.begin();
//	//while (dit != dict.end())
//	//{
//	//	//cout << (*dit).first << ":" << (*dit).second << endl;
//	//	cout << dit->first << ":" << dit->second << endl;
//	//	++dit;
//	//}
//
//	//dict.erase("�ַ���");
//	//dict.erase("�ַ�");
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
//	////	// ����ʧ�ܣ�s�Ѿ���map��
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
//	//	if(ret.second == true) //����ɹ�ʱ
//	//		ret.first->second++;
//
//	//	else //����ʧ��ʱ
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
//	// 1������
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
//	//	����ж����ͬ��ֵ���ҵ����������һ��
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
//	dict.insert(make_pair("left", "ʣ��"));
//	dict.insert(make_pair("left", "���"));
//	dict.insert(make_pair("left", "���"));
//	dict.insert(make_pair("string", "�ַ���"));
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

	// ���� 1��vecctor+sort 2��multimap/multiset
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

	vector<string> v = { "����", "ӣ��", "����", "ӣ��", "ӣ��", "�㽶", "�㽶", "�㽶", "�㽶", "ƻ��", "����", "����", "�㽶", "�㽶", "�㽶", "�㽶", "����", "����", "����" };
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