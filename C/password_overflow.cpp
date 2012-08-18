
/*
*This program demonstrate how the stack is overflow,in this case the password filed is 
*override by user input.even though the user don't konow password,he can still get into the system.
*该程序在vs2008的debug版本中会出现溢出情况，在release中不能出现溢出的情况.
*时间：2011年8月18日17:44:33
*作者：张超
*Email:uestczhangchao@gmail.com
*/


//#include "X:\编程练习\C-C++\global.h"

//#if password_overflow==stdon

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
int main()
{
	/*password和input的顺序不能够颠倒，因为局部变量是在栈上按照定义顺序
	从高地址往地地址递减，即&password[0]>&input[0]。对于每个数组，从首元素开始，
	依次递增的存放，即&password[1]>&password[0]。只有这样定义才可以让input向上增长的时候
	覆盖掉password的内容。
	*/
	char password[10]="123456789";
	char input[10];

	int i;
	cout<<"请输入密码"<<endl;
	cin>>input;
	for(i=0;i<10;i++)
	{
		if(password[i]!=input[i])
			break;
	}

	/*这里用strcmp是不行的，因为input自己已经溢出，末尾的\0已经被替换成1了，
	同时password末尾的\0也已经被替换成1了。而strcmp是依据\0来判断字符串结尾的*/
	if(i==10)
	{
		cout<<"密码正确"<<endl;
	}
	else
	{
		cout<<"密码错误"<<endl;
	}
	system("pause");
	return 0;
}
//#endif