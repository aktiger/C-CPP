#define M 10
#include<iostream.h>
int main()
{int n;int c[M];int j=0,k;

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
c[j++]=sum;

}while(n!=-1);
for (k=0;k<j-1;k++)
cout<<c[k]<<" miles"<<endl;
 return 0;
}
