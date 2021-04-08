#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>


//using namespace std;
//
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}

//#include <stdio.h>
//
//namespace ret 
//{
//	int scanf = 0;
//}
//
//int main()
//{
//	
//	printf("%d\n", scanf);
//}

//#include <stdio.h>
//
//namespace N
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//}
//
//using N::b;
//using namespace N;
//
//int main()
//{
//	printf("a = %d\n", N::a);
//	printf("a = %d\n", b);
//	printf("c = %d\n", c);
//	return 0;
//}

//#include <iostream>
//
//using std::cout;
//using std::endl;
//
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}

//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}

//#include <stdio.h>
//
//namespace N2
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N3
//	{
//		int c = 30;
//		int d = 40;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//int main()
//{
//	printf("%d\n", N2::a);
//	printf("%d\n", N2::Add(3, 4));
//	printf("%d\n", N2::N3::c);
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a = 48;
//	double b = 2.222;
//	char ch1 = 'x';
//	char ch2 = 50;
//
//	cin >> a;
//	cin >> b >> ch1;
//
//	cout << a << "--" << b << "--" << ch1 << endl;
//
//	//cout << a << endl; //打印整型
//	//cout << b << endl; //打印浮点型
//	//cout << ch1 << endl; //打印字符型
//	//cout << ch2 << endl; //打印ASCII转换的字符型
//	//cout << &a << endl;  //打印地址
//
//	return 0;
//}

//#include <iomanip>
//
//
//using namespace std;
//
////void TestFunc(int a = 0)
////{
////	cout << a << endl;
////}
//
////void TestFunc(int a = 10, int b = 20, int c = 30)
////{
////	cout << "a = " << a << endl;
////	cout << "b = " << b << endl;
////	cout << "c = " << c << endl;
////}
//
//#include "Test.h"
//
//void TestFunc(int a, int b, int c)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	TestFunc(1);
//	TestFunc(1, 2);
//	TestFunc(1, 2, 3);
//}



//struct stu
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//	double f = 3.14159;
//	printf("%.2lf\n", f);
//	cout.unsetf(ios::fixed);
//	cout << setprecision(3) << f << endl;
//	//struct stu s = { "zhangsan", 20 };
//	//printf("name：%s age: %d\n", s.name, s.age);
//	//cout << "name: " << s.name << ' ' << "age: " << s.age << endl;
//	return 0;
//}

#include <iostream>
#include "Test.h"

using namespace std;

//int Add(int i, int j)
//{
//	return i + j;
//}
//
//int Add(int i, int j, int k)
//{
//	return i + j + k;
//}
//
//int Add(int i, int j)
//{
//	return i + j;
//}
//
//int Add(double i, double j)
//{
//	return i + j;
//}



int main()
{
	Add(1, 1.0);
	return 0;
}