/*
2011年5月9日20:49:43
作者：张超
邮箱:uestczhangchao@gmail.com
poj:1664 ---- 把m个相同的苹果，放到n个相同的盘子中,这道题是大一的时候做个的，当时还是东哥
告诉我怎么做的，当时没怎么搞清楚，事隔4年，学习到了一种递归的解法，这和组合数学中整数的
拆分是一样的。
*/

#include<stdio.h>

int putapple(int m, int n)
{
	if(m==1 || n==1)
		return 1;
	//如果苹果比盘子少，那么不可能每个盘子都放苹果，并且每个
	//每个盘子都是一样的，所以返回putapple(m,m);
	if(m<n)
		return putapple(m,m);
	//盘子个数和苹果个数相等，那么有两种情况，1》所有的盘子都放一个苹果，有一种放法
	//2》让一个盘子空着，不妨苹果，即为putapple(m,m-1);
	if(m==n)
		return putapple(m,m-1)+1;
	//当苹果的个数大于盘子的个数时，有两种情况:1>所有的盘子都至少放一个苹果，这种情况
	//只需要先从m个苹果中拿出n个，放到n个盘子中，每个盘子放一个苹果,放法数位putapple(m-n,n)
	//2>至少有一个盘子是空着的，然后把m个苹果放到剩下的n-1个盘子中，放法数位putapple(m,n-1)
	if(m>n)
		return putapple(m,n-1)+putapple(m-n,n);
}

int main()
{
	int t;
	int i;
	int m, n;//m为苹果数，n为盘子个数
	scanf("%d",&t);//控制输入有多少行
	//printf("%d\n",t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		//printf("m=%d,n=%d",m,n);
		printf("%d\n",putapple(m,n));
	}
	system("pause");
	return 0;
}