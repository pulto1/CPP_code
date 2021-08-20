#pragma once

//template<class K>
//struct BSTreeNode
//{
//	K _key;
//	struct BSTreeNode<K>* _left;
//	struct BSTreeNode<K>* _right;
//
//	BSTreeNode(const K& key)
//		:_key(key)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//
//template<class K>
//class BSTree
//{
//	typedef BSTreeNode<K> Node;
//public:
//	bool Insert(const K& key)
//	{
//		if (_root == nullptr) //搜索二叉树为空，根结点就是要插入的结点
//		{
//			_root = new Node(key);
//			return true;
//		}
//
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		Node* newnode = new Node(key);
//		if (parent->_key > key)
//		{
//			parent->_left = newnode;
//		}
//		else
//		{
//			parent->_right = newnode;
//		}
//
//		return true;
//	}
//
//	const Node* Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//
//		return nullptr;
//	}
//
//	bool Erase(const K& key)
//	{
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				// 准备删除
//				// 1、左为空
//				// 2、右为空
//				// 3、左右都不为空
//				if (cur->_left == nullptr)
//				{
//					// 特殊情况：cur同时根，parent是nullptr
//					if (cur == _root)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						if (cur == parent->_left)
//						{
//							parent->_left = cur->_right;
//						}
//						else
//						{
//							parent->_right = cur->_right;
//						}
//					}
//					
//					delete cur;
//				}
//				else if (cur->_right == nullptr)
//				{
//					//...
//				}
//				else
//				{
//					// 替代法删除
//					// 右树最小节点（最左节点）
//					// 要注意的特殊情况是右子树根有可能就是最小节点
//					Node* smParent = cur;
//					Node* subMin = cur->_right;
//					while (subMin->_left)
//					{
//						smParent = subMin;
//						subMin = subMin->_left;
//					}
//
//					cur->_key = subMin->_key;
//					// subMin一定是一个左为空的节点
//					if (smParent->_left == subMin)
//					{
//						smParent->_left = subMin->_right;
//					}
//					else
//					{
//						smParent->_right = subMin->_right;
//					}
//
//					delete subMin;
//				}
//
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//			return;
//
//		_InOrder(root->_left);
//		cout << root->_key << " ";
//		_InOrder(root->_right);
//	}
//
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//
//private:
//	Node* _root = nullptr;
//};


// 1、key的搜索模型-》set
// a、查找在不在
// b、排序+去重

// 2、key/value的搜索模型-》map
// a、查找在不在
// b、排序+去重
// c、通过key查找value  字典  统计次数 

template<class K, class V>
struct BSTreeNode
{
	const K _key;
	V _value;

	struct BSTreeNode<K, V>* _left;
	struct BSTreeNode<K, V>* _right;

	BSTreeNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		Node* newnode = new Node(key, value);
		if (parent->_key > key)
		{
			parent->_left = newnode;
		}
		else
		{
			parent->_right = newnode;
		}

		return true;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << ":" << root->_value << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root = nullptr;
};