#include<iostream>
using namespace std;
int main()
{double a[10];double sum1[10],s;

	int fun(int);
for(int i=0;i<=9;i++)
{a[i]=fun(i);}
for(i=0;i<=9;i++)
{s=0.0;
	
	
	for(int j=0;j<=i;j++)
	{
		s=s+1.0/a[j];
	}
    
sum1[i]=s;	
}
printf("n e\n");
printf("- -----------\n");
for(int k=0;k<2;k++)
{
	printf("%d %1.0f\n",k,sum1[k]);
}
printf("%d %2.1f\n",2,sum1[2]);
for(k=3;k<=9;k++)
{
	
	printf("%d %11.9f\n",k,sum1[k]);
}


return 0;
}
int fun(int n)
{int m;
if(n==0)
m=1;
else m=n*fun(n-1);
return m;
}