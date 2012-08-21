
/*
*
*深入理解计算机系统--例子
*
*时间：2011年8月17日12:08:16
*作者：张超
*Email:uestczhangchao@gmail.com
*
*/


#include "X:\编程练习\C-C++\global.h"

#if computer_perspective==stdon

#include <stdio.h>

typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer *start,int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf(" %.2x",start[i]);
	}
	printf("\n");
}

void show_int(int x)
{
	show_bytes((byte_pointer)&x,sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_poiter(void *x)
{
	show_bytes((byte_pointer) &x, sizeof(void *));
}


int func1(unsigned word)
{
	return (int)((word<<24)>>24);

}

int func2(unsigned word)
{
	return ((int)word<<24)>>24;
}


int main()
{
	int number[]={0x00000076,0x87654321,0x000000c9,0xedcba987};
	int i;
	int size = sizeof(number)/sizeof(int);
	//printf("size=%d\n",size);

	for(i=0;i<size;i++)
	{
		printf("%x\t:\t%x\t%x\n",i+1,func1(number[i]),func2(number[i]));
	}
	
	system("pause");
	return 0;
}

#endif