#include<iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

void test_set()
{
	//����һ��set����
	set<int> s1;
	s1.insert(3);
	s1.insert(2);
	s1.insert(5);
	s1.insert(1);
	s1.insert(3);
	s1.insert(5);

	//�õ���������set��Ա
	set<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		//*it1 = 10; // ���ܸ�
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//�÷�Χfor������������Ա
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	//ȥ�ز���
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

	//set�Ĳ���
	auto ret = strunique.find("sort");
	if (ret != strunique.end())
	{
		cout << "�ҵ���" << endl;
	}
}

void test_map()
{
	//����һ��map����
	map<string, string> dict;
	dict.insert(pair<string, string>("�ַ���", "string"));
	dict.insert(pair<string, string>("����", "sort"));
	
	//����������
	map<string, string>::iterator dit = dict.begin(); //dit��һ��pair����
	while (dit != dict.end())
	{
		//cout << (*dit).first << ":" << (*dit).second << endl;
		cout << dit->first << ":" << dit->second << endl; //map��Ա��һ��pair�ṹ�壬ͨ���ýṹ�����������ֵ��
		++dit;
	}

	//��Χfor����
	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}

	//��ͨ��ʽͳ�ƴ���
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

	//[]����ͳ�ƴ���
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
//        //�������䲻����
//        if (inbegin > inend)
//            return nullptr;
//
//        //ȷ���������������λ�ã��ָ����������������������
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
//        //cur��Ϊ�ա���ʾ������û�п�ʼ����
//        //st��Ϊ�գ���ʾ���н���������û�з���
//        while (cur || !st.empty())
//        {
//            //1.���ʲ�������·����ջ
//            while (cur)
//            {
//                v.push_back(cur->val);
//                st.push(cur);
//                cur = cur->left;
//            }
//
//            //2.����root�������ʣ�µ�����·����������û�з���
//            //���δ�ջ�����ó�������
//            TreeNode* top = st.top();
//            st.pop();
//
//            //�����⣬������
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
//        //cur��Ϊ�ա���ʾ������û�п�ʼ����
//        //st��Ϊ�գ���ʾ���н���������û�з���
//        while (cur || !st.empty())
//        {
//            //1.��������·����ջ
//            while (cur)
//            {
//
//                st.push(cur);
//                cur = cur->left;
//            }
//
//            //2.����root�������ʣ�µ�����·������·����������û�з���
//            //���δ�ջ�����ó�������
//            TreeNode* top = st.top();
//
//            //���ʷ�����·���
//            v.push_back(top->val);
//            st.pop();
//
//            //�����⣬������
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
//        //cur��Ϊ�ա���ʾ������û�п�ʼ����
//        //st��Ϊ�գ���ʾ���н���������û�з���
//        while (cur || !st.empty())
//        {
//            //1.��������·����ջ
//            while (cur)
//            {
//                st.push(cur);
//                cur = cur->left;
//            }
//
//            //2.����root�������ʣ�µ�����·������·����������û�з���
//            //���δ�ջ�����ó�������
//            TreeNode* top = st.top();
//
//            //�����Ϊ�գ������Һ��ӵ�����һ�����ʵĽ�㣬��˵���������ʹ���
//            //ȡ����ǰ������
//            if (top->right == nullptr || top->right == prev)
//            {
//                v.push_back(top->val);
//                st.pop();
//                prev = top;
//            }
//
//            else
//            {
//                //�����⣬������
//                cur = top->right;
//            }
//
//        }
//
//        return v;
//    }
//};