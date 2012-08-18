#include<iostream>
using namespace std;
int main()
{
long devide (int l);
	for(;;)	
	{long int n,m;
		cin>>n;
		if(!n)  break;
	m=devide(n);
	
	while(m>=10)
	
	m=devide(m);
	cout<<m<<endl;
	
	}
	return 0;
}
long int  devide(int t)
{   int i=0,u;
	long int c[20];
	long int sum;
	u=t%10;
	c[0]=u;
while(t>=10)	
	{
	t=t/10;
long int temp2;
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
