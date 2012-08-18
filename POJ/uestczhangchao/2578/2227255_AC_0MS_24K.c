#include"stdio.h"
main()
{
 int i,j,k;
 scanf("%d%d%d",&i,&j,&k);
 if(i>168&&j>168&&k>168)
  printf("NO CRASH\n");
 if(i<=168)
 {printf("CRASH %d\n",i);goto next;}
 if(j<=168)
 {  printf("CRASH %d\n",j);goto next;}
 if(k<=168)
 {	 printf("CRASH %d\n",k);goto next;}
next:;
}