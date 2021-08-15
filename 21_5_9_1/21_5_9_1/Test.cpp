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

typedef void(*VFUNC)(); //�ض��庯��ָ��

void PrintVFT(VFUNC* vftable) //�β�Ϊ����ָ���������Ԫ�ص�ַ
{
	printf("���ָ�룺%p\n", vftable);
	for (int i = 0; vftable[i] != nullptr; ++i)
	{
		printf("vftale[%d]:%p->", i, vftable[i]);
		VFUNC f = vftable[i]; //����ָ��ָ��ĺ���
		f();
		//(*f)();
	}
}

int main()
{
	Base b;
	Derive d;

	PrintVFT((VFUNC*)(*((int*)&d))); //���Σ����������Ǻ���ָ�������ָ��
	cout << endl << endl;

	PrintVFT((VFUNC*)(*((int*)&b)));


	return 0;
}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//	printf("���ָ�룺%p\n", *((int*)&b1));
//	int a = 0;
//	static int b = 0;
//	int* p = new int;
//	const char* str = "hello world";
//	printf("ջ��%p\n", &a);
//	printf("���ݶ�(��̬��)��%p\n", &b);
//	printf("�ѣ�%p\n", p);
//	printf("�����(������)��%p\n", str);
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
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
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
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//};

//class Car final
//{
//public:
//	virtual void Drive()  {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};