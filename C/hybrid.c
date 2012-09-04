/*
@@
	Author:	Justinzhang
	Email:	uestczhangchao@gmail.com
	Time:	2012-9-4 20:38:18
	Desc:	hybrid c problem meet during job hunting era.:(
@@
*/
#include <stdio.h>

/* convert a oct number to decimal number */
int oct2dec(int oct)
{
	int sum = 0;
	int scale = 1;
	while(oct)
	{
		int tmp = oct%10;
		sum = sum + tmp * scale;
		oct = oct/10;
		scale = scale * 8;
	}
	return sum;
}


int main()
{
	/* using printf to print unmatched parameters */
	printf("%f\n", 5); // we will get 0.000000
	printf("%d\n", 5.01); // we will get a huge number
	/*----------------invinsible split line---------------------*/

	/*----------------test oct2dec---------------------------*/
	printf("%d\n",oct2dec(700));

	return 0;
}