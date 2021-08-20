#include <iostream>
#include <string>
using namespace std;
#include "BSTree.h"

//void TestBSTreeK()
//{
//	BSTree<int> t;
//	t.Insert(5);
//	t.Insert(2);
//	t.Insert(6);
//	t.Insert(8);
//	t.Insert(1);
//
//	t.InOrder();
//
//}

void TestBSTreeKV()
{
	/*BSTree<string, string> dict;
	dict.Insert("string", "×Ö·û´®");
	dict.Insert("sort", "ÅÅÐò");
	dict.Insert("insert", "²åÈë");
	dict.Insert("left", "×ó±ß");

	dict.InOrder();
	string str;
	while (cin>>str)
	{
	BSTreeNode<string, string>* ret = dict.Find(str);
	if (ret)
	{
	cout << ret->_value << endl;
	}
	else
	{
	cout << "µ¥´Ê²»´æÔÚ" << endl;
	}
	}*/

	string strArr[] = { "Æ»¹û", "Æ»¹û","Ïã½¶","Ïã½¶","Ïã½¶","Ïã½¶", "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Æ»¹û" };
	BSTree<string, int> countTree;
	for (auto& str : strArr)
	{
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	countTree.InOrder();
}

int main()
{
	//TestBSTreeK();
	TestBSTreeKV();
	return 0;
}