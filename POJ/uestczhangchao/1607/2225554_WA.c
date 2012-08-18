#include <stdio.h>
void main()
{
	double r[100000],sum=0;
	long i,a[5];
	for (i=1;i<100000;i++)
	{
		sum+=1.000000/(2*i);
		r[i]=sum;
	}
	for(i=0;i<5;i++)
	    scanf("%d",&a[i]);
	printf("Cards  Overhang\n");
		for(i=0;i<5;i++)
          printf("%5ld%10.3f\n",a[i],r[a[i]]);
	
}
