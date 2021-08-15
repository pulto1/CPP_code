#include <iostream>

using namespace std;

class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int b = 1;
};

class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int d = 2;
};

typedef void(*VFUNC)(); //重定义函数指针

void PrintVFT(VFUNC* vftable) //形参为函数指针数组的首元素地址
{
	printf("虚表指针：%p\n", vftable);
	for (int i = 0; vftable[i] != nullptr; ++i)
	{
		printf("vftale[%d]:%p->", i, vftable[i]);
		VFUNC f = vftable[i]; //调用指针指向的函数
		f();
		//(*f)();
	}
}

int main()
{
	Base b;
	Derive d;

	PrintVFT((VFUNC*)(*((int*)&d))); //传参，参数必须是函数指针数组的指针
	cout << endl << endl;

	PrintVFT((VFUNC*)(*((int*)&b)));


	return 0;
}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	//cout << sizeof(Base) << endl;
//
//	Base b1;
//	Base b2;
//
//	printf("虚表指针：%p\n", *((int*)&b1));
//	int a = 0;
//	static int b = 0;
//	int* p = new int;
//	const char* str = "hello world";
//	printf("栈：%p\n", &a);
//	printf("数据段(静态区)：%p\n", &b);
//	printf("堆：%p\n", p);
//	printf("代码段(常量区)：%p\n", str);
//
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//int main()
//{
//	//Benz b;
//	//Car c;
//	/*Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();*/
//	Benz bz;
//	BMW bw;
//	Car* p;
//	p = &bz;
//	p->Drive();
//
//	p = &bw;
//	p->Drive();
//
//	return 0;
//}

//class Car {
//public:
//	void Drive() {}
//};
//
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};

//class Car final
//{
//public:
//	virtual void Drive()  {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};