/*
Author:JustinZhang
Email:uestczhangchao@gmail.com
Time:2012��4��22��23:39:40
desc:�߾��ȼӷ�
*/

#include <iostream>
#include <cstring>
using namespace std;

/*
a��bΪ�ַ����飬�ڲ��洢�˼����ͱ�������ans����������ս����ҲΪ�ַ�����
*/
void arbitary_add(const char *a, const char *b,char *ans)
{
	int lena = strlen(a);
	int lenb = strlen(b);
	int maxlen = (lena > lenb) ? lena : lenb; //������������������
	int *arrayA = new int [maxlen+1];
	int *arrayB = new int [maxlen+1];
	
	int *intans = new int [maxlen+1];//������������ַ�����������ӵĽ��
	int i=0,j=0;

	//�Լӷ��Ľ����������
	for(i=0; i<maxlen+1; i++)
	{
		intans[i] = 0;
		arrayA[i] = 0;
		arrayB[i] = 0;
	}

	//�������ַ����е�����ȡ�������ŵ��������鵱�У��ַ�����ĵ�һ���ַ���Ӧ�����������λ.
	for(i=0; i<lena; i++)
	{
		arrayA[lena-i-1] = a[i] - '0';
	}
	//���������ַ����е�����ȡ�������ŵ��������鵱�У��ַ�����ĵ�һ���ַ���Ӧ�����������λ.
	for(j=0; j<lenb; j++)
	{
		arrayB[lenb-j-1] = b[j] - '0';
	}
	//��������õ����������飬һλһλ�����ӷ�����
	for(i=0; i<maxlen; i++)
	{
		intans[i] += arrayA[i]+ arrayB[i];
		
		//�����iλ�Ľ������10����ô�����i+1λ��λ
		if(intans[i] > 9)
		{
			intans[i] = intans[i] - 10;
			intans[i+1] = intans[i+1] + 1;
		}
	}

	//������λ�н�λ
	if(intans[maxlen]!=0)
	{
		ans[0] = intans[maxlen]+'0';
		//����������ת��Ϊ�ַ�����
		for(i=1; i<=maxlen;i++)
		{
			ans[i] = intans[maxlen-i]+'0';
		}
		ans[maxlen+1] = '\0';
	}
	else
	{
		//����������ת��Ϊ�ַ�����
		for(i=0; i<maxlen;i++)
		{
			ans[i] = intans[maxlen-i-1]+'0';
		}
		ans[maxlen] = '\0';
	}
	delete [] arrayA;
	delete [] arrayB;
	delete [] intans;
}

int main()
{
	int count = 0;
	char *ans = new char[20];
	char *s1 = "1239945";
	char *s2 = "79999999";
	arbitary_add(s1,s2,ans);
	while(ans[count]!='\0')
	{
		cout << ans[count++] ;
	}
	cout << endl;
	delete [] ans;
	return 0;
}