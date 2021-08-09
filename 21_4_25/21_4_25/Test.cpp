#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};

int Person::_count = 0; //��ʼ����̬��������̬��Ա����ֻ���������ʼ��
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};

class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};

int main()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;

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
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	// �̳������ĸ��ಿ�ֵĳ�Ա��Ҫʹ�ø���Ĺ��캯��ȥ��ʼ��
//	// �����Լ���ʾ��ȥ��ʼ��
//	/*Student(const char* name = "С��", int num = 1)
//		:_name(name)
//		, _num(num)
//	{}*/
//
//	Student(const char* name = "С��", int num = 1)
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
//	// �����Ի�㣺
//	// 1����������������͸�������������������� 
//	// -> �����Ժ��̬��д����Ҫ��ʲô��Ҫ ���潲��
//	// ����������������������ֻᱻͳһ�����destructor
//	// 2���Լ���ʾ���ã����ڸ��������������⣬�����Ϲ���
//	~Student()
//	{
//		Person::~Person();
//		/*delete _ptr;*/
//	}
//
//protected:
//	int _num; //ѧ��
//};
//
//int main()
//{
//	Student s1;
//	//Student s2(s1);
//
//	//Student s3("����", 18);
//	//s1 = s3;
//
//
//	return 0;
//}

//// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
//// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
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
//	string _name = "С��"; // ����
//	string _sex = "��"; // �Ա�
//	int _age = 18; // ����
//};
//
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//void Test()
//{
//	Student sobj;
//
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	//2.��������ܸ�ֵ����������󣨴���ʾ����
//	sobj = pobj;
//
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	pp = &sobj; //ԭ����������ָ��
//	Student * ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//	ps1->_No = 10;
//	
//	pp = &pobj; //ԭ���Ǹ���ָ��
//	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
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
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//
//// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��
//// Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�
//// ����Print���Կ�����Ա�����ĸ��á�
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		cout << _name << endl; // ���ɼ�
//		cout << _age << endl;  // protected
//	}
//protected:
//	int _stuid = 123456; // ѧ��
//};
//
////class Teacher : public Person
////{
////protected:
////	int _jobid; // ����
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