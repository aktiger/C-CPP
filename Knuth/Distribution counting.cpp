#include <iostream>
using namespace std;

/*
*From the art of computer programming:vol 3:Sorting and Searching
*ʱ�䣺2012��3��6��21:02:32
*���ߣ��ų�
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
	

	//ͳ��array�ڵ�������minvalue��maxvalue��Χ�ĳ��ִ���
	for (i=0; i<arraylen; i++)
	{
		count[array[i]-minvalue]++;
	}

	//ͳ��minvalue��maxvalue��Χ�ڣ���С�ڸ÷�Χ��ĳ�����ĳ���Ƶ��
	//count[i]��ӦС��value+i�������ֵĴ���
	for (i=1; i<valuescope; i++)
	{
		count[i] = count[i] + count[i-1];
	}

	//�������ÿ�����֣������˳��Ϊnon-descending˳�򣬲��ұ�֤�������
	for (j=arraylen-1;j>=0;j--)
	{
		////ȡ���ùؼ��ֳ��ֵĴ���
		i = count[array[j]-minvalue];
		tmp[i-1] = array[j];
		--count[array[j]-minvalue];

	}

	//�����������array������
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