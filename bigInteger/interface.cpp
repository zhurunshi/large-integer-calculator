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
		cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        加 法 运 算                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        文 件 输 入                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        输入R以返回                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		cout<<"请输入文本路径："<<endl;
		cout<<"例如：D:/xxx/xxx.txt"<<endl<<endl;
		bigInteger para;
		string path,n1,n2;
		while(cin>>path)
		{
			if(path=="R")
				addface();
			//导入文本
			ifstream fin;
			fin.open(path.c_str());
			if(!fin)
			{
				cout<<"路径有误，请重新输入！"<<endl<<endl;
				continue;
			}
			else
				fin>>n1>>n2;
			fin.close();
			break;
		}
		
		cout<<"                               正 在 读 入 文 本"<<endl;
		cout<<"         ";
		for(int i=0;i<61;i++)
		{
			cout<<">";
			Sleep(10);
		}
		cout<<endl;
		cout<<"                                     完 毕"<<endl<<endl;
		
		cout<<"第一个数："<<n1<<endl<<endl;
		cout<<"第二个数："<<n2<<endl<<endl;
		linkedList l1(n1);
		linkedList l2(n2);
		cout<<"提示：1.底数和指数以空格隔开。"<<endl;
		cout<<"      2.输入0 0即可跳过此步。"<<endl;
		cout<<"请输入指数形式的模数：";
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
			//加的结果
			result=para.add(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//加的结果
			linkedList l5=para.add(l1,l2);
			//幂的结果
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"结果为：";
		result.display();
		cout<<endl;
		cout<<"用时： "<<(end-start)/1000<<" 秒"<<endl<<endl;
		while(true)
		{
			cout<<"是否导出至文件？(Y/N)：";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"例如：D:/xxx/xxx.txt"<<endl;
					cout<<"注：1.若文本不存在则创建该文本。"<<endl;
					cout<<"    2.若文本存在则会替换文本的内容。"<<endl<<endl;
					cout<<"请输入目的路径：";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"导出成功。"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"指令有误，请重新输入！"<<endl<<endl;
			}
			cout<<"是否继续输入？(Y/N)：";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"指令有误，请重新输入！"<<endl<<endl;
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
		cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        加 法 运 算                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        键 盘 输 入                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        输入R以返回                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		
		bigInteger para;
		string n1,n2;
		cout<<"请输入第一个数：";
		cin>>n1;
		if(n1=="R")
			addface();
		linkedList l1(n1);
		cout<<endl;
		cout<<"请输入第二个数：";
		cin>>n2;
		if(n2=="R")
			addface();
		linkedList l2(n2);
		cout<<endl;
		cout<<"提示：1.底数和指数以空格隔开。"<<endl;
		cout<<"      2.输入0 0即可跳过此步。"<<endl;
		cout<<"请输入指数形式的模数：";
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
			//加的结果
			linkedList l5=para.add(l1,l2);
			//幂的结果
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"结果为：";
		result.display();
		cout<<endl;
		cout<<"用时： "<<(end-start)/1000<<" 秒"<<endl<<endl;
		while(true)
		{
			cout<<"是否导出至文件？(Y/N)：";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"例如：D:/xxx/xxx.txt"<<endl;
					cout<<"注：1.若文本不存在则创建该文本。"<<endl;
					cout<<"    2.若文本存在则会替换文本的内容。"<<endl<<endl;
					cout<<"请输入目的路径：";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"导出成功。"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"指令有误，请重新输入！"<<endl<<endl;
			}
			cout<<"是否继续输入？(Y/N)：";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"指令有误，请重新输入！"<<endl<<endl;
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
	cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        加 法 运 算                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.键 盘 输 入                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.文 件 输 入                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        输入R以返回                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"请选择输入方式：";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':keyboard_add();break;
		case '2':file_add();break;
		case 'R':mainface();break;
		default :
			cout<<"指令有误，请重新输入！"<<endl;
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
		cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        减 法 运 算                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        文 件 输 入                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        输入R以返回                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		cout<<"请输入文本路径："<<endl;
		cout<<"例如：D:/xxx/xxx.txt"<<endl<<endl;
		bigInteger para;
		string path,n1,n2;
		while(cin>>path)
		{
			if(path=="R")
				subtractface();
			//导入文本
			ifstream fin;
			fin.open(path.c_str());
			if(!fin)
			{
				cout<<"路径有误，请重新输入！"<<endl<<endl;
				continue;
			}
			else
				fin>>n1>>n2;
			fin.close();
			break;
		}
		
		cout<<"                               正 在 读 入 文 本"<<endl;
		cout<<"         ";
		for(int i=0;i<61;i++)
		{
			cout<<">";
			Sleep(10);
		}
		cout<<endl;
		cout<<"                                     完 毕"<<endl<<endl;
		
		cout<<"第一个数："<<n1<<endl<<endl;
		cout<<"第二个数："<<n2<<endl<<endl;
		linkedList l1(n1);
		linkedList l2(n2);
		cout<<"提示：1.底数和指数以空格隔开。"<<endl;
		cout<<"      2.输入0 0即可跳过此步。"<<endl;
		cout<<"请输入指数形式的模数：";
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
			//减的结果
			result=para.subtract(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//减的结果
			linkedList l5=para.subtract(l1,l2);
			//幂的结果
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"结果为：";
		result.display();
		cout<<endl;
		cout<<"用时： "<<(end-start)/1000<<" 秒"<<endl<<endl;
		while(true)
		{
			cout<<"是否导出至文件？(Y/N)：";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"例如：D:/xxx/xxx.txt"<<endl;
					cout<<"注：1.若文本不存在则创建该文本。"<<endl;
					cout<<"    2.若文本存在则会替换文本的内容。"<<endl<<endl;
					cout<<"请输入目的路径：";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"导出成功。"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"指令有误，请重新输入！"<<endl<<endl;
			}
			cout<<"是否继续输入？(Y/N)：";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"指令有误，请重新输入！"<<endl<<endl;
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
		cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        减 法 运 算                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        键 盘 输 入                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        输入R以返回                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		
		bigInteger para;
		string n1,n2;
		cout<<"请输入第一个数：";
		cin>>n1;
		if(n1=="R")
			subtractface();
		linkedList l1(n1);
		cout<<endl;
		cout<<"请输入第二个数：";
		cin>>n2;
		if(n2=="R")
			subtractface();
		linkedList l2(n2);
		cout<<endl;
		cout<<"提示：1.底数和指数以空格隔开。"<<endl;
		cout<<"      2.输入0 0即可跳过此步。"<<endl;
		cout<<"请输入指数形式的模数：";
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
			//减的结果
			result=para.subtract(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//减的结果
			linkedList l5=para.subtract(l1,l2);
			//幂的结果
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"结果为：";
		result.display();
		cout<<endl;
		while(true)
		{
			cout<<"是否导出至文件？(Y/N)：";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"例如：D:/xxx/xxx.txt"<<endl;
					cout<<"注：1.若文本不存在则创建该文本。"<<endl;
					cout<<"    2.若文本存在则会替换文本的内容。"<<endl<<endl;
					cout<<"请输入目的路径：";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"导出成功。"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"指令有误，请重新输入！"<<endl<<endl;
			}
			cout<<"是否继续输入？(Y/N)：";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"指令有误，请重新输入！"<<endl<<endl;
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
	cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        减 法 运 算                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.键 盘 输 入                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.文 件 输 入                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        输入R以返回                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"请选择输入方式：";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':keyboard_subtract();break;
		case '2':file_subtract();break;
		case 'R':mainface();break;
		default :
			cout<<"指令有误，请重新输入！"<<endl;
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
		cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        乘 法 运 算                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        文 件 输 入                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        输入R以返回                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		cout<<"请输入文本路径："<<endl;
		cout<<"例如：D:/xxx/xxx.txt"<<endl<<endl;
		bigInteger para;
		string path,n1,n2;
		while(cin>>path)
		{
			if(path=="R")
				multiplyface();
			//导入文本
			ifstream fin;
			fin.open(path.c_str());
			if(!fin)
			{
				cout<<"路径有误，请重新输入！"<<endl<<endl;
				continue;
			}
			else
				fin>>n1>>n2;
			fin.close();
			break;
		}
		
		cout<<"                               正 在 读 入 文 本"<<endl;
		cout<<"         ";
		for(int i=0;i<61;i++)
		{
			cout<<">";
			Sleep(10);
		}
		cout<<endl;
		cout<<"                                     完 毕"<<endl<<endl;
		
		cout<<"第一个数："<<n1<<endl<<endl;
		cout<<"第二个数："<<n2<<endl<<endl;
		linkedList l1(n1);
		linkedList l2(n2);
		cout<<"提示：1.底数和指数以空格隔开。"<<endl;
		cout<<"      2.输入0 0即可跳过此步。"<<endl;
		cout<<"请输入指数形式的模数：";
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
			//乘的结果
			result=para.multiply(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//乘的结果
			linkedList l5=para.multiply(l1,l2);
			//幂的结果
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"结果为：";
		result.display();
		cout<<endl;
		cout<<"用时： "<<(end-start)/1000<<" 秒"<<endl<<endl;
		while(true)
		{
			cout<<"是否导出至文件？(Y/N)：";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"例如：D:/xxx/xxx.txt"<<endl;
					cout<<"注：1.若文本不存在则创建该文本。"<<endl;
					cout<<"    2.若文本存在则会替换文本的内容。"<<endl<<endl;
					cout<<"请输入目的路径：";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"导出成功。"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"指令有误，请重新输入！"<<endl<<endl;
			}
			cout<<"是否继续输入？(Y/N)：";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"指令有误，请重新输入！"<<endl<<endl;
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
		cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        乘 法 运 算                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        键 盘 输 入                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        输入R以返回                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		
		bigInteger para;
		string n1,n2;
		cout<<"请输入第一个数：";
		cin>>n1;
		if(n1=="R")
			multiplyface();
		linkedList l1(n1);
		cout<<endl;
		cout<<"请输入第二个数：";
		cin>>n2;
		if(n2=="R")
			multiplyface();
		linkedList l2(n2);
		cout<<endl;
		cout<<"提示：1.底数和指数以空格隔开。"<<endl;
		cout<<"      2.输入0 0即可跳过此步。"<<endl;
		cout<<"请输入指数形式的模数：";
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
			//乘的结果
			result=para.multiply(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//乘的结果
			linkedList l5=para.multiply(l1,l2);
			//幂的结果
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"结果为：";
		result.display();
		cout<<endl;
		cout<<"用时："<<(end-start)/1000<<" 秒"<<endl<<endl;
		while(true)
		{
			cout<<"是否导出至文件？(Y/N)：";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"例如：D:/xxx/xxx.txt"<<endl;
					cout<<"注：1.若文本不存在则创建该文本。"<<endl;
					cout<<"    2.若文本存在则会替换文本的内容。"<<endl<<endl;
					cout<<"请输入目的路径：";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"导出成功。"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"指令有误，请重新输入！"<<endl<<endl;
			}
			cout<<"是否继续输入？(Y/N)：";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"指令有误，请重新输入！"<<endl<<endl;
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
	cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        乘 法 运 算                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.键 盘 输 入                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.文 件 输 入                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        输入R以返回                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"请选择输入方式：";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':keyboard_multiply();break;
		case '2':file_multiply();break;
		case 'R':mainface();break;
		default :
			cout<<"指令有误，请重新输入！"<<endl;
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
		cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        除 法 运 算                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        文 件 输 入                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        输入R以返回                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		cout<<"请输入文本路径："<<endl;
		cout<<"例如：D:/xxx/xxx.txt"<<endl<<endl;
		bigInteger para;
		string path,n1,n2;
		while(cin>>path)
		{
			if(path=="R")
				divideface();
			//导入文本
			ifstream fin;
			fin.open(path.c_str());
			if(!fin)
			{
				cout<<"路径有误，请重新输入！"<<endl<<endl;
				continue;
			}
			else
				fin>>n1>>n2;
			fin.close();
			break;
		}
		
		cout<<"                               正 在 读 入 文 本"<<endl;
		cout<<"         ";
		for(int i=0;i<61;i++)
		{
			cout<<">";
			Sleep(10);
		}
		cout<<endl;
		cout<<"                                     完 毕"<<endl<<endl;
		
		cout<<"第一个数："<<n1<<endl<<endl;
		cout<<"第二个数："<<n2<<endl<<endl;
		linkedList l1(n1);
		linkedList l2(n2);
		cout<<"提示：1.底数和指数以空格隔开。"<<endl;
		cout<<"      2.输入0 0即可跳过此步。"<<endl;
		cout<<"请输入指数形式的模数：";
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
			//除的结果
			result=para.divide(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//除的结果
			linkedList l5=para.divide(l1,l2);
			//幂的结果
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"结果为：";
		result.display();
		cout<<endl;
		cout<<"用时： "<<(end-start)/1000<<" 秒"<<endl<<endl;
		while(true)
		{
			cout<<"是否导出至文件？(Y/N)：";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"例如：D:/xxx/xxx.txt"<<endl;
					cout<<"注：1.若文本不存在则创建该文本。"<<endl;
					cout<<"    2.若文本存在则会替换文本的内容。"<<endl<<endl;
					cout<<"请输入目的路径：";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"导出成功。"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"指令有误，请重新输入！"<<endl<<endl;
			}
			cout<<"是否继续输入？(Y/N)：";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"指令有误，请重新输入！"<<endl<<endl;
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
		cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        除 法 运 算                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        键 盘 输 入                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        输入R以返回                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		
		bigInteger para;
		string n1,n2;
		cout<<"请输入第一个数：";
		cin>>n1;
		if(n1=="R")
			divideface();
		linkedList l1(n1);
		cout<<endl;
		cout<<"请输入第二个数：";
		cin>>n2;
		if(n2=="R")
			divideface();
		while(n2=="0")
		{
			cout<<"除数不能为0！"<<endl<<endl;
			cout<<"请输入第二个数：";
			cin>>n2;
		}
		linkedList l2(n2);
		cout<<endl;
		cout<<"提示：1.底数和指数以空格隔开。"<<endl;
		cout<<"      2.输入0 0即可跳过此步。"<<endl;
		cout<<"请输入指数形式的模数：";
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
			//除的结果
			result=para.divide(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//除的结果
			linkedList l5=para.divide(l1,l2);
			//幂的结果
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"结果为：";
		result.display();
		cout<<endl;
		cout<<"用时："<<(end-start)/1000<<" 秒"<<endl<<endl;
		while(true)
		{
			cout<<"是否导出至文件？(Y/N)：";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"例如：D:/xxx/xxx.txt"<<endl;
					cout<<"注：1.若文本不存在则创建该文本。"<<endl;
					cout<<"    2.若文本存在则会替换文本的内容。"<<endl<<endl;
					cout<<"请输入目的路径：";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"导出成功。"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"指令有误，请重新输入！"<<endl<<endl;
			}
			cout<<"是否继续输入？(Y/N)：";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"指令有误，请重新输入！"<<endl<<endl;
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
	cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        除 法 运 算                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.键 盘 输 入                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.文 件 输 入                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        输入R以返回                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"请选择输入方式：";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':keyboard_divide();break;
		case '2':file_divide();break;
		case 'R':mainface();break;
		default :
			cout<<"指令有误，请重新输入！"<<endl;
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
		cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        指 数 运 算                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        文 件 输 入                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        输入R以返回                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		cout<<"请输入文本路径："<<endl;
		cout<<"例如：D:/xxx/xxx.txt"<<endl<<endl;
		bigInteger para;
		string path,n1,n2;
		while(cin>>path)
		{
			if(path=="R")
				powerface();
			//导入文本
			ifstream fin;
			fin.open(path.c_str());
			if(!fin)
			{
				cout<<"路径有误，请重新输入！"<<endl<<endl;
				continue;
			}
			else
				fin>>n1>>n2;
			fin.close();
			break;
		}
		
		cout<<"                               正 在 读 入 文 本"<<endl;
		cout<<"         ";
		for(int i=0;i<61;i++)
		{
			cout<<">";
			Sleep(10);
		}
		cout<<endl;
		cout<<"                                     完 毕"<<endl<<endl;
		
		cout<<"第一个数："<<n1<<endl<<endl;
		cout<<"第二个数："<<n2<<endl<<endl;
		linkedList l1(n1);
		linkedList l2(n2);
		cout<<"提示：1.底数和指数以空格隔开。"<<endl;
		cout<<"      2.输入0 0即可跳过此步。"<<endl;
		cout<<"请输入指数形式的模数：";
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
			//幂的结果
			result=para.power(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//幂的结果
			linkedList l5=para.power(l1,l2);
			//幂的结果
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"结果为：";
		result.display();
		cout<<endl;
		cout<<"用时： "<<(end-start)/1000<<" 秒"<<endl<<endl;
		while(true)
		{
			cout<<"是否导出至文件？(Y/N)：";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"例如：D:/xxx/xxx.txt"<<endl;
					cout<<"注：1.若文本不存在则创建该文本。"<<endl;
					cout<<"    2.若文本存在则会替换文本的内容。"<<endl<<endl;
					cout<<"请输入目的路径：";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"导出成功。"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"指令有误，请重新输入！"<<endl<<endl;
			}
			cout<<"是否继续输入？(Y/N)：";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"指令有误，请重新输入！"<<endl<<endl;
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
		cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        指 数 运 算                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        键 盘 输 入                        *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                                                           *"<<endl;
		cout<<"         *                        输入R以返回                        *"<<endl;
		cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<endl;
		
		bigInteger para;
		string n1,n2;
		cout<<"请输入第一个数：";
		cin>>n1;
		if(n1=="R")
			powerface();
		while(n1=="0")
		{
			cout<<"底数不能为0！"<<endl<<endl;
			cout<<"请输入第一个数：";
			cin>>n1;
		}
		linkedList l1(n1);
		cout<<endl;
		cout<<"请输入第二个数：";
		cin>>n2;
		if(n2=="R")
			powerface();
		linkedList l2(n2);
		cout<<endl;
		cout<<"提示：1.底数和指数以空格隔开。"<<endl;
		cout<<"      2.输入0 0即可跳过此步。"<<endl;
		cout<<"请输入指数形式的模数：";
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
			//幂的结果
			result=para.power(l1,l2);
			end=clock();
		}
		else
		{
			linkedList l3(num);
			linkedList l4(expo);
			cout<<endl;
			start=clock();
			//幂的结果
			linkedList l5=para.power(l1,l2);
			//幂的结果
			linkedList l6=para.power(l3,l4);
			result=para.mod(l5,l6);
			end=clock();
		}
		cout<<"结果为：";
		result.display();
		cout<<endl;
		cout<<"用时："<<(end-start)/1000<<" 秒"<<endl<<endl;
		while(true)
		{
			cout<<"是否导出至文件？(Y/N)：";
			char choice2;
			while(cin>>choice2)
			{
				if(choice2=='Y')
				{
					cout<<"例如：D:/xxx/xxx.txt"<<endl;
					cout<<"注：1.若文本不存在则创建该文本。"<<endl;
					cout<<"    2.若文本存在则会替换文本的内容。"<<endl<<endl;
					cout<<"请输入目的路径：";
					string path;
					cin>>path;
					result.savetxt(path);
					cout<<"导出成功。"<<endl<<endl;
					break;
				}
				else if(choice2=='N')
				{
					cout<<endl;
					break;
				}
				else
					cout<<"指令有误，请重新输入！"<<endl<<endl;
			}
			cout<<"是否继续输入？(Y/N)：";
			cin>>choice;
			cout<<endl;
			if(choice=='N'||choice=='Y')
				break;
			else
				cout<<"指令有误，请重新输入！"<<endl<<endl;
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
	cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        指 数 运 算                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.键 盘 输 入                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.文 件 输 入                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        输入R以返回                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"请选择输入方式：";
	char choice;
	while(cin>>choice)
	{
		switch(choice)
		{
		case '1':keyboard_power();break;
		case '2':file_power();break;
		case 'R':mainface();break;
		default :
			cout<<"指令有误，请重新输入！"<<endl;
		}
	}
}

void mainface()
{
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       1.加 法 运 算                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       2.减 法 运 算                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       3.乘 法 运 算                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       4.除 法 运 算                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                       5.指 数 运 算                       *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                        输入Q以退出                        *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"请选择：";
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
			cout<<"指令有误，请重新输入！"<<endl;
		}
	}
}