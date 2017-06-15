//bigInteger.cpp

#include<iostream>
#include<string>
#include"bigInteger.h"

using namespace std;

//add
linkedList bigInteger::add(const linkedList &left,const linkedList &right)
{
	linkedList tmp;//新建一个空链表
	int tempNum,rest=0;//tempNum是每一位的结果，rest是进位的数值
	node *n1=left.last;
	node *n2=right.last;
	//两数一样长
	while(n1&&n2)
	{
		//临时数等于上下相加再加进位的值
		tempNum=n1->data+n2->data+rest;
		if(tempNum>9)
		{
			tempNum=tempNum-10;
			rest=1;
		}
		else
			rest=0;
		tmp.push_front(tempNum);
		n1=n1->pre;
		n2=n2->pre;
	}
	//下面的数比上面短
	while(n1)
	{
		//临时数等于上面的数再加进位的值
		tempNum=n1->data+rest;
		if(tempNum>9)
		{
			tempNum=tempNum-10;
			rest=1;
		}
		else
			rest=0;
		tmp.push_front(tempNum);
		n1=n1->pre;
	}
	//上面的数比下面短
	while(n2)
	{
		//临时数等于下面的数再加进位的值
		tempNum=n2->data+rest;
		if(tempNum>9)
		{
			tempNum=tempNum-10;
			rest=1;
		}
		else
			rest=0;
		tmp.push_front(tempNum);
		n2=n2->pre;
	}
	//如果最后一次进位了，前面加1
	if(rest)
		tmp.push_front(1);
	return tmp;
}

//比大小：1是前面大，2是后面大，0是一样大
int bigInteger::isLarge(const linkedList &left,const linkedList &right)
{
	//先按长度比较大小
	if(left.size>right.size)
		return 1;
	else if(left.size<right.size)
		return 2;
	//如果长度相等，从前往后推，直到遇到小于的情况跳出
	node *p1=left.first;
	node *p2=right.first;
	for(int i=0;i<left.size;i++)
	{
		if(p1->data>p2->data)
		{
			return 1;
		}
		else if(p1->data<p2->data)
		{
			return 2;
		}
		p1=p1->next;
		p2=p2->next;
	}
	return 0;
}

//subtract
linkedList bigInteger::subtract(const linkedList &left,const linkedList &right)
{
	linkedList tmp;//新建一个空链表
	int tempNum,rest=0;//tempNum是每一位的结果，rest是进位的数值
	node *n1=left.last;
	node *n2=right.last;
	int whoLarge=isLarge(left,right);

	//一样大，结果为0
	if(whoLarge==0)
		tmp.push_front(0);

	//上面的数大
	if(whoLarge==1)
	{
		//上下的数都有
		while(n1&&n2)
		{
			//临时数等于上减下再加借位的值
			tempNum=n1->data-n2->data+rest;
			if(tempNum<0)
			{
				tempNum=tempNum+10;
				rest=-1;
			}
			else
				rest=0;
			tmp.push_front(tempNum);
			n1=n1->pre;
			n2=n2->pre;
		}
		//下面的数没了
		while(n1)
		{
			//临时数等于上加借位的值
			tempNum=n1->data+rest;
			if(tempNum<0)
			{
				tempNum=tempNum+10;
				rest=-1;
			}
			else
				rest=0;
			tmp.push_front(tempNum);
			n1=n1->pre;
		}
	}
	//后者大
	else if(whoLarge==2)
	{
		tmp.isMinus=true;
		//上下的数都有
		while(n2&&n1)
		{
			//临时数等于下减上再加借位的值
			tempNum=n2->data-n1->data+rest;
			if(tempNum<0)
			{
				tempNum=tempNum+10;
				rest=-1;
			}
			else
				rest=0;
			tmp.push_front(tempNum);
			n1=n1->pre;
			n2=n2->pre;
		}
		//上面的数没了
		while(n2)
		{
			//临时数等于下加借位的值
			tempNum=n2->data+rest;
			if(tempNum<0)
			{
				tempNum=tempNum+10;
				rest=-1;
			}
			else
				rest=0;
			tmp.push_front(tempNum);
			n2=n2->pre;
		}
	}
	//去掉前面的0
	while(tmp.first->data==0)
	{
		//最后要保留一个零
		if(tmp.size==1)
			break;

		node *temp=tmp.first;
		tmp.first=tmp.first->next;
		delete temp;
		tmp.size--;
	}
	return tmp;
}

//multiply
linkedList bigInteger::multiply(const linkedList &left,const linkedList &right)
{
	linkedList tmp;//新建一个空链表
	int tempNum=0,rest=0;//tempNum是每一位的结果，rest是进位的数值
	node *n1=left.last;
	node *n2=right.last;
	node *result=0;
	node *tempResult=0;
	bool isTmpEmpty=true;//哨兵
	//两个数中有一个是0的情况
	if(left.size==1&&n1->data==0||right.size==1&&n2->data==0)
	{
		tmp.push_front(0);
		return tmp;
	}
	//两个数中有一个是1的情况
	else if(left.size==1&&n1->data==1||right.size==1&&n2->data==1)
	{
		if(n1->data==1)
			tmp=right;
		else
			tmp=left;
		return tmp;
	}
	else if(left.size>=right.size)
	{
		//先求卷积的结果
		while(n2)
		{
			tempResult=result;
			//记录tempResult相对于result向前跳的次数
			int flag=0;
			while(n1)
			{
				flag++;
				//临时数等于两位的相乘
				tempNum=n2->data*n1->data;
				if(tempResult!=0)
				{
					//临时数等于原有的值加上新乘出来的值
					tempNum=tempResult->data+tempNum;
					tempResult->data=tempNum;
					tempResult=tempResult->pre;
					n1=n1->pre;
				}
				else
				{
					tmp.push_front(tempNum);
					if(isTmpEmpty)
					{
						result=tmp.last;
						tempResult=result;
						isTmpEmpty=false;
					}
					n1=n1->pre;
					for(int i=0;i<flag;i++)
					{
						if(i==0)
							tempResult=result->pre;
						else
							tempResult=tempResult->pre;
					}
				}
			}
			n1=left.last;
			result=result->pre;
			n2=n2->pre;
		}
	}
	else
	{
		//先求卷积的结果
		while(n1)
		{
			tempResult=result;
			//记录tempResult相对于result向前跳的次数
			int flag=0;
			while(n2)
			{
				flag++;
				//临时数等于两位的相乘
				tempNum=n1->data*n2->data;
				if(tempResult!=0)
				{
					//临时数等于原有的值加上新乘出来的值
					tempNum=tempResult->data+tempNum;
					tempResult->data=tempNum;
					tempResult=tempResult->pre;
					n2=n2->pre;
				}
				else
				{
					tmp.push_front(tempNum);
					if(isTmpEmpty)
					{
						result=tmp.last;
						tempResult=result;
						isTmpEmpty=false;
					}
					n2=n2->pre;
					for(int i=0;i<flag;i++)
					{
						if(i==0)
							tempResult=result->pre;
						else
							tempResult=tempResult->pre;
					}
				}
			}
			n2=left.last;
			result=result->pre;
			n1=n1->pre;
		}
	}
	//使卷积化的链表规范化
	node *p=tmp.last;
	while(p)
	{
		tempNum=p->data+rest;
		if(tempNum>9)
		{
			rest=tempNum/10;
			tempNum=tempNum%10;
		}
		else
			rest=0;
		p->data=tempNum;
		p=p->pre;
	}
	if(rest!=0)
		tmp.push_front(rest);
	return tmp;
}

//divide
linkedList bigInteger::divide(const linkedList &left,const linkedList &right)
{
	linkedList quotient;//商
	linkedList remainder;//余数
	int whoLarge=isLarge(left,right);//比大小

	//一样大，结果为1
	if(whoLarge==0)
	{
		quotient.push_front(1);
		remainder.push_front(0);
		return quotient;//mod则return remainder;
	}
	//后者大，结果为0
	else if(whoLarge==2)
	{
		quotient.push_front(0);
		remainder=left;
		return quotient;//mod则return remainder;
	}
	//除数是1
	else if(right.size==1&&right.first->data==1)
	{
		quotient=left;
		remainder.push_front(0);
		return quotient;//mod则return remainder;
	}
	//普通情况
	else
	{
		node *p=0;
		//截取被除数中少于除数1位的链表作为起始的余数
		if(right.size-1!=0)
		{
			remainder.create(right.size-1);
			node *p1=remainder.first;
			node *p2=left.first;

			//循环赋值
			for(int i=0;i<right.size-1;i++)
			{
				p1->data=p2->data;
				p1=p1->next;
				p2=p2->next;
			}
		}

		node *tmp=left.first;

		//tmp跳到下一位准备运算
		for(int j=0;j<right.size-1;j++)
			tmp=tmp->next;

		for(int i=right.size-1;i<left.size;i++)
		{
			p=remainder.first;

			//相减之后差为0,将0后的数代替0
			if(p!=0&&p->data==0)
			{
				node *change=remainder.first;
				change->data=tmp->data;
			}
			//继续插入下一位数
			else
				remainder.push_back(tmp->data);

			//一位一位的计算商
			int tmpQuotient;
			for(tmpQuotient=0;whoLarge=isLarge(remainder,right)!=2;tmpQuotient++)
				remainder=subtract(remainder,right);

			tmp=tmp->next;

			//将循环次数作为商放进结果
			quotient.push_back(tmpQuotient);
		}
		//去掉每次的余数前面的0（针对上次计算后余数为0的情况）
		if(quotient.first->data==0)
		{
			node *temp=quotient.first;
			quotient.first=quotient.first->next;
			delete temp;
			quotient.size--;
		}
		return quotient;//mod则return remainder;
	}
}

//mod
linkedList bigInteger::mod(const linkedList &left,const linkedList &right)
{
	linkedList quotient;//商
	linkedList remainder;//余数
	int whoLarge=isLarge(left,right);//比大小

	//一样大，结果为1
	if(whoLarge==0)
	{
		quotient.push_front(1);
		remainder.push_front(0);
		return remainder;//mod则return remainder;
	}
	//后者大，结果为0
	else if(whoLarge==2)
	{
		quotient.push_front(0);
		remainder=left;
		return remainder;//mod则return remainder;
	}
	//除数是1
	else if(right.size==1&&right.first->data==1)
	{
		quotient=left;
		remainder.push_back(0);
		return remainder;//mod则return remainder;
	}
	//普通情况
	else
	{
		node *p=0;
		//截取被除数中少于除数1位的链表作为起始的余数
		if(right.size-1!=0)
		{
			remainder.create(right.size-1);
			node *p1=remainder.first;
			node *p2=left.first;

			//循环赋值
			for(int i=0;i<right.size-1;i++)
			{
				p1->data=p2->data;
				p1=p1->next;
				p2=p2->next;
			}
		}

		node *tmp=left.first;

		//tmp跳到下一位准备运算
		for(int j=0;j<right.size-1;j++)
			tmp=tmp->next;

		for(int i=right.size-1;i<left.size;i++)
		{
				p=remainder.first;

			//相减之后差为0,将0后的数代替0
			if(p!=0&&p->data==0)
			{
				node *change=remainder.first;
				change->data=tmp->data;
			}
			//继续插入下一位数
			else
				remainder.push_back(tmp->data);

			//一位一位的计算商
			int tmpQuotient;
			for(tmpQuotient=0;whoLarge=isLarge(remainder,right)!=2;tmpQuotient++)
				remainder=subtract(remainder,right);

			tmp=tmp->next;

			//将循环次数作为商放进结果
			quotient.push_back(tmpQuotient);
		}
		//去掉每次的余数前面的0（针对上次计算后余数为0的情况）
		if(quotient.first->data==0)
		{
			node *temp=quotient.first;
			quotient.first=quotient.first->next;
			delete temp;
			quotient.size--;
		}
		return remainder;//mod则return remainder;
	}
}

//power
linkedList bigInteger::power(const linkedList &left,const linkedList &right)
{
	linkedList tmp;

	//底数是1或者0
	if(left.size==1&&(left.last->data==1||left.last->data==0))
	{
		//1
		if(left.last->data==1)
			tmp.push_front(1);
		//0
		else
			tmp.push_front(0);
		return tmp;
	}
	//指数为1或者0
	else if(right.size==1&&(right.last->data==1||right.last->data==0))
	{
		//指数为1
		if(right.last->data==1)
		{
			linkedList temp(left);
			return temp;
		}
		//指数为0
		else
		{
			tmp.push_front(1);
			return tmp;
		}
	}
	else
	{
		linkedList zero,one;
		zero.push_front(0);
		one.push_front(1);
		linkedList tmpResult;
		tmpResult.push_front(1);
		/*
		*下面的循环是根据普通的指数运算改成的
		*假设计算a^b;
		*int tmpResult=1;
		*for(int i=次数;i>0;i--)
		*	tmpResult=tmpResult*a;
		*/
		for(linkedList exponent(right);isLarge(exponent,zero)==1;exponent=subtract(exponent,one))
			tmpResult=multiply(tmpResult,left);
		return tmpResult;
	}
}
