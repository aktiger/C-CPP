#include <stdio.h>
void main()
{
	double r[100000],sum=0;
	long i,n;
	for (i=1;i<100000;i++)
	{
		sum+=1.000000/(2*i);
		r[i]=sum;
	}
scanf("%d",&n);
	printf("Cards  Overhang\n");
	
		printf("%5ld%10.3f\n",n,r[n]);
}
