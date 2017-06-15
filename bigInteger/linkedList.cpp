//linkedList.cpp

#include<iostream>
#include<string>
#include<fstream>
#include"linkedList.h"

using namespace std;

//重载默认构造函数
linkedList::linkedList()
{
	size=0;
	isMinus=false;
	first=last=0;
}

//创建指定长度的链表，并初始化为0
void linkedList::create(int lsize)
{
	size=lsize;
	isMinus=false;
	for(int i=0;i<size;i++)
	{
		if(i==0)
		{
			first=new node(0,0,0);
			last=first;
		}
		else
		{
			node *temp=new node(0,0,0);
			temp->pre=last;
			last->next=temp;
			last=last->next;
		}
	}
}

//构造函数
linkedList::linkedList(string &s)
{
	isMinus=false;
	//去掉前面的0	
	if(s[0]=='0')
	{
		//开头最后一个0的下标
		int num=s.length()-1;
		for(int i=1;i<s.length()-1;i++)
		{
			if(s[i]!='0')
			{
				num=i;
				break;
			}			
		}
		s=s.substr(num,s.length()-num);
	}
	
	//链表长度与字符串长度相同
	size=s.length();
	for(int i=0;i<size;i++)
	{
		if(i==0)
		{
			first=new node(s[i]-'0',0,0);
			last=first;
		}
		else
		{
			node *temp=new node(s[i]-'0',0,0);
			temp->pre=last;
			last->next=temp;
			last=last->next;
		}
	}
}

//析构函数：释放动态申请的空间
linkedList::~linkedList()
{
	while(first!=0)
	{
		node *temp=first;
		first=first->next;
		delete temp;
	}
}

//清空
void linkedList::clear()
{
	while(first!=0)
	{
		node *temp=first;
		first=first->next;
		delete temp;
	}
}

//拷贝构造函数
linkedList::linkedList(const linkedList &l)
{
	isMinus=l.isMinus;
	//给空链表拷贝一个空链表
	if(l.first==0)
	{
		first=0;
		size=0;
	}
	else
	{
		last=0;
		node *temp=l.first;
		int i;
		for(i=0;temp!=0;i++)
		{
			if(i==0)
			{
				first=new node(temp->data,0);
				last=first;
				temp=temp->next;
			}
			else
			{
				node *tmp=new node(temp->data,0);
				tmp->pre=last;
				last->next=tmp;
				last=last->next;
				temp=temp->next;
			}
		}
		size=i;
	}
}

//重载=
linkedList& linkedList::operator=(const linkedList& rhs)
{
	if(this==&rhs)
		return *this;
	clear();
	isMinus=rhs.isMinus;
	//给空链表拷贝一个空链表
	if(rhs.first==0)
	{
		first=0;
		size=0;
	}
	else
	{
		last=0;
		node *temp=rhs.first;
		int i;
		for(i=0;temp!=0;i++)
		{
			if(i==0)
			{
				first=new node(temp->data,0);
				last=first;
				temp=temp->next;
			}
			else
			{
				node *tmp=new node(temp->data,0);
				tmp->pre=last;
				last->next=tmp;
				last=last->next;
				temp=temp->next;
			}
		}
		size=i;
	}
	return *this;
}

//输出链表函数
void linkedList::display()
{
	if(isMinus)
		cout<<'-';
	int reminder=size%3;
	node *temp=first;
	if(reminder==0)
	{
		for(int j=1;j<=size-1;j++)
		{
			cout<<temp->data;
			temp=temp->next;
			if(j%3==0)
				cout<<',';
		}
		cout<<temp->data;
		cout<<endl;
		cout<<"共计 "<<size<<" 位。"<<endl;
	}
	else
	{
		for(int i=0;i<size-1;i++)
		{
			cout<<temp->data;
			temp=temp->next;
			if(i==reminder-1)
			{
				cout<<',';
				reminder+=3;
			}
		}
		cout<<temp->data;
		cout<<endl;
		cout<<"共计 "<<size<<" 位。"<<endl;
	}
}

//导出链表
void linkedList::savetxt(const string &path)
{
	ofstream fout;
	fout.open(path.c_str());
	if(isMinus)
		fout<<'-';
	int reminder=size%3;
	node *temp=first;
	if(reminder==0)
	{
		for(int j=1;j<=size-1;j++)
		{
			fout<<temp->data;
			temp=temp->next;
			if(j%3==0)
				fout<<',';
		}
		fout<<temp->data;
		fout<<endl;
		fout<<"共计 "<<size<<" 位。"<<endl;
	}
	else
	{
		for(int i=0;i<size-1;i++)
		{
			fout<<temp->data;
			temp=temp->next;
			if(i==reminder-1)
			{
				fout<<',';
				reminder+=3;
			}
		}
		fout<<temp->data;
		fout<<endl;
		fout<<"共计 "<<size<<" 位。"<<endl;
	}
	fout.close();
}

//在头部添加一个元素
void linkedList::push_front(const int &item)
{
	node *p=0;
	node *tmp=0;
    p=new node(item,0,0);
	//如果是空链表
    if(first==0)
    {
		p->next=0;
		p->pre=0;
		last=p;
		first=p;
    }
	//非空链表，则把旧元素的pre指向p,并将p的next指向原来的头元素
    else
    {
		tmp=first;
		first=p;
		p->next=tmp;
		tmp->pre=p;
		p->pre=0;
    }
	size++;
}

//在尾部添加一个元素
void linkedList::push_back(const int &item)
{
	node *p=0;
	node *tmp=0;
	p=new node(item,0,0);
	//如果是空链表
	if(first==0)
	{
		p->next=0;
		p->pre=0;
		last=p;
		first=p;
	}
	else
	{
		tmp=last;
		last=p;
		p->next=0;
		tmp->next=p;
		p->pre=tmp;
	}
	size++;
}