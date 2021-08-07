#include "Template.hpp"

template<class T>
void TFunc(const T& a)
{
	cout << "TFunc->" << a << endl;
}

// 显示实例化--解决方案一
template
void TFunc<int>(const int& a);

//template
//void TFunc<double>(const double& a);