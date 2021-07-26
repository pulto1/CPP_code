#pragma once

#include <deque>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<class T>
class Less {
public:
	bool operator()(const T& a, const T& b) {
		return a < b;
	}
};

template<class T>
class Greater {
public:
	bool operator()(const T& a, const T& b) {
		return a > b;
	}
};

namespace bit
{
	template<class T, class Container = vector<T>,
		class Compare = Greater<T>>
		class priority_queue
	{
	public:
		/*priority_queue()
		{}*/

		priority_queue() = default;

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			// 从下往上建堆
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				AdjustDown(i);
			}

			// 从上往下建堆
			/*for (int i = 1; i < _con.size(); ++i)
			{
			AdjustUp(i);
			}*/
		}

		// 
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] > _con[parent])
				if (com(_con[child], _con[parent]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}

		void AdjustDown(int parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				// 
				//if (child+1 < _con.size() && _con[child+1] > _con[child])
				if (child + 1 < _con.size() && com(_con[child + 1], _con[child]))
				{
					++child;
				}

				//if (_con[child] > _con[parent])
				if (com(_con[child], _con[parent]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			assert(size() > 0);

			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		const T& top() const
		{
			return _con[0];
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

		Container _con;
	};

	void test_priority_queue()
	{
		// 默认是大的优先级高
		//priority_queue<int, vector<int>, Greater<int>> pq;
		priority_queue<int, vector<int>, Less<int>> pq;
		pq.push(1);
		pq.push(5);
		pq.push(3);
		pq.push(0);
		pq.push(6);
		pq.push(3);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}

		cout << endl;

	}
}

