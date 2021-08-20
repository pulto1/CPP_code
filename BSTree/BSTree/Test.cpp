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
	dict.Insert("string", "�ַ���");
	dict.Insert("sort", "����");
	dict.Insert("insert", "����");
	dict.Insert("left", "���");

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
	cout << "���ʲ�����" << endl;
	}
	}*/

	string strArr[] = { "ƻ��", "ƻ��","�㽶","�㽶","�㽶","�㽶", "����", "����", "ƻ��", "ƻ��" };
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