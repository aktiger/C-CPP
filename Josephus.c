
/*
*author:zhangchao
*time:2011年3月31日17:24:11
*from:c语言竞赛题目大全第三题
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * 有 N 个小孩围成一圈，给他们从1 开始依次编号，现指定从第 W个开始报数，报到第S 个时，该小
 *孩出列，然后从下一个小孩开始报数，仍是报到 S 个出列，如此重复下去，直到所有的小孩都出列（总
 *人数不足 S个时将循环报数），求小孩出列的顺序。或者是求最后出圈人的编号等等类似问题。
 *输入：第一行输入小孩的人数 N（N<=64），接下来每行输入一个小孩的名字(人名不超过 15 个字符)
 *最后一行输入 W,S (W < N)，用逗号","间隔
 *输出：按人名输出小孩按顺序出列的顺序，每行输出一个人名
 *
Sample Input
5
Xiaoming
Xiaohua
Xiaowang
Zhangsan
Lisi
2,3

Sample Output
Zhangsan
Xiaohua
Xiaoming
Xiaowang
Lisi

*/

//将data的第p位设置为0
#define clearbit(data,p)\
	do{\
		data &= ~(1UL<<p);\
	}while(0)

//检查ma的第pos位是否为1，如果为1则返回非零，如果为零则返回0
int checkbit(int ma, int pos)
{
	int flag = ma & (1UL << pos);
	return flag;
}

int main()
{
	int n;//小孩的数量
	int i;
	int w, s ;//从编号为W的小孩开始报数，报到S的小孩就出列
	int mask =0;//小孩位置掩码
	char names[65][15];//存储小孩的名字
	int flag = 0;//相应位置是否有小孩的标志
	int count = 0;//小孩报数计数器
	scanf("%d",&n);//小孩数量
	for(i=0; i < n; i++)
	{
		scanf("%s",names[i]);
	}
	scanf("%d,%d",&w,&s);
	//由于w=1意味着从第一个小孩开始报数，但是我们names数组是从下标为0开始存储的，
	//所以这里的w要减1才对。。。
	w= w -1;
	printf("w=%d,s=%d\n",w,s);

	mask = (1UL<< n)-1;//如果有n个小孩，那么就设置一个掩码，有多少个小孩，就有多少个连续为1的位。
	//printf("mask=%x\n",mask);

	while(mask)
	{
		flag = checkbit(mask,w);//从w开始检查，该位是否为1，为1意味着这个地方还有小孩，否则相应未知的小孩已经出列。
		if(flag)//如果相应的位置上有小孩，那么就报数，即count加1
		{
			count++;
		}

		if(count == s)//如果报数达到了预定值s，那么计数器清零，相应的小孩出列（清除对应掩码为，打印出列的小孩名字）
		{
			count = 0;
			clearbit(mask, w);
			printf("%s\n",names[w]);
		}
		w = (w +1)%n;//继续向后扫描。
	}
	system("pause");
	return 0;
}
