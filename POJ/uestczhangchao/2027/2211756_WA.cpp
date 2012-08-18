
#define M 10
#include<iostream.h>
int main()
{int n;int i=0;
cin>>n;
int a[M];
while(i<n)
{
	int x,y;
	cin>>x;
cin>>y;
if(x>=y)
a[i++]=0;
else a[i++]=1;
}
for (i=0;i<n;i++)
{if(a[i])
cout<<"NO BRAINS"<<endl;
else cout<<"MMMM BRAINS"<<endl;
}
return 0;
}