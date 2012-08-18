/*
*
*This program is used to practice function pointers.
*There are there function pointers in struct hooks and struct config.
*I use the function pointers in hooks to initialize sturct config.
*When i do this in diab compiler i got errors, but in vs2008 ,it seem ok!~
*
*ʱ�䣺2011��8��17��21:14:37
*���ߣ��ų�
*Email:uestczhangchao@gmail.com
*
*/


#include "X:\�����ϰ\C-C++\global.h"

#if function_pointer==stdon
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	void (*error)();
	int (*startup)(int);
	int (*shutdown)(void);
	
}hooks;

typedef struct
{
	int id;
	void (*errorhook)();
	int (*startuphook)(int);
	int (*shutdownhook)();
}config;

void funcerror(void)
{
	printf("in funcerror\n");
}


int funcstartup(int x)
{
	printf("int funcstartup x=%d\n",x);
	return 1;
}


int funcshutdown(void)
{
	printf("in funcshutdown\n");
	return 0;
}

config cc[2];

hooks hook={funcerror, funcstartup, funcshutdown};

int main()
{
	int i;


	//�������������λ�ã�������һ���ǳ����ǵĴ��������ڴ�������Լ���������...
	//��Ϊ�������ˣ�������C�У����еı����������Ͷ��嶼���������еĲ���֮ǰ������
	//������ԭ����Ϊ��C�в�����srand�������ҵ�Ԥ���忪������������������
	//������ȥ��ԭ�����������ǵ�ԭ�򡣡�����2011��8��17��22:26:33 Justinzhang
	
	srand((unsigned)time(NULL));
	
	//__TIME__
	//A string literal containing the time of compilation, in the form "hh:mm:ss" 
	//From:C bible~~
	printf("%s\n",__TIME__);


	for(i=0;i<10;i++)
	{
		printf("%d\t",rand());
	}
	printf("\n");

	for (i=0; i<2; i++)
	{
		cc[i].errorhook = hook.error;
		cc[i].shutdownhook = hook.shutdown;
		cc[i].startuphook = hook.startup;
	}
	
	for (i=0; i<2; i++)
	{
		printf("\nIn cc[%d]***************\n",i+1);
		cc[i].errorhook();
		cc[i].startuphook(rand());
		cc[i].shutdownhook();
	}

	system("pause");
	return 0;
}

#endif