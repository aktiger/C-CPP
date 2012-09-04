/*
@@
	Author:	Justinzhang
	Email:	uestczhangchao@gmail.com
	Time:	ver 1.0 a long time ago, reviewed and made some change at:2012-9-4 21:29:09
	Desc:	bit operation, here i've stolen the linux macro style. 
@@
*/
#include <stdio.h>

#define clearbit(data,x)\
	do{							\
		data = data & ~(1UL<<(x));	\
	}while(0)

#define setbit(data, y)\
		do{\
			data = data | (1UL<<(y));\
		}while(0)


int clear(int data, int x)
{
	//int mask = pow(2,x);
	data = data & ~(1<<x);
	return data;
}

//#define sety(data, y)

/* this function set bit y and bit y-1, then clear bit y-2 */
int set(int data, int y)
{
	data = (data|(1<<y)|(1<<(y-1))& ~(1<<(y-2)));
	return data;
}

int main()
{
	int R, X, Y;
	printf("Input three integers!!!\n");
	fflush(stdout);
	scanf("%x,%d,%d",&R, &X, &Y);
	fflush(stdin);
	printf("%x,%d,%d\n",R, X, Y);
	fflush(stdout);
//	printf("%x\n",clear(R,X));
//	printf("%x\n",set(R,Y));

	/*the following three line are equal to set(R,Y);*/
	setbit(R,Y);
	setbit(R,Y-1);
	clearbit(R,Y-2);

	printf("%x\n",R);

	return 	0;
}
