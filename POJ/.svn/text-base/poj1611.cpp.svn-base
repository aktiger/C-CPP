/************************************************************************/
/* *Author:justinzhang
/*Email:uestczhangchao@gmail.com
/*Establish:2011年5月14日16:43:46
/*Discription：算法导论22章并查集&&poj1611                                                                     */
/************************************************************************/

#include<iostream>
using namespace std;

/*
*rank[]是用来存放元素x秩的数组，p[]是用来存放元素x父节点的数组
*Make_Set()用来初始化集合元素，刚开始的时候每个元素独立为一个集合
*/
void Make_Set(int rank[],int p[],int x)
{
	p[x] = x;
	rank[x] = 0;
}

/************************************************************************/
/* 寻找x元素所属的集合                                                                     */
/************************************************************************/
int Find_Set(int p[],int x)
{
	if(p[x]!=x)
	{
		p[x] = Find_Set(p,p[x]);
	}
	
		return p[x];

}


/************************************************************************/
/* 合并两个集合                                                                     */
/************************************************************************/
void Union(int rank[],int p[],int x, int y)
{
	int px = Find_Set(p,x);
	int py = Find_Set(p,y);
	if (rank[px]>rank[py])
	{
		p[py] = px;
	}
	else
	{
		p[px] = py;
		if (rank[px]==rank[py])
		{
			rank[py]++;
		}
	}
}

int main()
{
	int n, m;
	int rank[30003];
	int p[30003];
	int numsuspect;
	int personnum;
	int firstpersonnum;
	int groupnum;
	int i,j;
	while(1)
	{
		numsuspect = 0;
		memset(rank,0,sizeof(rank));
		memset(p,0,sizeof(p));
		cin >> n >> m;//n为学生人数，m为学生的分组数
		if(n==0 && m==0)
			break;
		for(j=0;j<n;j++)
			Make_Set(rank,p,j);
		while((--m)>=0)
		{
			cin>>groupnum;
			if (groupnum>=1)
			{
				cin>>firstpersonnum;
			}

			for(i=1;i<groupnum;i++)
			{
				cin >> personnum;
				Union(rank,p,firstpersonnum,personnum);
			}
			
		}
		for (j=0;j<n;j++)
		{
			if (Find_Set(p,0)==Find_Set(p,j))
			{
				numsuspect++;
			}
		}
		cout << numsuspect << endl;

	}
	system("pause");
	return 0;
}

