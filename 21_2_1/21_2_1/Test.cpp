#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <iostream>

using namespace std;

class A
{
public:
	void Init(int a1, int a2)
	{
		_a1 = a1;
		_a2 = a2;
	}

	void print()
	{
		cout << _a1 << endl;
		cout << _a2 << endl;
	}

private:
	int _a1;
	int _a2;
};

int main()
{
	A a;
	a.Init(1, 2);
	a.print();

	return 0;
}

//struct Student
//{
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
//int main()
//{
//	Student s;
//	s.SetStudentInfo("Peter", "男", 18);
//	return 0;
//}
//
//struct students
//{
//	char _name[20];
//	char _gender[3];
//	int _age;
//};

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(nullptr);
//	return 0;
//}

//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//		cout << *p << endl;
//}

//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (auto e : array)
//		e *= 2;
//	for (auto e : array)
//		cout << e << " ";
//}
//
//int main()
//{
//	TestFor();
//	return 0;
//}

//void TestAuto()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
//}
//
//int main()
//{
//	int a = 4.0;
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}

//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	
//	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	int* pa = &a;
//	*pa = 20;
//	return 0;
//}

//struct A { int a[10000]; };
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	//int& ret = Add(1, 2);
//	//printf("hello\n");
//	//cout << "Add(1, 2) is :" << ret << endl;
//	TestReturnByRefOrValue();
//	return 0;
//}

//int& Count()
//{
//	static int n = 0;
//		n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//
//	return 0;
//}

//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}

//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	//int a = 10;
//	//int b = 20;
//	///*Swap(&a, &b);*/
//	//Swap(a, b);
//	//cout << "a == " << a << endl;
//	//cout << "b == " << b << endl;
//	TestRefAndValue();
//	return 0;
//}

//void test()
//{
//	double a = 3.14;
//	const int& b = a;
//}

//void test()
//{
//	double a = 3.14;
//	int b = a;
//}

//void test()
//{
//	const int& a = 10;
//}

//void test()
//{
//	int a = 10;
//	const int& b = a;
//}

//void test()
//{
//	const int a = 10;
//	const int& b = a;
//}

//void test()
//{
//	int a = 10;
//	int& b = a;
//	
//	int c = 10;
//	int& b = c;
//}

//void test()
//{
//	int a = 10;
//	int& b = a;
//	int& c = a;
//	int& d = a;
//
//	printf("&a == %p\n", &a);
//	printf("&b == %p\n", &b);
//	printf("&c == %p\n", &c);
//	printf("&d == %p\n", &d);
//}

//int main()
//{
//	int a = 10;
//	int& b;
//	int b = a;
//}

//int main()
//{
//	int a = 10;
//	int& b = a; //<=== = 定义引用类型
//	printf("a = %d, b = %d\n", a, b);
//
//	a = 20;
//	printf("a = %d, b = %d\n", a, b);
//
//	b = 30;
//	printf("a = %d, b = %d\n", a, b);
//
//	printf("a的地址：%p\n", &a);
//	printf("b的地址：%p\n", &b);
//}