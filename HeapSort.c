/*
*Author:justinzhang
*Email:uestczhangchao@gmail.com
*Discription:ʵ���㷨���۵����µĶ������㷨
*Time:2011��5��11��15:39:30
*/


#include <stdio.h>

void swap(int *x,int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//������iΪ���ڵ�Ĵ󶥶�
void Max_Heapify(int A[], int i,int heapsize)
{
	int l=2*i;//ȡi������
	int r=2*i+1;//ȡi���Һ���
	int largest;//��¼���ڵ㡢���ӡ��к��������һ��������
	

	if(l<=heapsize && A[l]>A[i])
		largest = l;
	else
		largest = i;

	if(r<=heapsize && A[r]>A[largest])
		largest = r;

	if(largest!= i)
	{
		swap(&A[i],&A[largest]);//�����Ԫ�طŵ����ڵ���
		Max_Heapify(A,largest,heapsize);//���ڸ�Ϊlargest�Ķ��п��ܱ��ƻ����ݹ���е���
	}
	
}

//������ʼ��
void Build_Max_Heap(int A[],int heapsize)
{
	int i;
	//�����ڲ��ڵ�(��Ҷ�ӽڵ�Ľڵ�)Ϊn/2
	//�������ڲ��ڵ㵽�������ĸ��ڵ㽨���󶥶�
	for(i=heapsize/2;i>=1;i--)
	{
		Max_Heapify(A,i,heapsize);
	}

}

//�������㷨
void HeapSort(int A[],int len)
{
	int i;
	Build_Max_Heap(A,len);
	//���ϵĽ��Ѷ�Ԫ��������������Ϊlen��Ԫ�ؽ���
	for(i=len;i>=2;i--)
	{
		swap(&A[1],&A[len]);
		len--;
		Max_Heapify(A,1,len);
	}
}

int main()
{
	//���������±��1��ʼ�������һ��Ԫ��û��ʹ��
	int A[] = {0,-12,5,55,5,4,3,2,1};
	int i;
	HeapSort(A,5);
	for(i=1;i<=5;i++)
		printf("%d\n",A[i]);
	 system("pause");
	return 0;
}


