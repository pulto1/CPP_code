#include "Template.hpp"

template<class T>
void TFunc(const T& a)
{
	cout << "TFunc->" << a << endl;
}

// ��ʾʵ����--�������һ
template
void TFunc<int>(const int& a);

//template
//void TFunc<double>(const double& a);