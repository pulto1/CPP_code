#include<iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

void test_set()
{
	//构造一个set对象
	set<int> s1;
	s1.insert(3);
	s1.insert(2);
	s1.insert(5);
	s1.insert(1);
	s1.insert(3);
	s1.insert(5);

	//用迭代器遍历set成员
	set<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		//*it1 = 10; // 不能改
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//用范围for遍历迭代器成员
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	//去重测试
	string strs[] = { "sort", "sort", "insert", "sort", "map" };
	set<string> strunique;
	for (auto& str : strs)
	{
		strunique.insert(str);
	}

	for (auto& str : strunique)
	{
		cout << str << " ";
	}
	cout << endl;

	//set的查找
	auto ret = strunique.find("sort");
	if (ret != strunique.end())
	{
		cout << "找到了" << endl;
	}
}

void test_map()
{
	//构造一个map对象
	map<string, string> dict;
	dict.insert(pair<string, string>("字符串", "string"));
	dict.insert(pair<string, string>("排序", "sort"));
	
	//迭代器遍历
	map<string, string>::iterator dit = dict.begin(); //dit是一个pair对象
	while (dit != dict.end())
	{
		//cout << (*dit).first << ":" << (*dit).second << endl;
		cout << dit->first << ":" << dit->second << endl; //map成员是一个pair结构体，通过该结构体访问两个键值对
		++dit;
	}

	//范围for遍历
	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}

	//普通方式统计次数
	string strs[] = { "sort", "sort", "insert", "sort", "map" };
	map<string, int> countMap;
	for (auto& s : strs)
	{
		auto ret = countMap.find(s);
		if (ret != countMap.end())
		{
			ret->second++;
		}
		else
		{
			//countMap.insert(pair<string, int>(s, 1));
			countMap.insert(make_pair(s, 1));
		}
	}

	//[]重载统计次数
	for (auto& s : strs)
	{
		countMap[s]++;
	}

	for (auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

int main()
{
	//test_set();
	test_map();

	return 0;
}

//class Solution {
//public:
//    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& previ, int inbegin, int inend)
//    {
//        if (previ == preorder.size())
//            return nullptr;
//
//        //中序区间不存在
//        if (inbegin > inend)
//            return nullptr;
//
//        //确定根在中序区间的位置，分割出左子树和右子树的中序
//        int rooti = inbegin;
//        while (rooti <= inend)
//        {
//            if (inorder[rooti] == preorder[previ])
//                break;
//            else
//                rooti++;
//        }
//
//        //[inbegin, rooti - 1] rooti [rooti + 1, inend]
//        TreeNode* root = new TreeNode(preorder[previ]);
//        ++previ;
//
//        root->left = _buildTree(preorder, inorder, previ, inbegin, rooti - 1);
//        root->right = _buildTree(preorder, inorder, previ, rooti + 1, inend);
//
//        return root;
//    }
//
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
//    {
//        int previ = 0;
//        return _buildTree(preorder, inorder, previ, 0, inorder.size() - 1);
//    }
//};
//
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root)
//    {
//        vector<int> v;
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//
//        //cur不为空。表示还有树没有开始访问
//        //st不为空，表示还有结点的右子树没有访问
//        while (cur || !st.empty())
//        {
//            //1.访问并保存左路结点进栈
//            while (cur)
//            {
//                v.push_back(cur->val);
//                st.push(cur);
//                cur = cur->left;
//            }
//
//            //2.对于root这颗数，剩下的是左路结点的右子树没有访问
//            //依次从栈里面拿出来访问
//            TreeNode* top = st.top();
//            st.pop();
//
//            //子问题，走右树
//            cur = top->right;
//        }
//
//        return v;
//    }
//};
//
//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root)
//    {
//        vector<int> v;
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//
//        //cur不为空。表示还有树没有开始访问
//        //st不为空，表示还有结点的右子树没有访问
//        while (cur || !st.empty())
//        {
//            //1.并保存左路结点进栈
//            while (cur)
//            {
//
//                st.push(cur);
//                cur = cur->left;
//            }
//
//            //2.对于root这颗数，剩下的是左路结点和左路结点的右子树没有访问
//            //依次从栈里面拿出来访问
//            TreeNode* top = st.top();
//
//            //访问访问左路结点
//            v.push_back(top->val);
//            st.pop();
//
//            //子问题，走右树
//            cur = top->right;
//        }
//
//        return v;
//    }
//};
//
//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root)
//    {
//        vector<int> v;
//        TreeNode* prev = nullptr;
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//
//        //cur不为空。表示还有树没有开始访问
//        //st不为空，表示还有结点的右子树没有访问
//        while (cur || !st.empty())
//        {
//            //1.并保存左路结点进栈
//            while (cur)
//            {
//                st.push(cur);
//                cur = cur->left;
//            }
//
//            //2.对于root这颗数，剩下的是左路结点和左路结点的右子树没有访问
//            //依次从栈里面拿出来访问
//            TreeNode* top = st.top();
//
//            //如果右为空，或者右孩子等于上一个访问的结点，那说明右树访问过了
//            //取出当前结点访问
//            if (top->right == nullptr || top->right == prev)
//            {
//                v.push_back(top->val);
//                st.pop();
//                prev = top;
//            }
//
//            else
//            {
//                //子问题，走右树
//                cur = top->right;
//            }
//
//        }
//
//        return v;
//    }
//};