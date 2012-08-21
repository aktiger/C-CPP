/*
*Author:justinzhang
*Email:uestczhangchao@gmail.com
*Time:2011年5月11日16:17:52
*Discription:冒泡排序算法
*/


#include<stdio.h>

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void bubblesort(int A[],int len)
{
	int i,j;
	int flag = 0;
	for(i=1; i<=len-1;i++)
	{
		flag = 0;
		for(j=1;j<=len-i;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(&A[j],&A[j+1]);
				flag = 1;
			}
		}

		if(flag==0)
			break;
	}
	
}


int main()
{
	/*数组元素从0开始存放*/
	int A[] = {0,5,6,7,-3,555,88};
	int i;
	bubblesort(A,6);
	for(i=1; i<=6;i++)
		printf("%d\n",A[i]);
	system("pause");
	return 0;
}
