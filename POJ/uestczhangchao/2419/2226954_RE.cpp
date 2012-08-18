#include"stdio.h"
main()
{
 int i,j,k;
 int p,t;
 int a[100],b[100];
 int c=0;
 scanf("%d %d",&p,&t);
 for(i=1;i<=2*p;i++)
 {
  scanf("%d %d",&a[i],&b[i]);
 }
 for(k=1;k<=t;k++)
 {
  for(j=1;j<=2*p;j++)
  {
	for(i=j+1;i<=2*p;i++)
	  if((a[i]!=a[j])&&(b[j]==k)&&(b[i]==k))
	  {
		  c++;
	goto next;
	  }
  }
 next:;
 }
 printf("%d",c);
}