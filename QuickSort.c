/*
*Author:justinzhang
*Email:uestczhangchao@gmail.com
*Time:2011��5��11��15:58:40
*Discription:�㷨���۵�7�£����������㷨ʵ��
*/

#include "X:\�����ϰ\C-C++\global.h"

#if quick_sort==stdon

#include <stdio.h>
/*����������*/
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y= tmp;
}

/*����������ұ�Ԫ��A[r]Ϊ��Ԫ��������л��֣�����pivot��pivot��ߵ�Ԫ�ض���A[r]С���ұߵ�Ԫ��
*����A[r]��
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

/*����partition���ϵĶ�������л��֣�Ȼ��ֱ�Ի��ֺ���������ֽ�������(���η�˼��)*/
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
	/*����������±��0��ʼ*/
	int A[]={55,5,4,6,7,8,444,4};
	int i;
	quicksort(A,0,7);
	for(i=0;i<=7;i++)
		printf("%d\n",A[i]);
	system("pause");
	return 0;
}

#endif