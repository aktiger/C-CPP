/*
*Author:justinzhang
*Email:uestczhangchao@gmail.com
*Time:2011年5月11日15:58:40
*Discription:算法导论第7章，快速排序算法实现
*/

#include "X:\编程练习\C-C++\global.h"

#if quick_sort==stdon

#include <stdio.h>
/*交换两个数*/
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y= tmp;
}

/*以数组的最右边元素A[r]为主元对数组进行划分，返回pivot，pivot左边的元素都比A[r]小，右边的元素
*都比A[r]大；
*/
int partition(int A[],int p, int r)
{
	int x = A[r];
	int i=p-1;
	int j;
	for(j=p;j<=r-1;j++)
	{
		if(A[j]<x)
		{
			i++;
			swap(&A[i],&A[j]);
		}
	}
	i++;
	swap(&A[i],&A[r]);
	return i;
}

/*利用partition不断的对数组进行划分，然后分别对划分后的两个部分进行排序(分治法思想)*/
void quicksort(int A[],int low, int high)
{
	int pivot;
	if(low<high)
	{
		pivot = partition(A,low,high);
		quicksort(A,low,pivot-1);
		quicksort(A,pivot+1,high);
	}

}

int main()
{
	/*这里数组的下标从0开始*/
	int A[]={55,5,4,6,7,8,444,4};
	int i;
	quicksort(A,0,7);
	for(i=0;i<=7;i++)
		printf("%d\n",A[i]);
	system("pause");
	return 0;
}

#endif