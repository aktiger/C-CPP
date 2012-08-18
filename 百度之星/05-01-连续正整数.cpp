/************************************************************************
* Author:justinzhang
* Email:uestczhangchao@gmail.com
* Time：2011年5月26日19:42:29
* Discription:百度之星-05年，第一题，一个整数可以表示为n个连续整数之和。
************************************************************************/
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		cout << "请输入一个正整数"<<endl;
		exit(0);
	}
	int num = atoi(argv[1]);
	int sum = 0;
	int half = num/2 + 1;
	int i,j,k;
	int flag = 0;
	for(i=1;i<=half;i++)
	{
		sum = 0;
		for(j=i;j<=half;j++)
		{
			sum += j;
			if (sum == num)
			{
				flag = 1;
				break;
			}
		}
		
		if (sum == num)
		{
			for (k=i;k<=j;k++)
			{
				cout << k << " ";
			}
			cout << endl;
		}
		

	}
	if (flag == 0)
	{
		cout << "NONE" << endl;
	}
	
	return 0;
}