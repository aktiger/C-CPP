/*
Author:JustinZhang
Email:uestczhangchao@gmail.com
locale:14#102
Time:2012��4��22��16:08:42
From:2012��Ϊ��̴���������ڶ���
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

/*
input[]��һ���ַ��������������֡���ĸ��������ţ�Ҫ��ѵ��е����ֵ������򣻽���������output[]�С�
�磺ux0@9ab7yu2���Ϊ��ux0@2ab7yu7
˼·����input�а����г������ֵ�λ�ü�¼���������ҽ����г��ֵ����ַŵ�����һ�������н�������Ȼ���ź����
���飬���ݼ�¼�������ֵ�λ�ã�һ��һ���Ĳ��뵽output�С�

*/


void mysort(char input[], char output[])
{
	int m = strlen(input);
	int *location = new int [m];
	int *digital = new int [m];
	int digital_count = 0;
	int tmp = 0;
	//��¼�������ֵ�λ�ã����ҽ����ּ��е�digital[]������
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
	//ʹ�ò�������
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
	//���ź����������뵽output����
	for(int i=0; i<digital_count; i++)
	{
		output[location[i]] = digital[i] + '0';
	}
	output[m] = '\0';//�ֹ������ַ����������־����Ϊ�ַ����鲻���Զ���ĩβ���Ͻ�������
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