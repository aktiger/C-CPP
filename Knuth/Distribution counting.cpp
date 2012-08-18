#include <iostream>
using namespace std;

/*
*From the art of computer programming:vol 3:Sorting and Searching
*时间：2012年3月6日21:02:32
*作者：张超
*Email:uestczhangchao@gmail.com
*/


void Distribution_Counting(int array[], int arraylen)
{
	int *tmp = new int[arraylen];
	int *count = NULL;
	int i,j;
	int minvalue=INT_MAX, maxvalue=INT_MIN;
	int valuescope;
	memset(tmp,0,sizeof(int)*arraylen);

	
	for (i=0; i<arraylen; i++)
	{
		if (array[i]<minvalue)
		{
 			minvalue=array[i];
		}
		if (array[i]>maxvalue)
		{
			maxvalue = array[i];
		}
		
	}

	valuescope = maxvalue-minvalue+1;
	count = new int[valuescope];


	memset(count,0,sizeof(int)*valuescope);
	

	//统计array内的数字在minvalue和maxvalue范围的出现次数
	for (i=0; i<arraylen; i++)
	{
		count[array[i]-minvalue]++;
	}

	//统计minvalue和maxvalue范围内，不小于该范围内某个数的出现频数
	//count[i]对应小于value+i的数出现的次数
	for (i=1; i<valuescope; i++)
	{
		count[i] = count[i] + count[i-1];
	}

	//依次输出每个数字，输出的顺序为non-descending顺序，并且保证是有序的
	for (j=arraylen-1;j>=0;j--)
	{
		////取出该关键字出现的次数
		i = count[array[j]-minvalue];
		tmp[i-1] = array[j];
		--count[array[j]-minvalue];

	}

	//将结果拷贝到array数组中
	for (i=0; i<arraylen; i++)
	{
		array[i] = tmp[i];
	}

	delete []tmp;
	delete []count;

}




int main()
{
	int data[] = {8,5,4,5,6,10};
	int size = sizeof(data)/sizeof(int);
	Distribution_Counting(data,size);
	for(int i=0; i<size;i++)
	{
		cout <<" " << data[i] << " ";
	}
	cout << endl;

	return 0;
}