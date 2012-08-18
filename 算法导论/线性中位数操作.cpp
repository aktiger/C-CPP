/*
Author:JustinZhang
Email:uestczhangchao@gmail.com
Time:2012年4月24日16:37:22
End:2012年4月24日22:33:01
Dess:算法导论第九章中线性时间选出第i大的算法；算法导论本身没有给出算法伪代码，只是给出了算法思想；
在解决编程之美上一道关于点对最短距离时，需要利用中位数对点集合进行划分，这样才能保证被划分的集合大小基本相等；
纵观网络上大多数博客，未发现满意的实现，所以没办法，只好自己写一下，有错误的地方，还望大家批评指正~~
*/

#include <iostream>
#include <iomanip>
using namespace std;


void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void insert_sort(int A[], int p, int r)
{
	int i,j;
	int key = 0;
	for (i=p+1; i<=r; i++)
	{
		key = A[i];
		j = i - 1;
		while (j>=p && A[j]>key)
		{
			A[j+1] = A[j];//将A[j]往前移动
			j--;
		}
		A[j+1] = key;
	}
}


int partion(int A[],int p, int r)
{
	int count = p - 1;
	int key = A[r];

	for (int i=p; i<=r-1; i++)
	{
		if (A[i] < key)
		{
			count++;
			swap(A[count],A[i]);
		}
	}
	swap(A[count+1],A[r]);
	return count+1;
}


int get_median(int data[], int p, int r)
{
	int i=0, j=0;
	int n = r - p + 1;            //获得原始数组数据个数
	int remains = n%5;
	int int_count = n - remains;
	int int_group = int_count/5;
	int group_count = (n+4)/5;   //计算出五个元素一组的组数；
	
	int *group_median = new int[group_count];
	
	if (p==r)
	{
		return data[p];
	}
	memset(group_median,0,group_count);      //对动态申请的内存清零
	
	//以下代码求出五个元素为一组的中位数
	if (0 == remains) //如果元素的个数正好可以分为以5个元素为单位的整数组
	{
		for (i=p; i<=r-4; i=i+5)
		{
			insert_sort(data, i, i+4);
			group_median[(i-p)/5] = data[p+2];
		}
	}
	else
	{
		for (i=p; i<=(r-remains-4);i=i+5)
		{
			insert_sort(data, i, i+4);
			group_median[(i-p)/5] = data[i+2];
		}
		//处理不够5个元素的组，改组开始的序号为r-remains+1，结束序号为r
		insert_sort(data,r-remains+1,r);
		group_median[group_count-1] = data[r-remains+1+remains/2];
	}

	/*cout <<"group_median:"<< endl;
	for (j=0; j<group_count; j++)
	{
		cout <<group_median[j] << setw(3);
	}
	cout << endl;*/
	if (group_count==1)
	{
		return group_median[0];
	}
	else
	{
		return get_median(group_median,0,group_count-1);
	}

	delete [] group_median;
	return 0;
}

/*就是因为get_position函数写错了，导致很久都没有能够发现错误，要仔细啊~~*/
int get_position(int A[], int p, int r, int key)
{
	for (int i=p; i<=r; i++)
	{
		if (A[i]==key)
		{
			return i;
		}
	}

	return -1;
}

//该函数是为了找到数组A中，第seq小的数
int select(int A[],int p, int r, int seq)
{
	//获得数组A的中位数的中位数，将其作为划分数组的支点
	int pivot_key = get_median(A, p, r);
	int pos = get_position(A,p,r,pivot_key);
	swap(A[pos],A[r]);
	int i = partion(A, p, r);
	int x = i - p + 1;
	if (seq == x)
	{
		return A[i];
	}
	else if (seq < x)
	{
		select(A, p, i-1, seq);
	}
	else
	{
		select(A, i+1, r, seq-x);
	}

}


int main()
{
	int arrays[] = {23,13,12,14,11,8,9,20,7,4,5,6,2,1,3};
	int size = sizeof(arrays) / sizeof(int);

	for (int i=1; i<=size; i++)
	{
			cout << "select "<<i<<"->"<< select(arrays,0,size-1,i) << endl;


	}

	return 0;
}