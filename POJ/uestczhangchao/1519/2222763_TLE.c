#include<stdio.h>
int main(void)
{
	int n[20];
	int  i=0,j,k=0,t=0;
	int m[10];
	int sum[20];
	scanf("%d",&n[k]);
	while(n[k]!=0)
	{
		k++;
		scanf("%d",&n[k]);
	}
	for(i=0;i<k;i++)
		sum[i]=0;
	for(i=0;i<k;i++)
	{
	while(n[i]%10!=0)
	{
		m[t]=n[i]%10;
		n[i]/=10;
		t++;
	}
	for(j=0;j<t;j++)
		sum[i]+=m[j];
	t=0;
	while(sum[i]>=10)
	{
		while(sum[i]%10!=0)
		{
		m[t]=sum[i]%10;
        sum[i]/=10;
		t++;
		}
		for(j=0;j<t;j++)
			sum[i]+=m[j];
		t=0;
	}
	}
	for(i=0;i<k;i++)
		printf("%d\n",sum[i]);
	return 0;
}
		