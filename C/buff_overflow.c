

//#include "X:\�����ϰ\C-C++\global.h"

//#if buffer_overflow==stdon
//buffer overflow example 

#include <stdio.h>
#include <stdlib.h>

//typedef void (*PF)(void);

void why_here(void) //�������û���κεط����ù� 
{
printf("why u here !n\n");
printf("you are traped here\n");
system("pause");
_exit(0);
}


int main(int argc,char * argv[])
{


int buff[1];
buff[3] =0x41111d;
//PF ff = 0x004113c0;
//ff();
//buff[3] = why_here;
//printf("why_here=0x%x\n",why_here);
//printf("&why_here=0x%x\n",&why_here);

system("pause");
return 0;
}
//#endif