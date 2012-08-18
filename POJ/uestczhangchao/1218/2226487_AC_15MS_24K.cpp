#include"stdio.h"
 main()
{
 int i,j,m;
 int n;
 int a[101];
 int y=0;
 scanf("%d",&y);
 for(m=0;m<y;m++)
 {
	  if(m)
		  printf("\n");
	 int k=0;
	 scanf("%d",&n);

 for(i=1;i<=n;i++)
{
 a[i]=0;
}
 for(i=1;i<=n;i++)
{
 for(j=1;j<=n;j++)
 {
 if(j%i==0)
 { 
  if(a[j]==0)
  a[j]=1;
  
  else if(a[j]==1)
  a[j]=0;
 } 
  }
  
 }
 for(i=1;i<=n;i++)
 {
  if(a[i])
  k++;
 }
 printf("%d",k);
 }

} 