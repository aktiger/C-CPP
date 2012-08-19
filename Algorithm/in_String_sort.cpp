/*
Author:JustinZhang
Email:uestczhangchao@gmail.com
locale:14#102
Time:2012年4月22日16:08:42
From:2012华为编程大赛下午组第二题
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

/*
input[]是一个字符串，其中有数字、字母、特殊符号，要求把当中的数字递增排序；将结果存放在output[]中。
如：ux0@9ab7yu2输出为：ux0@2ab7yu7
思路：将input中把所有出现数字的位置记录下来，并且将所有出现的数字放到另外一个数组中进行排序，然后将排好序的
数组，根据记录的有数字的位置，一个一个的插入到output中。

*/


void mysort(char input[], char output[])
{
	int m = strlen(input);
	int *location = new int [m];
	int *digital = new int [m];
	int digital_count = 0;
	int tmp = 0;
	//记录出现数字的位置，并且将数字集中到digital[]数组中
	for(int i=0; i<m; i++)
	{
		if(input[i]>='0' && input[i]<='9')
		{
			location[digital_count] = i;
			digital[digital_count] = input[i] - '0';
			digital_count++;
		}
		output[i] = input[i];
	}
	//使用插入排序
	for(int i=1; i<digital_count; i++)
	{
		for(int j=i; j>0; j--)
		{
			if(digital[j] < digital[j-1])
			{
				tmp = digital[j];
				digital[j] = digital[j-1];
				digital[j-1] = tmp;
			}
		}
	}
	//将排好序的数组插入到output当中
	for(int i=0; i<digital_count; i++)
	{
		output[location[i]] = digital[i] + '0';
	}
	output[m] = '\0';//手工加上字符数组结束标志，因为字符数组不会自动在末尾加上结束符；
	delete [] location;
	delete [] digital;
}


int main()
{
	int index = 0;
	char input[] = "u8x9@0ab7yu2";
	char *output = new char[strlen(input)+1];
	mysort(input,output);
	while(output[index] != '\0')
	{
		cout << output[index++];
	}
	cout << endl;
	delete [] output;
	return 0;
}