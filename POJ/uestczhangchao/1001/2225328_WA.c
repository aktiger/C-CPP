#include"stdio.h"
#include"math.h"
long  a[1000];
long  b[1000];
main()
{
 int i,j,k,m;
 float x;
 long unsigned g,h,r;
 int n;

 scanf("%f %d",&x,&n);

 x=x*10000.0;
 g=x;
 if(n==0)
 goto next;
 h=g;
 for(i=1;;i++)
 {
  r=10;
  a[i]=h%r;
  h=h-a[i];
  h=h/10;

  if(h==0)
  break;
 }
 i=i+50;
 for(j=2;j<=n;j++,i=i+10)
 {
  for(k=1;k<=i;k++)
  {
   a[k]=a[k]*g;
  }
  for(k=1;k<=i;k++)
  {
   a[k+1]=a[k+1]+a[k]/10;
   a[k]=a[k]%10;
  }
 }
 for(j=i;j>4*n+1;j--)
 if((a[j+1]==0)&&(a[j]!=0))
 break;
 for(m=1;m<=4*n;m++)
 {
 if(a[m]!=0)
 break;
 if((a[m+1]!=0)&&(a[m]==0))
  {m++;
 break;
  }
 }
 if(j==4*n+1)
 {j--;}
  for(;j>=m;j--)
 {
 if(j-4*n==0)
 printf(".");
 printf("%d",a[j]);
 }
 next:
 if(n==0)
 printf("1"); 
 printf("\n");
}