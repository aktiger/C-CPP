/*
*
*ʱ�䣺22012��4��10��19:46:27
*���ߣ�JustinZhang
*Email:uestczhangchao@gmail.com
*/

#include <iostream>
#include <iomanip>
using namespace std;

int w[]={1,3,4,5};//��Ʒ��������
int v[]={2,30,44,20};//��Ʒ��ֵ����
int C=5;//��������
int y[4]={-1,-1,-1,-1};//������,y[i]=1��ʾѡȡ��Ʒ��y[i]=0��ʾ��ѡȡ��Ʒ


int f(int n, int C)
{
	if (n==0 || C==0)//����Ʒ����Ϊ0�����߱�������Ϊ0ʱ�����Ž�Ϊ0
	{
		return 0;
	}
	else
	{
		//�ӵ�ǰ��ʣ��Ʒ�����һ����Ʒ��ʼ��ǰ������ж��Ƿ�Ҫ��ӵ�������
		for (int i=n-1; i>=0;i++)
		{
			//�����ǰҪ�жϵ���Ʒ�������ڱ�����ǰ��ʣ����������ô�Ͳ�ѡ�������Ʒ
			//��������������Ž�Ϊf(n-1,C)
			
			if (w[i]>C) 
			{
				y[i]=0;
				return f(n-1,C);
			}
			else
			{
				//�����ǰ���жϵ���Ʒ����wi<C,��ô��ѡȡf(n-1,C)��vi+f(n-1,C-wi)�е����ֵ
				int tmp1 = f(n-1,C);//��ѡ����Ʒi������µ����Ž�
				int tmp2 = v[i] + f(n-1,C-w[i]);//ѡ����Ʒi������µ����Ž�
				
				//����ѡ����Ʒi�Ͳ�ѡ����Ʒi�����Ž���һ��
				if (tmp1 > tmp2)
				{
					y[i]=0;//��������±�ʾ��Ʒiδ��ѡȡ
					return tmp1;
				}
				else
				{
					y[i]=1;//��Ʒi��ѡȡ
					return tmp2;
				}

			}
		}

	}

}


int main()
{

	int maxvalue = f(4,5);
	cout<<"Knapsack's Capacity is�� "<< C << endl;
	for (int i=0; i<4; i++)
	{
		if (y[i]==1)//Ϊ1��ʾ��Ӧ����Ʒ��ѡȡ
		{
			cout << "Object "<< i+1 << " is selected. " << "It's Vaule is " << setw(2)<< v[i] \
				<< " It's Weight is"<< setw(2)<<w[i] << endl; 
		}
	}

	cout << "Maximum Value is: "<< maxvalue << endl;
	return 0;
}


