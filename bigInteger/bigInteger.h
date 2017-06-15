//bigInteger.h

#ifndef BIGINTEGER_HEADER
#define BIGINTEGER_HEADER

#include<string>
#include"linkedList.h"

using namespace std;

//�������ࣺ����
class bigInteger
{
public:
	//add
	linkedList add(const linkedList &left,const linkedList &right);

	//subtract
	linkedList subtract(const linkedList &left,const linkedList &right);

	//�ȴ�С��1��ǰ���2�Ǻ����0��һ����
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