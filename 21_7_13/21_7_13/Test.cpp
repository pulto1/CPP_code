#include <iostream>
#include <vector>
#include <map>
#include <initializer_list>

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3 ,4, 5 };
	for (auto e : v) //��������ת���ɵ�����
	{
		cout << e << " ";
	}
	cout << endl;

	int arr[] = { 1, 2, 3 ,4 ,5 };
	for (auto e : arr) //��������ת����ָ��
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

//void* GetMemory(size_t size)
//{
//	return malloc(size);
//}
//int main()
//{
//	// ���û�д��������Ƶ�����������
//	cout << typeid(decltype(GetMemory)).name() << endl;
//	// ����������б��Ƶ����Ǻ�������ֵ������,ע�⣺�˴�ֻ�����ݣ�����ִ�к���
//	cout << typeid(decltype(GetMemory(0))).name() << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	// ��decltype����a+b��ʵ�����ͣ���Ϊ����c������
//	decltype(a + b) c;
//	cout << typeid(c).name() << endl;
//	return 0;
//}
//
//int main()
//{
//	std::map<std::string, std::string> m{ {"apple", "ƻ��"}, {"banana","�㽶"} };
//	cout << typeid(m).name() << endl; //��ȡ����m������
//
//	return 0;
//}

//template<class T1, class T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}

//int main()
//{
//	short a = 32670;
//	short b = 32670;
//	// c�������short����������ݶ�ʧ������ܹ��ñ���������a+b�Ľ���Ƶ�c��ʵ�����ͣ��Ͳ����������
//	short c = a + b;
//
//	std::map<std::string, std::string> m{ {"apple", "ƻ��"}, {"banana","�㽶"} };
//	// ʹ�õ�������������, ����������̫����
//	std::map<std::string, std::string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << " " << it->second << endl;
//		++it;
//	}
//	return 0;
//}

//template<class T>
//class Vector 
//{
//public:
//	// ...
//	Vector(initializer_list<T> l) : _capacity(l.size()), _size(0) //�������캯��
//	{
//		_array = new T[_capacity];
//		for (auto e : l)
//			_array[_size++] = e;
//	}
//	Vector<T>& operator=(initializer_list<T> l) //��ֵ��������غ���
//	{
//		delete[] _array;
//		size_t i = 0;
//		for (auto e : l)
//			_array[i++] = e;
//		return *this;
//	}
//	// ...
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};

//class Point
//{
//public:
//	Point(int x = 0, int y = 0) : _x(x), _y(y)
//	{}
//private:
//	int _x;
//	int _y;
//};
//
//int main()
//{
//	Point p{ 1, 2 }; //�������ȹ���һ��Point�����������ٵ�����������ȥ��������p����
//	return 0;
//}

//int main()
//{
//	// �������ͱ���
//	int x1 = { 10 };
//	int x2{ 10 };
//	int x3 = 1 + 2;
//	int x4 = { 1 + 2 };
//	int x5{ 1 + 2 };
//
//	// ����
//	int arr1[5]{ 1,2,3,4,5 };
//	int arr2[]{ 1,2,3,4,5 };
//
//	// ��̬���飬��C++98�в�֧��
//	int* arr3 = new int[5]{ 1,2,3,4,5 };
//
//	// ��׼����
//	vector<int> v{ 1,2,3,4,5 };
//	map<int, int> m{ {1,1}, {2,2,},{3,3},{4,4} };
//
//	return 0;
//}