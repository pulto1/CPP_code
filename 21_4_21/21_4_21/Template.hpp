#pragma once
#include <iostream>
using namespace std;

template<class T>
void TFunc(const T& a);

// 声明和定义放在一个问津--解决方案二  推荐
//template<class T>
//void TFunc(const T& a)
//{
//	cout << "TFunc->" << a << endl;
//}