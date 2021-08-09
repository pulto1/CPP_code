#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};

int Person::_count = 0; //初始化静态变量，静态成员变量只能在类外初始化
class Student : public Person
{
protected:
	int _stuNum; // 学号
};

class Graduate : public Student
{
protected:
	string _seminarCourse; // 研究科目
};

int main()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;

	return 0;
}

//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	// 继承下来的父类部分的成员，要使用父类的构造函数去初始化
//	// 不能自己显示的去初始化
//	/*Student(const char* name = "小明", int num = 1)
//		:_name(name)
//		, _num(num)
//	{}*/
//
//	Student(const char* name = "小明", int num = 1)
//		:Person(name)
//		,_num(num)
//	{}
//
//	Student(const Student& s)
//		:Person(s)
//		, _num(s._num)
//	{}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = s._num;
//		}
//
//		return *this;
//	}
//
//	// 两个迷惑点：
//	// 1、子类的析构函数和父类的析构函数构成隐藏 
//	// -> 由于以后多态重写的需要（什么需要 后面讲）
//	// ，所有类的析构函数，名字会被统一处理成destructor
//	// 2、自己显示调用，存在父类先析构的问题，不符合规则
//	~Student()
//	{
//		Person::~Person();
//		/*delete _ptr;*/
//	}
//
//protected:
//	int _num; //学号
//};
//
//int main()
//{
//	Student s1;
//	//Student s2(s1);
//
//	//Student s3("唐三", 18);
//	//s1 = s3;
//
//
//	return 0;
//}

//// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
//// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	//b.fun(10);
//	b.A::fun();
//
//	return 0;
//};

//class Person
//{
//public:
//	string _name = "小明"; // 姓名
//	string _sex = "男"; // 性别
//	int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//void Test()
//{
//	Student sobj;
//
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	//2.基类对象不能赋值给派生类对象（错误示范）
//	sobj = pobj;
//
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &sobj; //原本就是子类指针
//	Student * ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//	
//	pp = &pobj; //原本是父类指针
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//
//// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和
//// Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。
//// 调用Print可以看到成员函数的复用。
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		cout << _name << endl; // 不可见
//		cout << _age << endl;  // protected
//	}
//protected:
//	int _stuid = 123456; // 学号
//};
//
////class Teacher : public Person
////{
////protected:
////	int _jobid; // 工号
////};
//
//int main()
//{
//	Student s;
//	s.func();
//	//Teacher t;
//	/*s.Print();*/
//	//t.Print();
//	return 0;
//}