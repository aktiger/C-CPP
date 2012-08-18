#define M 5
#include<iostream>
using namespace std;
int main()
{
	int sum(int *);
	int a[M],b[M],c[M];
	int x,y,z,m;
for(m=2992;m>=2992&&m<=9999;m++)
{
a[0]=m/1000;
a[1]=(m/100)%10;
a[2]=(m/10)%10;
a[3]=m%10;
a[4]='\0';

b[0]=m%12;
b[1]=(m/12)%12;
b[2]=((m/12)/12)%12;
b[3]=(((m/12)/12)/12)%12;
b[4]='\0';

c[0]=m%16;
c[1]=(m/16)%16;
c[2]=((m/16)/16)%16;
c[3]=(((m/16)/16)/16)%16;
c[4]='\0';

x=sum(a);
y=sum(b);
z=sum(c);

if(x==y&&y==z)
cout<<m<<endl;
}
cout<<"..."<<endl;
return 0;
}

int sum(int *p)
{int sm=0;
int i;
for(i=0;p[i]!='\0';i++)
sm=sm+p[i];
return sm;
}