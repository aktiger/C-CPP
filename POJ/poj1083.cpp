
/*
*ˮ��һ��~~ 
*ʱ�䣺2012��3��6��21:55:18
*���ߣ��ų�
*Email:uestczhangchao@gmail.com
*/

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;


int path[201];

int main()
{
	int nTestCase = 0;
	int nTable = 0;
	int s,t;
	int i,j,k;
	int count=0;

	cin >> nTestCase;

	for (i=0; i<nTestCase; i++)
	{
		cin >> nTable;
		memset(path,0,sizeof(path));

		for (j=0; j<nTable;j++)
		{
			cin >>s>>t;
			if(s>t)
				swap(s,t);
			s=(s+1)/2;
			t=(t+1)/2;
			for (k=s;k<=t;k++)
			{
				path[k]++;
			}

		}

		count = path[1];
		for (k=2;k<=200;k++)
		{
			if (path[k] > count )
			{
				count = path[k];
			}
		}
		cout << count*10 << endl;

	}


	return 0;
}