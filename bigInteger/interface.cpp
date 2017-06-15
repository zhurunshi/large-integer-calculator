//interface.cpp

#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<windows.h>
#include"bigInteger.h"
#include"linkedList.h"
#include"interface.h"

using namespace std;

void file_add()
{
	char choice;
	while(true)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ����R�Է���                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		cout<<"�������ı�·����"<<endl;
		cout<<"���磺D:/xxx/xxx.txt"<<endl<<endl;
		bigInteger para;
		string path,n1,n2;
		while(cin>>path)
		{
			if(path=="R")
				addface();
			//�����ı�
			ifstream fin;
			fin.open(path.c_str());
			if(!fin)
			{
				cout<<"·���������������룡"<<endl<<endl;
				continue;
			}
			else
				fin>>n1>>n2;
			fin.close();
			break;
		}
		
		cout<<"                               �� �� �� �� �� ��"<<endl;
		cout<<"         ";
		for(int i=0;i<61;i++)
		{
			cout<<">";
			Sleep(10);
		}
		cout<<endl;
		cout<<"                                     �� ��"<<endl<<endl;
		
		cout<<"��һ������"<<n1<<endl<<endl;
		cout<<"�ڶ�������"<<n2<<endl<<endl;
		linkedList l1(n1);
		linkedList l2(n2);
		cout<<"��ʾ��1.������ָ���Կո������"<<endl;
		cout<<"      2.����0 0���������˲���"<<endl;
		cout<<"������ָ����ʽ��ģ����";
		string num,expo;
		double start,end;
		linkedList result;
		cin>>num>>expo;
		if(num=="R"||expo=="R")
			addface();
		if(num=="0"&&expo=="0")
		{
			cout<<endl;
			start=clock();
			//�ӵĽ��
			result=para.add(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//�ӵĽ��
			linkedList l5=para.add(l1,l2);
			//�ݵĽ��
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"���Ϊ��";
		result.display();
		cout<<endl;
		cout<<"��ʱ�� "<<(end-start)/1000<<" ��"<<endl<<endl;
		while(true)
		{
			cout<<"�Ƿ񵼳����ļ���(Y/N)��";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"���磺D:/xxx/xxx.txt"<<endl;
					cout<<"ע��1.���ı��������򴴽����ı���"<<endl;
					cout<<"    2.���ı���������滻�ı������ݡ�"<<endl<<endl;
					cout<<"������Ŀ��·����";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"�����ɹ���"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"ָ���������������룡"<<endl<<endl;
			}
			cout<<"�Ƿ�������룿(Y/N)��";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"ָ���������������룡"<<endl<<endl;
		}
		if(choice=='N')
			addface();
		else if(choice=='Y')
			continue;
	}
}

void keyboard_add()
{
	char choice;
	while(true)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ����R�Է���                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		
		bigInteger para;
		string n1,n2;
		cout<<"�������һ������";
		cin>>n1;
		if(n1=="R")
			addface();
		linkedList l1(n1);
		cout<<endl;
		cout<<"������ڶ�������";
		cin>>n2;
		if(n2=="R")
			addface();
		linkedList l2(n2);
		cout<<endl;
		cout<<"��ʾ��1.������ָ���Կո������"<<endl;
		cout<<"      2.����0 0���������˲���"<<endl;
		cout<<"������ָ����ʽ��ģ����";
		string num,expo;
		linkedList result;
		double start,end;
		cin>>num>>expo;
		if(num=="R"||expo=="R")
			addface();
		if(num=="0"&&expo=="0")
		{
			cout<<endl;
			start=clock();
			result=para.add(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//�ӵĽ��
			linkedList l5=para.add(l1,l2);
			//�ݵĽ��
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"���Ϊ��";
		result.display();
		cout<<endl;
		cout<<"��ʱ�� "<<(end-start)/1000<<" ��"<<endl<<endl;
		while(true)
		{
			cout<<"�Ƿ񵼳����ļ���(Y/N)��";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"���磺D:/xxx/xxx.txt"<<endl;
					cout<<"ע��1.���ı��������򴴽����ı���"<<endl;
					cout<<"    2.���ı���������滻�ı������ݡ�"<<endl<<endl;
					cout<<"������Ŀ��·����";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"�����ɹ���"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"ָ���������������룡"<<endl<<endl;
			}
			cout<<"�Ƿ�������룿(Y/N)��";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"ָ���������������룡"<<endl<<endl;
		}
		if(choice=='N')
			addface();
		else if(choice=='Y')
			continue;
	}
}

void addface()
{
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        �� �� �� ��                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        ����R�Է���                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"��ѡ�����뷽ʽ��";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':keyboard_add();break;
		case '2':file_add();break;
		case 'R':mainface();break;
		default :
			cout<<"ָ���������������룡"<<endl;
		}
	}
}


void file_subtract()
{	
	char choice;
	while(true)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ����R�Է���                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		cout<<"�������ı�·����"<<endl;
		cout<<"���磺D:/xxx/xxx.txt"<<endl<<endl;
		bigInteger para;
		string path,n1,n2;
		while(cin>>path)
		{
			if(path=="R")
				subtractface();
			//�����ı�
			ifstream fin;
			fin.open(path.c_str());
			if(!fin)
			{
				cout<<"·���������������룡"<<endl<<endl;
				continue;
			}
			else
				fin>>n1>>n2;
			fin.close();
			break;
		}
		
		cout<<"                               �� �� �� �� �� ��"<<endl;
		cout<<"         ";
		for(int i=0;i<61;i++)
		{
			cout<<">";
			Sleep(10);
		}
		cout<<endl;
		cout<<"                                     �� ��"<<endl<<endl;
		
		cout<<"��һ������"<<n1<<endl<<endl;
		cout<<"�ڶ�������"<<n2<<endl<<endl;
		linkedList l1(n1);
		linkedList l2(n2);
		cout<<"��ʾ��1.������ָ���Կո������"<<endl;
		cout<<"      2.����0 0���������˲���"<<endl;
		cout<<"������ָ����ʽ��ģ����";
		string num,expo;
		double start,end;
		linkedList result;
		cin>>num>>expo;
		if(num=="R"||expo=="R")
			subtractface();
		if(num=="0"&&expo=="0")
		{
			cout<<endl;
			start=clock();
			//���Ľ��
			result=para.subtract(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//���Ľ��
			linkedList l5=para.subtract(l1,l2);
			//�ݵĽ��
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"���Ϊ��";
		result.display();
		cout<<endl;
		cout<<"��ʱ�� "<<(end-start)/1000<<" ��"<<endl<<endl;
		while(true)
		{
			cout<<"�Ƿ񵼳����ļ���(Y/N)��";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"���磺D:/xxx/xxx.txt"<<endl;
					cout<<"ע��1.���ı��������򴴽����ı���"<<endl;
					cout<<"    2.���ı���������滻�ı������ݡ�"<<endl<<endl;
					cout<<"������Ŀ��·����";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"�����ɹ���"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"ָ���������������룡"<<endl<<endl;
			}
			cout<<"�Ƿ�������룿(Y/N)��";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"ָ���������������룡"<<endl<<endl;
		}
		if(choice=='N')
			subtractface();
		else if(choice=='Y')
			continue;
	}
}

void keyboard_subtract()
{
	char choice;
	while(true)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ����R�Է���                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		
		bigInteger para;
		string n1,n2;
		cout<<"�������һ������";
		cin>>n1;
		if(n1=="R")
			subtractface();
		linkedList l1(n1);
		cout<<endl;
		cout<<"������ڶ�������";
		cin>>n2;
		if(n2=="R")
			subtractface();
		linkedList l2(n2);
		cout<<endl;
		cout<<"��ʾ��1.������ָ���Կո������"<<endl;
		cout<<"      2.����0 0���������˲���"<<endl;
		cout<<"������ָ����ʽ��ģ����";
		string num,expo;
		double start,end;
		linkedList result;
		cin>>num>>expo;
		if(num=="R"||expo=="R")
			subtractface();
		if(num=="0"&&expo=="0")
		{
			cout<<endl;
			start=clock();
			//���Ľ��
			result=para.subtract(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//���Ľ��
			linkedList l5=para.subtract(l1,l2);
			//�ݵĽ��
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"���Ϊ��";
		result.display();
		cout<<endl;
		while(true)
		{
			cout<<"�Ƿ񵼳����ļ���(Y/N)��";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"���磺D:/xxx/xxx.txt"<<endl;
					cout<<"ע��1.���ı��������򴴽����ı���"<<endl;
					cout<<"    2.���ı���������滻�ı������ݡ�"<<endl<<endl;
					cout<<"������Ŀ��·����";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"�����ɹ���"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"ָ���������������룡"<<endl<<endl;
			}
			cout<<"�Ƿ�������룿(Y/N)��";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"ָ���������������룡"<<endl<<endl;
		}
		if(choice=='N')
			subtractface();
		else if(choice=='Y')
			continue;
	}
}

void subtractface()
{
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        �� �� �� ��                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        ����R�Է���                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"��ѡ�����뷽ʽ��";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':keyboard_subtract();break;
		case '2':file_subtract();break;
		case 'R':mainface();break;
		default :
			cout<<"ָ���������������룡"<<endl;
		}
	}
}


void file_multiply()
{
	char choice;
	while(true)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ����R�Է���                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		cout<<"�������ı�·����"<<endl;
		cout<<"���磺D:/xxx/xxx.txt"<<endl<<endl;
		bigInteger para;
		string path,n1,n2;
		while(cin>>path)
		{
			if(path=="R")
				multiplyface();
			//�����ı�
			ifstream fin;
			fin.open(path.c_str());
			if(!fin)
			{
				cout<<"·���������������룡"<<endl<<endl;
				continue;
			}
			else
				fin>>n1>>n2;
			fin.close();
			break;
		}
		
		cout<<"                               �� �� �� �� �� ��"<<endl;
		cout<<"         ";
		for(int i=0;i<61;i++)
		{
			cout<<">";
			Sleep(10);
		}
		cout<<endl;
		cout<<"                                     �� ��"<<endl<<endl;
		
		cout<<"��һ������"<<n1<<endl<<endl;
		cout<<"�ڶ�������"<<n2<<endl<<endl;
		linkedList l1(n1);
		linkedList l2(n2);
		cout<<"��ʾ��1.������ָ���Կո������"<<endl;
		cout<<"      2.����0 0���������˲���"<<endl;
		cout<<"������ָ����ʽ��ģ����";
		string num,expo;
		double start,end;
		linkedList result;
		cin>>num>>expo;
		if(num=="R"||expo=="R")
			multiplyface();
		if(num=="0"&&expo=="0")
		{
			cout<<endl;
			start=clock();
			//�˵Ľ��
			result=para.multiply(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//�˵Ľ��
			linkedList l5=para.multiply(l1,l2);
			//�ݵĽ��
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"���Ϊ��";
		result.display();
		cout<<endl;
		cout<<"��ʱ�� "<<(end-start)/1000<<" ��"<<endl<<endl;
		while(true)
		{
			cout<<"�Ƿ񵼳����ļ���(Y/N)��";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"���磺D:/xxx/xxx.txt"<<endl;
					cout<<"ע��1.���ı��������򴴽����ı���"<<endl;
					cout<<"    2.���ı���������滻�ı������ݡ�"<<endl<<endl;
					cout<<"������Ŀ��·����";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"�����ɹ���"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"ָ���������������룡"<<endl<<endl;
			}
			cout<<"�Ƿ�������룿(Y/N)��";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"ָ���������������룡"<<endl<<endl;
		}
		if(choice=='N')
			multiplyface();
		else if(choice=='Y')
			continue;
	}
}

void keyboard_multiply()
{
	char choice;
	while(true)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ����R�Է���                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		
		bigInteger para;
		string n1,n2;
		cout<<"�������һ������";
		cin>>n1;
		if(n1=="R")
			multiplyface();
		linkedList l1(n1);
		cout<<endl;
		cout<<"������ڶ�������";
		cin>>n2;
		if(n2=="R")
			multiplyface();
		linkedList l2(n2);
		cout<<endl;
		cout<<"��ʾ��1.������ָ���Կո������"<<endl;
		cout<<"      2.����0 0���������˲���"<<endl;
		cout<<"������ָ����ʽ��ģ����";
		string num,expo;
		double start,end;
		linkedList result;
		cin>>num>>expo;
		if(num=="R"||expo=="R")
			multiplyface();
		if(num=="0"&&expo=="0")
		{
			cout<<endl;
			start=clock();
			//�˵Ľ��
			result=para.multiply(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//�˵Ľ��
			linkedList l5=para.multiply(l1,l2);
			//�ݵĽ��
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"���Ϊ��";
		result.display();
		cout<<endl;
		cout<<"��ʱ��"<<(end-start)/1000<<" ��"<<endl<<endl;
		while(true)
		{
			cout<<"�Ƿ񵼳����ļ���(Y/N)��";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"���磺D:/xxx/xxx.txt"<<endl;
					cout<<"ע��1.���ı��������򴴽����ı���"<<endl;
					cout<<"    2.���ı���������滻�ı������ݡ�"<<endl<<endl;
					cout<<"������Ŀ��·����";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"�����ɹ���"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"ָ���������������룡"<<endl<<endl;
			}
			cout<<"�Ƿ�������룿(Y/N)��";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"ָ���������������룡"<<endl<<endl;
		}
		if(choice=='N')
			multiplyface();
		else if(choice=='Y')
			continue;
	}
}

void multiplyface()
{
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        �� �� �� ��                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        ����R�Է���                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"��ѡ�����뷽ʽ��";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':keyboard_multiply();break;
		case '2':file_multiply();break;
		case 'R':mainface();break;
		default :
			cout<<"ָ���������������룡"<<endl;
		}
	}
}


void file_divide()
{
	char choice;
	while(true)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ����R�Է���                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		cout<<"�������ı�·����"<<endl;
		cout<<"���磺D:/xxx/xxx.txt"<<endl<<endl;
		bigInteger para;
		string path,n1,n2;
		while(cin>>path)
		{
			if(path=="R")
				divideface();
			//�����ı�
			ifstream fin;
			fin.open(path.c_str());
			if(!fin)
			{
				cout<<"·���������������룡"<<endl<<endl;
				continue;
			}
			else
				fin>>n1>>n2;
			fin.close();
			break;
		}
		
		cout<<"                               �� �� �� �� �� ��"<<endl;
		cout<<"         ";
		for(int i=0;i<61;i++)
		{
			cout<<">";
			Sleep(10);
		}
		cout<<endl;
		cout<<"                                     �� ��"<<endl<<endl;
		
		cout<<"��һ������"<<n1<<endl<<endl;
		cout<<"�ڶ�������"<<n2<<endl<<endl;
		linkedList l1(n1);
		linkedList l2(n2);
		cout<<"��ʾ��1.������ָ���Կո������"<<endl;
		cout<<"      2.����0 0���������˲���"<<endl;
		cout<<"������ָ����ʽ��ģ����";
		string num,expo;
		double start,end;
		linkedList result;
		cin>>num>>expo;
		if(num=="R"||expo=="R")
			divideface();
		if(num=="0"&&expo=="0")
		{
			cout<<endl;
			start=clock();
			//���Ľ��
			result=para.divide(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//���Ľ��
			linkedList l5=para.divide(l1,l2);
			//�ݵĽ��
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"���Ϊ��";
		result.display();
		cout<<endl;
		cout<<"��ʱ�� "<<(end-start)/1000<<" ��"<<endl<<endl;
		while(true)
		{
			cout<<"�Ƿ񵼳����ļ���(Y/N)��";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"���磺D:/xxx/xxx.txt"<<endl;
					cout<<"ע��1.���ı��������򴴽����ı���"<<endl;
					cout<<"    2.���ı���������滻�ı������ݡ�"<<endl<<endl;
					cout<<"������Ŀ��·����";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"�����ɹ���"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"ָ���������������룡"<<endl<<endl;
			}
			cout<<"�Ƿ�������룿(Y/N)��";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"ָ���������������룡"<<endl<<endl;
		}
		if(choice=='N')
			divideface();
		else if(choice=='Y')
			continue;
	}
}

void keyboard_divide()
{
	char choice;
	while(true)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ����R�Է���                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		
		bigInteger para;
		string n1,n2;
		cout<<"�������һ������";
		cin>>n1;
		if(n1=="R")
			divideface();
		linkedList l1(n1);
		cout<<endl;
		cout<<"������ڶ�������";
		cin>>n2;
		if(n2=="R")
			divideface();
		while(n2=="0")
		{
			cout<<"��������Ϊ0��"<<endl<<endl;
			cout<<"������ڶ�������";
			cin>>n2;
		}
		linkedList l2(n2);
		cout<<endl;
		cout<<"��ʾ��1.������ָ���Կո������"<<endl;
		cout<<"      2.����0 0���������˲���"<<endl;
		cout<<"������ָ����ʽ��ģ����";
		string num,expo;
		double start,end;
		linkedList result;
		cin>>num>>expo;
		if(num=="R"||expo=="R")
			divideface();
		if(num=="0"&&expo=="0")
		{
			cout<<endl;
			start=clock();
			//���Ľ��
			result=para.divide(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//���Ľ��
			linkedList l5=para.divide(l1,l2);
			//�ݵĽ��
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"���Ϊ��";
		result.display();
		cout<<endl;
		cout<<"��ʱ��"<<(end-start)/1000<<" ��"<<endl<<endl;
		while(true)
		{
			cout<<"�Ƿ񵼳����ļ���(Y/N)��";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"���磺D:/xxx/xxx.txt"<<endl;
					cout<<"ע��1.���ı��������򴴽����ı���"<<endl;
					cout<<"    2.���ı���������滻�ı������ݡ�"<<endl<<endl;
					cout<<"������Ŀ��·����";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"�����ɹ���"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"ָ���������������룡"<<endl<<endl;
			}
			cout<<"�Ƿ�������룿(Y/N)��";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"ָ���������������룡"<<endl<<endl;
		}
		if(choice=='N')
			divideface();
		else if(choice=='Y')
			continue;
	}
}

void divideface()
{
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        �� �� �� ��                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        ����R�Է���                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"��ѡ�����뷽ʽ��";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':keyboard_divide();break;
		case '2':file_divide();break;
		case 'R':mainface();break;
		default :
			cout<<"ָ���������������룡"<<endl;
		}
	}
}


void file_power()
{
	char choice;
	while(true)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ָ �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ����R�Է���                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		cout<<"�������ı�·����"<<endl;
		cout<<"���磺D:/xxx/xxx.txt"<<endl<<endl;
		bigInteger para;
		string path,n1,n2;
		while(cin>>path)
		{
			if(path=="R")
				powerface();
			//�����ı�
			ifstream fin;
			fin.open(path.c_str());
			if(!fin)
			{
				cout<<"·���������������룡"<<endl<<endl;
				continue;
			}
			else
				fin>>n1>>n2;
			fin.close();
			break;
		}
		
		cout<<"                               �� �� �� �� �� ��"<<endl;
		cout<<"         ";
		for(int i=0;i<61;i++)
		{
			cout<<">";
			Sleep(10);
		}
		cout<<endl;
		cout<<"                                     �� ��"<<endl<<endl;
		
		cout<<"��һ������"<<n1<<endl<<endl;
		cout<<"�ڶ�������"<<n2<<endl<<endl;
		linkedList l1(n1);
		linkedList l2(n2);
		cout<<"��ʾ��1.������ָ���Կո������"<<endl;
		cout<<"      2.����0 0���������˲���"<<endl;
		cout<<"������ָ����ʽ��ģ����";
		string num,expo;
		double start,end;
		linkedList result;
		cin>>num>>expo;
		if(num=="R"||expo=="R")
			powerface();
		if(num=="0"&&expo=="0")
		{
			cout<<endl;
			start=clock();
			//�ݵĽ��
			result=para.power(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//�ݵĽ��
			linkedList l5=para.power(l1,l2);
			//�ݵĽ��
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"���Ϊ��";
		result.display();
		cout<<endl;
		cout<<"��ʱ�� "<<(end-start)/1000<<" ��"<<endl<<endl;
		while(true)
		{
			cout<<"�Ƿ񵼳����ļ���(Y/N)��";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"���磺D:/xxx/xxx.txt"<<endl;
					cout<<"ע��1.���ı��������򴴽����ı���"<<endl;
					cout<<"    2.���ı���������滻�ı������ݡ�"<<endl<<endl;
					cout<<"������Ŀ��·����";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"�����ɹ���"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"ָ���������������룡"<<endl<<endl;
			}
			cout<<"�Ƿ�������룿(Y/N)��";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"ָ���������������룡"<<endl<<endl;
		}
		if(choice=='N')
			powerface();
		else if(choice=='Y')
			continue;
	}
}

void keyboard_power()
{
	char choice;
	while(true)
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ָ �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        �� �� �� ��                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        ����R�Է���                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		
		bigInteger para;
		string n1,n2;
		cout<<"�������һ������";
		cin>>n1;
		if(n1=="R")
			powerface();
		while(n1=="0")
		{
			cout<<"��������Ϊ0��"<<endl<<endl;
			cout<<"�������һ������";
			cin>>n1;
		}
		linkedList l1(n1);
		cout<<endl;
		cout<<"������ڶ�������";
		cin>>n2;
		if(n2=="R")
			powerface();
		linkedList l2(n2);
		cout<<endl;
		cout<<"��ʾ��1.������ָ���Կո������"<<endl;
		cout<<"      2.����0 0���������˲���"<<endl;
		cout<<"������ָ����ʽ��ģ����";
		string num,expo;
		double start,end;
		linkedList result;
		cin>>num>>expo;
		if(num=="R"||expo=="R")
			powerface();
		if(num=="0"&&expo=="0")
		{
			cout<<endl;
			start=clock();
			//�ݵĽ��
			result=para.power(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//�ݵĽ��
			linkedList l5=para.power(l1,l2);
			//�ݵĽ��
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"���Ϊ��";
		result.display();
		cout<<endl;
		cout<<"��ʱ��"<<(end-start)/1000<<" ��"<<endl<<endl;
		while(true)
		{
			cout<<"�Ƿ񵼳����ļ���(Y/N)��";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"���磺D:/xxx/xxx.txt"<<endl;
					cout<<"ע��1.���ı��������򴴽����ı���"<<endl;
					cout<<"    2.���ı���������滻�ı������ݡ�"<<endl<<endl;
					cout<<"������Ŀ��·����";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"�����ɹ���"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"ָ���������������룡"<<endl<<endl;
			}
			cout<<"�Ƿ�������룿(Y/N)��";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"ָ���������������룡"<<endl<<endl;
		}
		if(choice=='N')
			powerface();
		else if(choice=='Y')
			continue;
	}
}

void powerface()
{
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        ָ �� �� ��                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        ����R�Է���                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"��ѡ�����뷽ʽ��";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':keyboard_power();break;
		case '2':file_power();break;
		case 'R':mainface();break;
		default :
			cout<<"ָ���������������룡"<<endl;
		}
	}
}

void mainface()
{
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<"         * * * * * * * * * * *�� �� �� �� ��(Alpha��)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       3.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       4.�� �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       5.ָ �� �� ��                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        ����Q���˳�                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"��ѡ��";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':addface();break;
		case '2':subtractface();break;
		case '3':multiplyface();break;
		case '4':divideface();break;
		case '5':powerface();break;
		case 'Q':exit(0);
		default :
			cout<<"ָ���������������룡"<<endl;
		}
	}
}