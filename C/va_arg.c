/*
*
*���ܣ� ��va_arg()���ڸ��������ݿɱ䳤�ȵĲ����б� 
*���ȣ��������va_start() ������Ч�Ĳ����б�va_list�ͺ���ǿ�Ƶĵ�һ����������һ����������Ҫ���ݵĲ����ĸ����� 
*��Σ�����va_arg()���ݲ����б�va_list �ͽ������صĲ��������͡�va_arg()�ķ���ֵ�ǵ�ǰ�Ĳ����� 
*�ٴΣ������еĲ����ظ�����va_arg() 
*��󣬵���va_end()����va_list����ɺ������Ǳ���ġ� 
*
*ʱ�䣺2011��8��17��22:34:04
*���ߣ��ų�
*Email:uestczhangchao@gmail.com
*
*/


#include "X:\�����ϰ\C-C++\global.h"

#if va_arg==stdon
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

//��һ������ָ���˲����ĸ���
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