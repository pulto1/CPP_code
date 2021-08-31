#pragma once
#include <assert.h>
#include <iostream>

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent; // 不是必须
	pair<K, V> _kv;

	int _bf;  // 平衡银子  左右高度差  不是必须

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}

};

template<class K, class V>
struct AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree() = default;
	AVLTree(const AVLTree<K, V>& t);
	AVLTree<K, V>& operator=(AVLTree<K, V> t);
	//~AVLTree();

	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		Node* newnode = cur;

		// 1、更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				// 旋转
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else // cur->_bf == 1
					{
						RotateLR(parent);
					}
				}
				else //parent->_bf == 2
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else // cur->_bf == -1
					{
						RotateRL(parent);
					}
				}

				break;
			}
			else
			{
				assert(false);
			}
		}

		return make_pair(newnode, true);
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}

			subL->_parent = parentParent;
		}

		subL->_bf = parent->_bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;

		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
		}

		subR->_parent = parentParent;

		parent->_bf = subR->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1)  // 说明subLR是右树插入
		{
			subLR->_bf = 0;
			parent->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)  // 说明subLR是左树插入
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;

		}
		else if (bf == 0) // 说明subLR是新增节点
		{
			subL->_bf = subLR->_bf = parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 0)
		{
			subRL->_bf = subR->_bf = parent->_bf = 0;
		}
		else if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			parent->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	int Height(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		return max(Height(root->_left), Height(root->_right)) + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == NULL)
		{
			return true;
		}

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		if (rightHeight - leftHeight != root->_bf)
		{
			cout << "平衡因子异常：" << root->_kv.first << endl;
		}


		return abs(leftHeight - rightHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}

	Node* Find(const K& key);
	V& operator[](const K& key);
	//bool Erase(const K& key);
private:
	Node* _root = nullptr;
};

void TestAVLTree()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;

	for (auto e : a)
	{
		t.Insert(std::make_pair(e, e));
	}

	t.InOrder();

	std::cout << t.IsBalance() << std::endl;
}






