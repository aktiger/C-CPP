#include<stdio.h>
int a[11],total,m,n,t;

void try1(int x,int y)
{
int i;
if (x==0)
{
if (y-1<=n)
   total++;
}
else
  {
    for(i=1;i<=x;i++)
    {  if (i>=a[y-1])
	  {
	   a[y]=i;
	   try1(x-i,y+1);
	   a[y]=0;
	  }
     }
  }
}
main()
{
int i;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
scanf("%d %d",&m,&n);
total=0;
try1(m,1);
printf("%d\n",total);
}
}