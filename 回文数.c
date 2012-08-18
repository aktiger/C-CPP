/************************************************************************
*Author:justinzhang
*Time:2011年5月18日23:34:26
*Discription：回文数:如121是回文数，123不是回文数，就是正反对都是一样的数字
*输入一个整数，判断是不是回文数。
*http://v.youku.com/v_show/id_XMTYwNDAwNjg4.html 妙趣横生的算法
************************************************************************/

#include <stdio.h>

int ishuiwen(int m)
{
	int j=0;
	int i=m;//保存m的值
	while (m!=0)
	{
		j = 10*j+(m%10);
		m=m/10;
	}
	if(i==j)//如果i==j说明是回文数
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
		printf("是回文数\n");
	}
	else
	{
		printf("不是回文数\n");
	}
	system("pause");

	return 0;
}

