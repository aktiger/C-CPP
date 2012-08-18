/*
*
*This program is used to practice function pointers.
*There are there function pointers in struct hooks and struct config.
*I use the function pointers in hooks to initialize sturct config.
*When i do this in diab compiler i got errors, but in vs2008 ,it seem ok!~
*
*时间：2011年8月17日21:14:37
*作者：张超
*Email:uestczhangchao@gmail.com
*
*/


#include "X:\编程练习\C-C++\global.h"

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


	//曾经，我在这个位置，犯下了一个非常弱智的错误，以至于打击到了自己的自信心...
	//因为，我忘了，这是在C中，所有的变量的声明和定义都必须在所有的操作之前。。。
	//到处找原因，以为是C中不能用srand啦、、我的预定义开关有问题啦。。。。
	//找来找去，原来是这种弱智的原因。。。。2011年8月17日22:26:33 Justinzhang
	
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