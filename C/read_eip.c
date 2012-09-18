#include <stdio.h>

int main()
{

int x = 0;
int eip = 0;
int cs = 0;
__asm__ __volatile__(
"movl %%ebp, %0\n\t"
"push %%cs\n\t"
"pop %%eax\n\t"
"movl %%eax, %1\n\t"
"call here\n\t"
"here:	pop %%eax\n\t"
"movl %%eax,%2"
:
:"m"(x),"m"(cs),"m"(eip)
:"memory"
);
printf("ebp==%#x,cs=%#x,eip=%#x\n",x,cs,eip);
 
return 0;
}

