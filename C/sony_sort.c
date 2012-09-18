/************************************************************************

this program is the test of sony 
Author:justinzhang
Email:uestczhangchao@gmail.com
time:2011年9月20日23:57:56
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void sort();
int main()
{
	int arry[]={23,45,56,2,56,1,3,76,89,343};//数字任意
	int x = 0;
	printf("x=%#x\n",&x);
	printf("array=%#x\n",arry);
	asm volatile
	(
	"movl %%ebp,%0"
	:
	:"m"(x)
	);
	printf("in main ebp==%#x\n",x);
	printf("epb-4=%#x, epb-8=%#x\n",*((int *)(x-4)),*((int *)(x-4)));
	sort();
	return 0;
}

void sort()
{

	int *data = sort;
	int arr[10];
	int x = 111;
	
	//int *data2 = (int *)sort;
	int i,j, tmp;

	asm volatile
	(
	"movl 0(%%ebp),%%eax\n\t"
	"movl %%eax, %0\n\t"
	:
	:"m"(x)
	
	);
	printf("\nebp=%#x\n",x);
	printf("sort()=0x%x\n",sort);
	printf("&sort()=0x%x\n",&sort);

	printf("*data=0x%x\n",*data);
	//printf("*data2=0x%x\n",*data2);

	printf("data=0x%x\n",data);
	//printf("data2=0x%x\n",data2);
	printf("main()=%d\n",main);
	for(i=0; i<1000;i++)
	{
		 if (*(&data+i)==23)
		{ 
			printf("data[%d]=%d, address is:%#x\n",i,*(&data+i),&data+i);
			break;
		}
			
	}
	printf("last element=%#x\n", (&data+i+9));
	memcpy(arr,&data+i,sizeof(int)*10);
	printf("Get right position i=%d\n",i);

	for(i=0; i<10; i++)
	{
	    printf("%d\n",arr[i]);
	}
	for(i=0; i<10; i++)
	{
	    for(j=0; j<10-i-1; j++)
	    {
                if(arr[j]>arr[j+1])
		{
		    tmp = arr[j];
		    arr[j] = arr[j+1];
		    arr[j+1] = tmp;
		}
	    }
	}
	printf("after sort\n");

	for(i=0; i<10; i++)
	{
	    printf("%d\n",arr[i]);
	}
}


