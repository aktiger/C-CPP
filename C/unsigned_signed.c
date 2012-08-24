#include<stdio.h>

int main()
{
int i = -888;
int a[] = {1,2,3,4};
int xx = -7777;
int *p = a+1;
printf("%d\n",p[-1]);
printf("%d\n",a[-1]);
unsigned char x = -1;
printf("%d\n",x);
printf("%d\n",-1%256);
return 0;
}
