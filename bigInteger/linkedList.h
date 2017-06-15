//linkedList.h

#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

#include<string>

using namespace std;

//节点类
class node
{
public:
	int data;
	node *next,*pre;
	node():next(0),pre(0){}
	node(const int &item,node *nextnode=0,node *prenode=0):data(item),next(nextnode),pre(prenode){}
};

//链表类：存储数据
class linkedList
{
public:
	//默认构造函数
	linkedList();

	//构造函数
	linkedList(string &s);

	//创建指定长度的链表
	void create(int lsize);

	//拷贝构造函数
	linkedList(const linkedList &l);

	//重载=
	linkedList& operator=(const linkedList& rhs);

	//析构函数：释放动态申请的空间
	~linkedList();

	//清空链表
	void clear();

	//输出链表函数
	void display();

	//导出链表
	void savetxt(const string &path);

	//在头部添加一个元素
	void push_front(const int &item);

	//在尾部添加一个元素
	void push_back(const int &item);

	friend class bigInteger;
	bool isMinus;//是否为负数
	int size;//链表长度
	node *first;//头指针
	node *last;//尾指针
};

#endif