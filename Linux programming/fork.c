/*
Author:Justinzhang
email:uestczhangchao@gmail.com
time:2012-8-30 22:17:23
desc：fork problem, from www.qshpan.com
*/

#include <stdio.h>
int sum;
int main()
{
	int i = 0;
	sum = 0;
	fork();
	for(i=0; i<5; i++)
	{
		printf("%d\n",i);
		fflush();
		sum += i;
	}
	printf("sum = %d\n", sum);
	
	exit(0);
}