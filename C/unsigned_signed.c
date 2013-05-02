#include<stdio.h>

int main()
{
int	 i  = 0xffffffff;
int a[]	    = {1,2,3,4};
int	 xx = 0xfffffffe;
int	*p  = a+1;
printf("a-1 = %p\n", a-1);
printf("a = %p\n",a);
printf("a+1 = %p\n",a+1);
printf("a+4 = %p\n",a+4);
printf("a+5 = %p\n",a+5);
printf("&i = %p\n", &i);
printf("&xx = %p\n", &xx);
printf("p[-1] = %d\n",p[-1]);
printf("a[-1] %d\n",a[-1]);
unsigned char x = -1;
printf("the value of a+5 is %d\n",a[5]);
printf("x = %d\n",x);
printf("%d\n",-1%256);
return 0;
}
