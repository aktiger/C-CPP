/*
*Author:justinzhang
*Email:uestczhangchao@gmail.com
*Discription:实现算法导论第六章的堆排序算法
*Time:2011年5月11日15:39:30
*/


#include <stdio.h>

void swap(int *x,int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//建立以i为根节点的大顶堆
void Max_Heapify(int A[], int i,int heapsize)
{
	int l=2*i;//取i的左孩子
	int r=2*i+1;//取i的右孩子
	int largest;//记录根节点、左孩子、有孩子中最大一个的索引
	

	if(l<=heapsize && A[l]>A[i])
		largest = l;
	else
		largest = i;

	if(r<=heapsize && A[r]>A[largest])
		largest = r;

	if(largest!= i)
	{
		swap(&A[i],&A[largest]);//将最大元素放到根节点上
		Max_Heapify(A,largest,heapsize);//处于根为largest的堆有可能被破坏，递归进行调整
	}
	
}

//建立初始堆
void Build_Max_Heap(int A[],int heapsize)
{
	int i;
	//最大的内部节点(有叶子节点的节点)为n/2
	//从最大的内部节点到整棵数的根节点建立大顶堆
	for(i=heapsize/2;i>=1;i--)
	{
		Max_Heapify(A,i,heapsize);
	}

}

//堆排序算法
void HeapSort(int A[],int len)
{
	int i;
	Build_Max_Heap(A,len);
	//不断的将堆顶元素与数组中索引为len的元素交换
	for(i=len;i>=2;i--)
	{
		swap(&A[1],&A[len]);
		len--;
		Max_Heapify(A,1,len);
	}
}

int main()
{
	//这里数组下标从1开始，数组第一个元素没有使用
	int A[] = {0,-12,5,55,5,4,3,2,1};
	int i;
	HeapSort(A,5);
	for(i=1;i<=5;i++)
		printf("%d\n",A[i]);
	 system("pause");
	return 0;
}


