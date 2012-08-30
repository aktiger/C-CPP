/*
时间：2012年4月10日025
作者：JustinZhang
Email:uestczhangchao@gmail.com
Desc:算法导论中背包问题的实现，采用非递归的方式;更加深入的理解递归是如何工作的，因为此时没有用递归调用，
是使用矩阵来记录每一步计算的结果，最后得到最优解；在最优解找到过后，还要给出那些物品被选中，此时是使用c[i][j]
从c[n][W]往前查找，利用递归公式做出判断（如果当前物品被选中，那么没有该物品的最优解(c[i-1][j-w[i])就等于当前的最优解减去当前物品的价值（c[i][j]-v[i]））；
*/

#include <iostream>
#include <iomanip>
using namespace std;



const int n = 4;
const int W = 5;

int c[n+1][W+1];

/*
input:
int v[]:物品的价值数组;
int w[]:物品重量数组;
int n:物品个数;
int W:背包容量;

*/
void knapsack_0_1_problem(int v[],int w[], int n, int W)
{
	c[0][0] = 0;
	//c[i][j]表示，将i个物品放入容量为j的背包中所具有的价值最大值；
	for (int i=1; i<n; i++)
	{
		c[i][0] = 0;//如果背包容量为0，那么i个物品放入该背包的最优值都是0；
	}
	for (int j=1; j<W; j++)
	{
		c[0][j] = 0;//如果物品的数量为0，那么将0个物品放入大小为j的背包中的最优值就是0；
	}

	//下面开始使用递归公式求解最优值
	for(int i=1; i<=n;i++)
	{
		for (int ww=1; ww<=W; ww++)
		{
			//如果当前物品的重量大于背包的体积
			if (w[i]>ww)
			{
				c[i][ww] = c[i-1][ww];
			}
			else
			{
				if (c[i-1][ww] > (v[i]+c[i-1][ww-w[i]]))
				{
					c[i][ww] = c[i-1][ww];
				}
				else
				{
					c[i][ww] = v[i]+c[i-1][ww-w[i]];
				}
			}
		}

	}
}



int main()
{

	//v[]和w[]分别为价值数组和重量数组，并且下标都是从1开始算的，第0个元素设为-999；
	//这里要下标必须从1开始，因为在迭代的过程当中有c[i][j]=max{c[i-1][j], c[i-1][j-w[i]]},
	//如果元素的下标从0开始取的话，我们在遍历物品价值和重量数组的时候，就会有c[0][j]=max{c[i-1][j], c[-1][j-w[0]]},这里就会出现数组下标为0的情况,
	//所以下标选择从1开始。
	int v[n+1] = {-999, 6, 7, 14, 8};
	int w[n+1] = {-999, 1, 2, 4, 5};

	knapsack_0_1_problem(v,w,n,W);

	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=W; j++)
		{
			cout << setw(3) << c[i][j];
		}
		cout << endl;
	}

	int remainspace = W;//该变量用来记录背包当前还剩余的容量

	//以下过程，从c[n][W]开始向前寻找，那些物品被选择装进背包中;
	//判断条件为：如果第n个物品被选择装进背包中，那么c[n][W]=c[n-1][W-w[n]] + v[n];此时reminspace将变为remainspace-w[n]
	//否则物品n没有被选择，此时背包剩余的容量remainspace不会发生改变；
	//按照上述方法一直往前找，即可以将所有装入背包中物品找到。

	for(int i=n; i>=1; i--)
	{

		if (remainspace >= w[i])
		{

			if ((c[i][remainspace]-c[i-1][remainspace-w[i]]==v[i]))
			{
				cout << "item " << i << " is selected!" << endl;
				remainspace = remainspace - w[i];//如果第i个物品被选择，那么背包剩余容量将减去第i个物品的重量
												//2012年5月2日21:45:33 修改为remainspace - w[i];以前为 W-w[i];
			}
		}

	}

	cout << "Maximum values is " << c[n][W] << endl;

	return 0;
}

