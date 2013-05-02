#include <stdio.h>

int myfun(int n)
{
	n=n+2;

	return rand(n);
}
void main()
{
	volatile  int i=10;
	//int i=10;
	int a,b,c;
	a=i;
	b=i;
	c=i;
	printf("i=%d\n",a);
	printf("i=%d\n",myfun(4));
}

