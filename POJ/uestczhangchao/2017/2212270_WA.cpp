#define M 10
#include<iostream.h>
int main()
 {int n;

do{
int a[M];int i=0;int sum;int p,m;int b[M];
cin>>n;
while(i<n)
{
int x,y;
cin>>x;
cin>>y;
b[i]=y;
if(i>0)
{p=y-b[i-1];
m=x*p;
a[i]=m;
}
else{ m=x*y;a[i]=m;}
i++;
}


for(i=0,sum=0;i<n;i++)
{
sum=sum+a[i];
}
cout<<sum<<" miles"<<endl;
}while(n!=-1);
 return 0;
}
