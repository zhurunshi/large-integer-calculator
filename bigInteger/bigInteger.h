//bigInteger.h

#ifndef BIGINTEGER_HEADER
#define BIGINTEGER_HEADER

#include<string>
#include"linkedList.h"

using namespace std;

//大整数类：运算
class bigInteger
{
public:
	//add
	linkedList add(const linkedList &left,const linkedList &right);

	//subtract
	linkedList subtract(const linkedList &left,const linkedList &right);

	//比大小：1是前面大，2是后面大，0是一样大
	int isLarge(const linkedList &left,const linkedList &right);

	//multiply
	linkedList multiply(const linkedList &left,const linkedList &right);

	//divide
	linkedList divide(const linkedList &left,const linkedList &right);

	//mod
	linkedList mod(const linkedList &left,const linkedList &right);

	//power
	linkedList power(const linkedList &left,const linkedList &right);
};

#endif