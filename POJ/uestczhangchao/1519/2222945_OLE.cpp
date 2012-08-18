#include<iostream>
using namespace std;
int main()
{
	int  devide (int l);
	for(;;)	
	{int n,m;
		cin>>n;
		if(!n)  break;
	m=devide(n);
	
	while(m>=10)
	
	m=devide(m);
	cout<<m<<endl;
	
	}
	return 0;
}
int devide(int t)
{   int i=0,u;
	int c[18];
	int sum;
	u=t%10;
	c[0]=u;
while(t>=10)	
	{
	t=t/10;
int temp2;
	temp2=t%10;
	c[i+1]=temp2;
    i++;
}
sum=0;
for(int k=0;k<=i;k++)
{
sum=sum+c[k];
}
return sum;
}
