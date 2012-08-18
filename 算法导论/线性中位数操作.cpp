/*
Author:JustinZhang
Email:uestczhangchao@gmail.com
Time:2012��4��24��16:37:22
End:2012��4��24��22:33:01
Dess:�㷨���۵ھ���������ʱ��ѡ����i����㷨���㷨���۱���û�и����㷨α���룬ֻ�Ǹ������㷨˼�룻
�ڽ�����֮����һ�����ڵ����̾���ʱ����Ҫ������λ���Ե㼯�Ͻ��л��֣��������ܱ�֤�����ֵļ��ϴ�С������ȣ�
�ݹ������ϴ�������ͣ�δ���������ʵ�֣�����û�취��ֻ���Լ�дһ�£��д���ĵط��������������ָ��~~
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
			A[j+1] = A[j];//��A[j]��ǰ�ƶ�
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
	int n = r - p + 1;            //���ԭʼ�������ݸ���
	int remains = n%5;
	int int_count = n - remains;
	int int_group = int_count/5;
	int group_count = (n+4)/5;   //��������Ԫ��һ���������
	
	int *group_median = new int[group_count];
	
	if (p==r)
	{
		return data[p];
	}
	memset(group_median,0,group_count);      //�Զ�̬������ڴ�����
	
	//���´���������Ԫ��Ϊһ�����λ��
	if (0 == remains) //���Ԫ�صĸ������ÿ��Է�Ϊ��5��Ԫ��Ϊ��λ��������
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
		//������5��Ԫ�ص��飬���鿪ʼ�����Ϊr-remains+1���������Ϊr
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

/*������Ϊget_position����д���ˣ����ºܾö�û���ܹ����ִ���Ҫ��ϸ��~~*/
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

//�ú�����Ϊ���ҵ�����A�У���seqС����
int select(int A[],int p, int r, int seq)
{
	//�������A����λ������λ����������Ϊ���������֧��
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