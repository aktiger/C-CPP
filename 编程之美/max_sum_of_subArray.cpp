#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


//int flag = -1;//为0表示数组array的第i个元素被丢弃，为1表示数组array的第i个元素被选中
//
//int find_max_sum_of_subArray(int array[],int i, int j)
//{
//	if (i==j)
//	{
//		return array[i];
//	}
//	else
//	{
//		int tmp1 = find_max_sum_of_subArray(array,i+1,j);
//		int tmp2 = array[i] + find_max_sum_of_subArray(array,i+1,j);
//		if (tmp1 > tmp2)//tm1>tmp2,说明数组的第i个元素被丢弃掉了
//		{
//			flag = 0;
//			return tmp1;
//		}
//		else
//		{
//			if (flag ==0)//如果前一次数组第i给元素被丢弃，那么说明已经不是连续的子元素，要重新计算
//			{
//				flag = 1;
//				return tmp1;
//			}
//			else
//			{
//				return tmp2;
//			}
//			
//		}
//	}
//}

int partition(int array[], int len)
{
	int front = -1;
	int tmp;
	for (int i=0; i<len; i++)
	{
		if (array[i] < 0)
		{
			front++;
			tmp = array[i];
			array[i] = array[front];
			array[front] = tmp;
		}
	}
	return front+1;
}

int liner_find_max_sum_of_subArray(int array[], int len)
{
	int max_number = INT_MIN;
	int first_positive_position = partition(array, len);
	if (first_positive_position >len-1)//没有正数
	{
		for (int i=0; i<len; i++)
		{
			if (array[i] > max_number)
			{
				max_number = array[i];
			}
		}
		return max_number;
	}
	else //正数集合不为空，将所有正数都加起来就行了
	{
		
	}
}



int sum(int array[], int i, int j)
{
	int s = 0 ;
	for (int ii=i; ii<=j; ii++)
	{
		s = s + array[ii];
	}
	return s;
}

int ma = INT_MIN;
int find_max_sum_of_subArray(int array[],int i, int j)
{
	for (int ii=0; ii<=j; ii++)
	{
		for (int jj=ii; jj<=j; jj++)
		{
			int tmp = sum(array,ii,jj);
			if ( tmp > ma)
			{
				ma = tmp;
			}
		}
	}
	return ma;
	
}

int max_sum(int *A, int len)
{
	int nstart = A[len-1];
	int nall = A[len-1];
	for (int i=len-2; i>=0; i--)
	{
		if (nstart < 0)
		{
			nstart = 0;
		}

		nstart = nstart + A[i];
		if (nstart > nall)
		{
			nall = nstart;
		}
	}
	return nall;	

}
int main()
{
	int array[] = {-2, 5, 3,-6, 4, -8, 16};
	cout << "find_max_sum_of_subArray:" << find_max_sum_of_subArray(array,0,6) << endl;

	/*int x = partition(array,7);
	cout << "x= " << x << endl; 
	for (int i=0; i<7; i++)
	{
		cout << setw(3) << array[i] ;
	}
	cout << endl;*/

	cout << "max_sum:" << max_sum(array, 7) << endl;

	return 0;
}