

/************************************************************************

this program is the test of sony 
Author:justinzhang
Email:uestczhangchao@gmail.com
time:2011年9月20日23:57:56
************************************************************************/

#include "X:\编程练习\C-C++\global.h"

#if sony_sort==stdon

#include <stdio.h>

void sort();
int main()
{
	int arry[]={23,45,56,2,56,1,3,76,89,343};//数字任意
	sort();
	return 0;
}

void sort()
{

	int *data = sort;
	//int *data2 = (int *)sort;
	int i;
	printf("sort()=0x%x\n",sort);
	printf("&sort()=0x%x\n",&sort);

	printf("*data=0x%x\n",*data);
	//printf("*data2=0x%x\n",*data2);

	printf("data=0x%x\n",data);
	//printf("data2=0x%x\n",data2);

	for(i=0; i<1000;i++)
	{
		 if (*(&data+i)==23)
		{ 
			printf("array[%d]=%d\n",i,*(&data+i));
			break;
		}
			
	}

	printf("Get right position i=%d\n",i);

}


#endif