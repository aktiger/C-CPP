/*
*This program is used to learn null pointer.
*from:嵌入式C精华
*时间：2011年8月17日20:18:15
*作者：张超
*Email:uestczhangchao@gmail.com
*
*/


#include "X:\编程练习\C-C++\global.h"

#if null_pointer==stdon

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

int *ptr;

if ((ptr=malloc(0))==NULL)
{
	printf("Get a NULL pointer.\n");
}
else
{
	printf("Get a valid pointer\n");
}

system("pause");
return 0;

}

#endif