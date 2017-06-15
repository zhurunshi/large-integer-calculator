//linkedList.h

#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

#include<string>

using namespace std;

//�ڵ���
class node
{
public:
	int data;
	node *next,*pre;
	node():next(0),pre(0){}
	node(const int &item,node *nextnode=0,node *prenode=0):data(item),next(nextnode),pre(prenode){}
};

//�����ࣺ�洢����
class linkedList
{
public:
	//Ĭ�Ϲ��캯��
	linkedList();

	//���캯��
	linkedList(string &s);

	//����ָ�����ȵ�����
	void create(int lsize);

	//�������캯��
	linkedList(const linkedList &l);

	//����=
	linkedList& operator=(const linkedList& rhs);

	//�����������ͷŶ�̬����Ŀռ�
	~linkedList();

	//�������
	void clear();

	//���������
	void display();

	//��������
	void savetxt(const string &path);

	//��ͷ�����һ��Ԫ��
	void push_front(const int &item);

	//��β�����һ��Ԫ��
	void push_back(const int &item);

	friend class bigInteger;
	bool isMinus;//�Ƿ�Ϊ����
	int size;//������
	node *first;//ͷָ��
	node *last;//βָ��
};

#endif