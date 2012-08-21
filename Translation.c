#include <stdio.h>

/*
 * 将任意进制数转化为十进制数
 * data 为原始数，r为原始数据的进制数
 */

int T(int data, int r)
{
	int temp = 0;
	int exp = 1;
	int sum = 0;
	while(data!=0)
	{
		temp = data%r;
		sum = sum + temp*exp;
		exp = exp * r;
		data = data/r;
	}
	return sum;
}


/*
 *TB：to binary
 *m为待转化成二进制的数
 * 任意进制数转化为二进制数
 */

int TB(int m)
{
	if(m>0)
	{
		TB(m/2);
		printf("%d ",m%2);
	}
	else
		return;
}

int main()
{
int x = 0xff;
printf("%d \n",T(x,16));
TB(x);//将x转化为二进制数
printf("\n");

return 0;
}
