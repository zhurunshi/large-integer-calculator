//bigInteger.cpp

#include<iostream>
#include<string>
#include"bigInteger.h"

using namespace std;

//add
linkedList bigInteger::add(const linkedList &left,const linkedList &right)
{
	linkedList tmp;//�½�һ��������
	int tempNum,rest=0;//tempNum��ÿһλ�Ľ����rest�ǽ�λ����ֵ
	node *n1=left.last;
	node *n2=right.last;
	//����һ����
	while(n1&&n2)
	{
		//��ʱ��������������ټӽ�λ��ֵ
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
	//��������������
	while(n1)
	{
		//��ʱ��������������ټӽ�λ��ֵ
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
	//��������������
	while(n2)
	{
		//��ʱ��������������ټӽ�λ��ֵ
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
	//������һ�ν�λ�ˣ�ǰ���1
	if(rest)
		tmp.push_front(1);
	return tmp;
}

//�ȴ�С��1��ǰ���2�Ǻ����0��һ����
int bigInteger::isLarge(const linkedList &left,const linkedList &right)
{
	//�Ȱ����ȱȽϴ�С
	if(left.size>right.size)
		return 1;
	else if(left.size<right.size)
		return 2;
	//���������ȣ���ǰ�����ƣ�ֱ������С�ڵ��������
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
	linkedList tmp;//�½�һ��������
	int tempNum,rest=0;//tempNum��ÿһλ�Ľ����rest�ǽ�λ����ֵ
	node *n1=left.last;
	node *n2=right.last;
	int whoLarge=isLarge(left,right);

	//һ���󣬽��Ϊ0
	if(whoLarge==0)
		tmp.push_front(0);

	//���������
	if(whoLarge==1)
	{
		//���µ�������
		while(n1&&n2)
		{
			//��ʱ�������ϼ����ټӽ�λ��ֵ
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
		//�������û��
		while(n1)
		{
			//��ʱ�������ϼӽ�λ��ֵ
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
	//���ߴ�
	else if(whoLarge==2)
	{
		tmp.isMinus=true;
		//���µ�������
		while(n2&&n1)
		{
			//��ʱ�������¼����ټӽ�λ��ֵ
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
		//�������û��
		while(n2)
		{
			//��ʱ�������¼ӽ�λ��ֵ
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
	//ȥ��ǰ���0
	while(tmp.first->data==0)
	{
		//���Ҫ����һ����
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
	linkedList tmp;//�½�һ��������
	int tempNum=0,rest=0;//tempNum��ÿһλ�Ľ����rest�ǽ�λ����ֵ
	node *n1=left.last;
	node *n2=right.last;
	node *result=0;
	node *tempResult=0;
	bool isTmpEmpty=true;//�ڱ�
	//����������һ����0�����
	if(left.size==1&&n1->data==0||right.size==1&&n2->data==0)
	{
		tmp.push_front(0);
		return tmp;
	}
	//����������һ����1�����
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
		//�������Ľ��
		while(n2)
		{
			tempResult=result;
			//��¼tempResult�����result��ǰ���Ĵ���
			int flag=0;
			while(n1)
			{
				flag++;
				//��ʱ��������λ�����
				tempNum=n2->data*n1->data;
				if(tempResult!=0)
				{
					//��ʱ������ԭ�е�ֵ�����³˳�����ֵ
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
		//�������Ľ��
		while(n1)
		{
			tempResult=result;
			//��¼tempResult�����result��ǰ���Ĵ���
			int flag=0;
			while(n2)
			{
				flag++;
				//��ʱ��������λ�����
				tempNum=n1->data*n2->data;
				if(tempResult!=0)
				{
					//��ʱ������ԭ�е�ֵ�����³˳�����ֵ
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
	//ʹ�����������淶��
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
	linkedList quotient;//��
	linkedList remainder;//����
	int whoLarge=isLarge(left,right);//�ȴ�С

	//һ���󣬽��Ϊ1
	if(whoLarge==0)
	{
		quotient.push_front(1);
		remainder.push_front(0);
		return quotient;//mod��return remainder;
	}
	//���ߴ󣬽��Ϊ0
	else if(whoLarge==2)
	{
		quotient.push_front(0);
		remainder=left;
		return quotient;//mod��return remainder;
	}
	//������1
	else if(right.size==1&&right.first->data==1)
	{
		quotient=left;
		remainder.push_front(0);
		return quotient;//mod��return remainder;
	}
	//��ͨ���
	else
	{
		node *p=0;
		//��ȡ�����������ڳ���1λ��������Ϊ��ʼ������
		if(right.size-1!=0)
		{
			remainder.create(right.size-1);
			node *p1=remainder.first;
			node *p2=left.first;

			//ѭ����ֵ
			for(int i=0;i<right.size-1;i++)
			{
				p1->data=p2->data;
				p1=p1->next;
				p2=p2->next;
			}
		}

		node *tmp=left.first;

		//tmp������һλ׼������
		for(int j=0;j<right.size-1;j++)
			tmp=tmp->next;

		for(int i=right.size-1;i<left.size;i++)
		{
			p=remainder.first;

			//���֮���Ϊ0,��0���������0
			if(p!=0&&p->data==0)
			{
				node *change=remainder.first;
				change->data=tmp->data;
			}
			//����������һλ��
			else
				remainder.push_back(tmp->data);

			//һλһλ�ļ�����
			int tmpQuotient;
			for(tmpQuotient=0;whoLarge=isLarge(remainder,right)!=2;tmpQuotient++)
				remainder=subtract(remainder,right);

			tmp=tmp->next;

			//��ѭ��������Ϊ�̷Ž����
			quotient.push_back(tmpQuotient);
		}
		//ȥ��ÿ�ε�����ǰ���0������ϴμ��������Ϊ0�������
		if(quotient.first->data==0)
		{
			node *temp=quotient.first;
			quotient.first=quotient.first->next;
			delete temp;
			quotient.size--;
		}
		return quotient;//mod��return remainder;
	}
}

//mod
linkedList bigInteger::mod(const linkedList &left,const linkedList &right)
{
	linkedList quotient;//��
	linkedList remainder;//����
	int whoLarge=isLarge(left,right);//�ȴ�С

	//һ���󣬽��Ϊ1
	if(whoLarge==0)
	{
		quotient.push_front(1);
		remainder.push_front(0);
		return remainder;//mod��return remainder;
	}
	//���ߴ󣬽��Ϊ0
	else if(whoLarge==2)
	{
		quotient.push_front(0);
		remainder=left;
		return remainder;//mod��return remainder;
	}
	//������1
	else if(right.size==1&&right.first->data==1)
	{
		quotient=left;
		remainder.push_back(0);
		return remainder;//mod��return remainder;
	}
	//��ͨ���
	else
	{
		node *p=0;
		//��ȡ�����������ڳ���1λ��������Ϊ��ʼ������
		if(right.size-1!=0)
		{
			remainder.create(right.size-1);
			node *p1=remainder.first;
			node *p2=left.first;

			//ѭ����ֵ
			for(int i=0;i<right.size-1;i++)
			{
				p1->data=p2->data;
				p1=p1->next;
				p2=p2->next;
			}
		}

		node *tmp=left.first;

		//tmp������һλ׼������
		for(int j=0;j<right.size-1;j++)
			tmp=tmp->next;

		for(int i=right.size-1;i<left.size;i++)
		{
				p=remainder.first;

			//���֮���Ϊ0,��0���������0
			if(p!=0&&p->data==0)
			{
				node *change=remainder.first;
				change->data=tmp->data;
			}
			//����������һλ��
			else
				remainder.push_back(tmp->data);

			//һλһλ�ļ�����
			int tmpQuotient;
			for(tmpQuotient=0;whoLarge=isLarge(remainder,right)!=2;tmpQuotient++)
				remainder=subtract(remainder,right);

			tmp=tmp->next;

			//��ѭ��������Ϊ�̷Ž����
			quotient.push_back(tmpQuotient);
		}
		//ȥ��ÿ�ε�����ǰ���0������ϴμ��������Ϊ0�������
		if(quotient.first->data==0)
		{
			node *temp=quotient.first;
			quotient.first=quotient.first->next;
			delete temp;
			quotient.size--;
		}
		return remainder;//mod��return remainder;
	}
}

//power
linkedList bigInteger::power(const linkedList &left,const linkedList &right)
{
	linkedList tmp;

	//������1����0
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
	//ָ��Ϊ1����0
	else if(right.size==1&&(right.last->data==1||right.last->data==0))
	{
		//ָ��Ϊ1
		if(right.last->data==1)
		{
			linkedList temp(left);
			return temp;
		}
		//ָ��Ϊ0
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
		*�����ѭ���Ǹ�����ͨ��ָ������ĳɵ�
		*�������a^b;
		*int tmpResult=1;
		*for(int i=����;i>0;i--)
		*	tmpResult=tmpResult*a;
		*/
		for(linkedList exponent(right);isLarge(exponent,zero)==1;exponent=subtract(exponent,one))
			tmpResult=multiply(tmpResult,left);
		return tmpResult;
	}
}
