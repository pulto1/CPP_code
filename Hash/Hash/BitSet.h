#pragma once
#include <vector>
#include <iostream>

namespace bit
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize((N >> 3) + 1, 0);
		}

		void set(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;

			_bits[index] |= (1 << num);
		}

		void reset(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;

			_bits[index] &= (~(1 << num));
		}

		bool test(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;

			return _bits[index] & (1 << num);
		}

		// 获取位图中比特位的总个数
		size_t size()const { return _bitCount; }
		// 位图中比特为1的个数
		size_t Count()const
		{
			int bitCnttable[256] = {
			0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
			3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
			3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
			4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
			3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
			6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
			4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
			6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
			3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
			4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
			6, 7, 6, 7, 7, 8 };
			size_t size = _bit.size();
			size_t count = 0;
			for (size_t i = 0; i < size; ++i)
			{
				int value = _bit[i];
				int j = 0;
				while (j < sizeof(_bit[0]))
				{
					unsigned char c = value;
					count += bitCntTable[c];
					++j;
					value >>= 8;
				}
			}
			return count;
		}
	private:
		std::vector<char> _bits;
		//std::vector<int> _bits; 
	};

	void test_bitset()
	{
		bitset<100> bs;
		bs.set(10);
		bs.set(17);
		bs.set(80);

		cout << bs.test(10) << endl;
		cout << bs.test(17) << endl;
		cout << bs.test(80) << endl;
		cout << bs.test(81) << endl << endl;

		bs.reset(80);
		bs.set(81);

		cout << bs.test(10) << endl;
		cout << bs.test(17) << endl;
		cout << bs.test(80) << endl;
		cout << bs.test(81) << endl;

		//bitset<-1> bs_max;
		//bitset<0xffffffff> bs_max;
	}
}

