/*
*
*功能： 宏va_arg()用于给函数传递可变长度的参数列表。 
*首先，必须调用va_start() 传递有效的参数列表va_list和函数强制的第一个参数。第一个参数代表将要传递的参数的个数。 
*其次，调用va_arg()传递参数列表va_list 和将被返回的参数的类型。va_arg()的返回值是当前的参数。 
*再次，对所有的参数重复调用va_arg() 
*最后，调用va_end()传递va_list对完成后的清除是必须的。 
*
*时间：2011年8月17日22:34:04
*作者：张超
*Email:uestczhangchao@gmail.com
*
*/


#include "X:\编程练习\C-C++\global.h"

#if va_arg==stdon
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

//第一个参数指定了参数的个数
int sum(int number,...)
{
	va_list vaptr;
	int i;
	int sum = 0;
	int *p = &i;
	char *pc;
	char c='a';
	pc = &c;
	printf("pc=%d\n",pc);
	printf("pc+1=%d\n",pc+1);
	printf("p=%d\n",p);
	printf("p+1=%d\n",p+1);
	va_start(vaptr,number);
	for(i=0; i<number;i++)
	{
		sum += va_arg(vaptr,int);
	}
	va_end(vaptr);
	return sum;
}


int main()
{
	printf("%d\n",sum(4,4,3,2,1));
	system("pause");
	return 0;
}

#endif