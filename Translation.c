#include <stdio.h>

/*
 * �����������ת��Ϊʮ������
 * data Ϊԭʼ����rΪԭʼ���ݵĽ�����
 */

int T(int data, int r)
{
	int temp = 0;
	int exp = 1;
	int sum = 0;
	while(data!=0)
	{
		temp = data%r;
		sum = sum + temp*exp;
		exp = exp * r;
		data = data/r;
	}
	return sum;
}


/*
 *TB��to binary
 *mΪ��ת���ɶ����Ƶ���
 * ���������ת��Ϊ��������
 */

int TB(int m)
{
	if(m>0)
	{
		TB(m/2);
		printf("%d ",m%2);
	}
	else
		return;
}

int main()
{
int x = 0xff;
printf("%d \n",T(x,16));
TB(x);//��xת��Ϊ��������
printf("\n");

return 0;
}
