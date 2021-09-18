#include <iostream>
#include <vector>
#include <map>
#include <initializer_list>

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3 ,4, 5 };
	for (auto e : v) //遍历容器转换成迭代器
	{
		cout << e << " ";
	}
	cout << endl;

	int arr[] = { 1, 2, 3 ,4 ,5 };
	for (auto e : arr) //遍历数组转换成指针
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
//	// 如果没有带参数，推导函数的类型
//	cout << typeid(decltype(GetMemory)).name() << endl;
//	// 如果带参数列表，推导的是函数返回值的类型,注意：此处只是推演，不会执行函数
//	cout << typeid(decltype(GetMemory(0))).name() << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	// 用decltype推演a+b的实际类型，作为定义c的类型
//	decltype(a + b) c;
//	cout << typeid(c).name() << endl;
//	return 0;
//}
//
//int main()
//{
//	std::map<std::string, std::string> m{ {"apple", "苹果"}, {"banana","香蕉"} };
//	cout << typeid(m).name() << endl; //获取对象m的类型
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
//	// c如果给成short，会造成数据丢失，如果能够让编译器根据a+b的结果推导c的实际类型，就不会存在问题
//	short c = a + b;
//
//	std::map<std::string, std::string> m{ {"apple", "苹果"}, {"banana","香蕉"} };
//	// 使用迭代器遍历容器, 迭代器类型太繁琐
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
//	Vector(initializer_list<T> l) : _capacity(l.size()), _size(0) //拷贝构造函数
//	{
//		_array = new T[_capacity];
//		for (auto e : l)
//			_array[_size++] = e;
//	}
//	Vector<T>& operator=(initializer_list<T> l) //赋值运算符重载函数
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
//	Point p{ 1, 2 }; //编译器先构造一个Point的匿名对象，再调用匿名对象去拷贝构造p对象
//	return 0;
//}

//int main()
//{
//	// 内置类型变量
//	int x1 = { 10 };
//	int x2{ 10 };
//	int x3 = 1 + 2;
//	int x4 = { 1 + 2 };
//	int x5{ 1 + 2 };
//
//	// 数组
//	int arr1[5]{ 1,2,3,4,5 };
//	int arr2[]{ 1,2,3,4,5 };
//
//	// 动态数组，在C++98中不支持
//	int* arr3 = new int[5]{ 1,2,3,4,5 };
//
//	// 标准容器
//	vector<int> v{ 1,2,3,4,5 };
//	map<int, int> m{ {1,1}, {2,2,},{3,3},{4,4} };
//
//	return 0;
//}