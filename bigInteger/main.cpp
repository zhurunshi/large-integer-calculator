//main.cpp

#include<iostream>
#include<windows.h>
#include"bigInteger.h"
#include"linkedList.h"
#include"interface.h"

using namespace std;

void main()
{
	cout<<endl;
	cout<<endl;
	cout<<"         * * * * * * * * * * *大 整 数 运 算(Alpha版)* * * * * * * * *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                           作  者：                        *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                           朱润石                          *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         *                                                           *"<<endl;
	cout<<"         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
	cout<<"                                    STARTING                          "<<endl;
	cout<<endl;
	cout<<"         ";
	for(int i=0;i<61;i++)
	{
		cout<<">";
		Sleep(50);
	}
	cout<<endl;
	mainface();
}
