/************************************************************************
*Author:justinzhang
*Time:2011��5��18��23:34:26
*Discription��������:��121�ǻ�������123���ǻ����������������Զ���һ��������
*����һ���������ж��ǲ��ǻ�������
*http://v.youku.com/v_show/id_XMTYwNDAwNjg4.html ��Ȥ�������㷨
************************************************************************/

#include <stdio.h>

int ishuiwen(int m)
{
	int j=0;
	int i=m;//����m��ֵ
	while (m!=0)
	{
		j = 10*j+(m%10);
		m=m/10;
	}
	if(i==j)//���i==j˵���ǻ�����
	{
		return 1;
	}
	else
		return 0;
	
}


int main()
{
	int number;
	printf("please input a integer number\n");
	scanf("%d",&number);
	if (ishuiwen(number))
	{
		printf("�ǻ�����\n");
	}
	else
	{
		printf("���ǻ�����\n");
	}
	system("pause");

	return 0;
}

