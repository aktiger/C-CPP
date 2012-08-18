/*
*
*时间：22012年4月10日19:46:27
*作者：JustinZhang
*Email:uestczhangchao@gmail.com
*/

#include <iostream>
#include <iomanip>
using namespace std;

int w[]={1,3,4,5};//物品重量数组
int v[]={2,30,44,20};//物品价值数组
int C=5;//背包容量
int y[4]={-1,-1,-1,-1};//解向量,y[i]=1表示选取物品，y[i]=0表示不选取物品


int f(int n, int C)
{
	if (n==0 || C==0)//当物品数量为0，或者背包容量为0时，最优解为0
	{
		return 0;
	}
	else
	{
		//从当前所剩物品的最后一个物品开始向前，逐个判断是否要添加到背包中
		for (int i=n-1; i>=0;i++)
		{
			//如果当前要判断的物品重量大于背包当前所剩的容量，那么就不选择这个物品
			//在这种情况的最优解为f(n-1,C)
			
			if (w[i]>C) 
			{
				y[i]=0;
				return f(n-1,C);
			}
			else
			{
				//如果当前待判断的物品重量wi<C,那么就选取f(n-1,C)和vi+f(n-1,C-wi)中的最大值
				int tmp1 = f(n-1,C);//不选择物品i的情况下的最优解
				int tmp2 = v[i] + f(n-1,C-w[i]);//选择物品i的情况下的最优解
				
				//返回选择物品i和不选择物品i中最优解大的一个
				if (tmp1 > tmp2)
				{
					y[i]=0;//这种情况下表示物品i未被选取
					return tmp1;
				}
				else
				{
					y[i]=1;//物品i被选取
					return tmp2;
				}

			}
		}

	}

}


int main()
{

	int maxvalue = f(4,5);
	cout<<"Knapsack's Capacity is： "<< C << endl;
	for (int i=0; i<4; i++)
	{
		if (y[i]==1)//为1表示相应的物品被选取
		{
			cout << "Object "<< i+1 << " is selected. " << "It's Vaule is " << setw(2)<< v[i] \
				<< " It's Weight is"<< setw(2)<<w[i] << endl; 
		}
	}

	cout << "Maximum Value is: "<< maxvalue << endl;
	return 0;
}


