/*
*This program is used to learn null pointer.
*from:Ƕ��ʽC����
*ʱ�䣺2011��8��17��20:18:15
*���ߣ��ų�
*Email:uestczhangchao@gmail.com
*
*/


#include "X:\�����ϰ\C-C++\global.h"

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