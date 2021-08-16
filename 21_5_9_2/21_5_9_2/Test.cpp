//#include <iostream>
//
//using namespace std;
//
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	cout << "虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf("第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	//cout << sizeof(Derive) << endl;
//
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//
//	printf("Derive::func1地址：%p\n", &Derive::func1);
//	cout << endl;
//
//	p1->func1();
//	p2->func1();
//
//	PrintVTable((VFPTR*)(*(int*)&d));
//	cout << endl << endl;
//	PrintVTable((VFPTR*)(*(int*)((char*)&d + sizeof(Base1)))); //打印第二个父类虚表的内容
//	
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A {
//public:
//	A(const char* s) { cout << s << endl; }
//	~A() {}
//};
//class B :virtual public A
//{
//public:
//	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class C :virtual public A
//{
//public:
//	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class D :public B, public C
//{
//public:
//	D(const char* s1, const char* s2, const char* s3, const char* s4) :B(s1, s2), C(s1, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}

class A
{
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); }
};

class B : public A
{
public:
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};

int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();
	return 0;
}