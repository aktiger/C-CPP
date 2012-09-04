/*
*Author:justinzhang
*Email:uestczhangchao@gmail.com
*Time:2011年5月11日15:58:40
*Discription:算法导论第7章，快速排序算法实现
			 change the previous c to cpp, and using template to make satisfy more data type
			 @Justin at:2012-9-4 21:57:52
*/

#include <iostream>
using namespace std;
/*交换两个数*/
template <typename T> void q_swap(T &x, T& y)
{
	T tmp = x;
	x = y;
	y= tmp;
}

/*以数组的最右边元素A[r]为主元对数组进行划分，返回pivot，pivot左边的元素都比A[r]小，右边的元素
*都比A[r]大；
*/
template <typename T> int partition(T A[],int p, int r)
{
	T x = A[r];
	int i=p-1;
	int j;
	for(j=p;j<=r-1;j++)
	{
		if(A[j]<x)
		{
			i++;
			q_swap<T>(A[i],A[j]);
		}
	}
	i++;
	q_swap(A[i],A[r]);
	return i;
}

/*利用partition不断的对数组进行划分，然后分别对划分后的两个部分进行排序(分治法思想)*/
template <typename T> void quicksort(T A[],int low, int high)
{
	int pivot;
	if(low<high)
	{
		pivot = partition<T>(A,low,high);
		quicksort(A,low,pivot-1);
		quicksort(A,pivot+1,high);
	}

}

int main()
{
	/*这里数组的下标从0开始*/
	int A[]={55,5,4,6,7,8,-444,4};
	int i;
	quicksort<int>(A,0,7);
	for(i=0;i<=7;i++)
		cout << A[i] << endl;

	/*----test double qsort----------*/
	cout << "test double quicksrot" << endl;
	double data[] = {1.0, -2.0, 3.0,4.5};
	quicksort<double>(data ,0, sizeof(data)/sizeof(double)-1);

	for(i=0;i<=sizeof(data)/sizeof(double)-1;i++)
		cout << data[i] << endl;

	return 0;
}

