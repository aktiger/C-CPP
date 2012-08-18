#include"stdio.h"
#include"math.h"
 int a[5][9];
void main()
{
 int i,j,k;
 int y,x;
 char c;
 scanf("%d",&y);
 getchar();
 for(x=1;x<=y;x++)
 {j=1;
  for(i=1;i<=32;i++)
  { c=getchar();
  if(c=='\n')
	  break;
  if(j==1)
	  a[j][i]=c-'0';

  if(j!=1)  
  a[j][i-(j-1)*8]=c-'0';
   if(i%8==0)
 {
   j++;
 }
   
 }
  
 for(k=1;k<=4;k++)
  {  
  
   for(j=7;j>=0;j--)
   a[k][0]=a[k][0]+a[k][j+1]*pow(2,7-j);
  }
 for(k=1;k<=4;k++)
 {
 printf("%d",a[k][0]);  
 if(k!=4)
 printf(".");
 }
 printf("\n");
 for(i=1;i<=4;i++)
 {
 for(j=0;j<=8;j++)
 a[i][j]=0;
 }
 }
} 