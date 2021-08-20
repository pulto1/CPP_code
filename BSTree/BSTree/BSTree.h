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
//		if (_root == nullptr) //����������Ϊ�գ���������Ҫ����Ľ��
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
//				// ׼��ɾ��
//				// 1����Ϊ��
//				// 2����Ϊ��
//				// 3�����Ҷ���Ϊ��
//				if (cur->_left == nullptr)
//				{
//					// ���������curͬʱ����parent��nullptr
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
//					// �����ɾ��
//					// ������С�ڵ㣨����ڵ㣩
//					// Ҫע���������������������п��ܾ�����С�ڵ�
//					Node* smParent = cur;
//					Node* subMin = cur->_right;
//					while (subMin->_left)
//					{
//						smParent = subMin;
//						subMin = subMin->_left;
//					}
//
//					cur->_key = subMin->_key;
//					// subMinһ����һ����Ϊ�յĽڵ�
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


// 1��key������ģ��-��set
// a�������ڲ���
// b������+ȥ��

// 2��key/value������ģ��-��map
// a�������ڲ���
// b������+ȥ��
// c��ͨ��key����value  �ֵ�  ͳ�ƴ��� 

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