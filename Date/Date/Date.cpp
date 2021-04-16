#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"

int main()
{
	Date d1(2021, 2, 3);
	d1++;
	++d1;
	Date ret = d1 + (-100);
	ret.Print();
	//d1.Print();

	/*d1 += 100;*/
	//Date d2(2021, 2, 29);

	return 0;
}