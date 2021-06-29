#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vv;
        vv.resize(numRows, vector<int>());
        for (size_t i = 0; i < vv.size(); i++)
        {
            vv[i].resize(i + 1, 0);
            vv[i][0] = 1;
            vv[i][vv[i].size() - 1] = 1;
        }

        for (size_t i = 0; i < vv.size(); i++)
        {
            for (size_t j = 0; j < vv[i].size(); j++)
            {
                if (vv[i][j] == 0)
                {
                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
                }
            }
        }

        return vv;
    }
};

//class Solution {
//public:
//    int singleNumber(vector<int>& nums)
//    {
//        int x = 0;
//        for (auto e : nums)
//        {
//            x ^= e;
//        }
//
//        return x;
//    }
//};

//int main()
//{
//	vector<int> v1;
//	v1.push_back(1); //尾插
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i] << " "; //重载"[]",可以像数组一样访问
//	}
//	cout << endl;
//
//	v1.pop_back(); //尾删
//	for (const auto& v : v1)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	auto it = find(v1.begin(), v1.end(), 3); //查找，通用find而非vector类里面定义的
//	if (it != v1.end())
//	{
//		cout << "找到了" << endl;
//		v1.insert(it, 300); // 任意位置插入
//		for (const auto& v : v1)
//		{
//			cout << v << " ";
//		}
//		cout << endl;
//	}
//
//	v1.erase(it); //删除某一个位置的数据，可能会出错（迭代器失效原因）
//	for (const auto& v : v1)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	size_t sz;
//	std::vector<int> foo;
//	sz = foo.capacity();
//	std::cout << "making foo grow:\n";
//	for (int i = 0; i < 100; ++i) 
//	{
//		foo.push_back(i);
//		if (sz != foo.capacity()) 
//		{
//			sz = foo.capacity();
//			std::cout << "capacity changed: " << sz << '\n';
//		}
//	}
//
//	/*vector<int> v1;
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//	
//	v1.reserve(10);
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//
//	v1.resize(15, 2);
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;*/
//	/*vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };*/
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1(10, 5);
//
//	for (size_t i = 0; i < v1.size(); i++) //"[]"遍历
//	{
//		cout << v1[i] << " ";
//	}
//
//	cout << endl;
//
//	vector<int>::iterator it = v1.begin(); //迭代器遍历
//	while (it != v1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//
//	cout << endl;
//
//	for (auto& e : v1) //范围for遍历
//	{
//		cout << e << " ";
//	}
//
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1; //构造匿名对象v1
//	vector<int> v2(10, 3); //构造10个整型元素3
//	vector<int> v3(v2); //用v2拷贝构造v1
//
//	string st("123456789");
//	vector<char> v4(st.begin(), st.end()); //用迭代器构造
//
//	return 0;
//}