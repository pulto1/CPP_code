#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	// 各种开后门特例，本质都是为了析构函数构成重写
	// 因为如果不构成重写，特殊情况下，可能会存在内存泄露
	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person {
public:
	~Student() { cout << "~Student()" << endl; }
};

int main()
{
	//Person p;
	//Student s;
	Person* p1 = new Person;
	delete p1;

	Person* p2 = new Student;
	delete p2;

	return 0;
}

//class Person
//{
//public:
//	// 重写的-协变
//	virtual void BuyTicket()
//	{
//		cout << "正常排队-全价格买票" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	// 重写
//	 virtual void BuyTicket()
//	{
//		cout << "正常排队-半价格买票" << endl;
//	}
//};
//
//// 多态的条件-》满多态，指向谁调用谁的虚函数
//// 1、继承类中，虚函数的重写 
//// 2、基类指针或者引用去调用这个虚函数
////		重写的条件：
////			a、父子类中的函数都是虚函数
////			b、函数名、参数、返回值都要相同
//void Buy(Person& p)
//{
//	// 不满足多态：跟类型有关，也就是说p是什么类型，就掉的这个类型的成员函数
//	// 满足多态：跟对象有关，也就是指向的是哪个对象，调用就是那个的虚函数
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Buy(ps);
//
//	Student st;
//	Buy(st);
//
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	A a;
//	a._a = 6;
//
//	B b;
//	b._a = 7;
//
//	/*D d;
//	cout << sizeof(d) << endl;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;*/
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	//a.Student::_name = "xxx";
//	//a.Teacher::_name = "yyy";
//
//	return 0;
//}