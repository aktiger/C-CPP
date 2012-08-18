/*
Description

George took sticks of the same length and cut them randomly until all parts became at most 50 units long. Now he wants to return sticks to the original state, but he forgot how
many sticks he had originally and how long they were originally. Please help him and design a program which computes the smallest possible original length of those sticks. All 
lengths expressed in units are integers greater than zero. 

Input

The input contains blocks of 2 lines. The first line contains the number of sticks parts 
after cutting, there are at most 64 sticks. The second line contains the lengths of those 
parts separated by the space. The last line of the file contains zero.

Output

The output should contains the smallest possible length of original sticks, one per line. 

Sample Input

9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0

Sample Output

6
5

Input:
12
1 1 2 2 2 3 3 3 3 3 3 4

27
15 3 2 4 11 1 8 8 8 15 3 2 4 11 1 8 8 8 15 3 2 4 11 1 8 8 8

9
15 4 3 1 2 8 11 8 8

45
15 3 2 11 4 1 8 8 8 15 3 2 11 4 1 8 8 8 15 3 2 11 4 1 8 8 8 15 3 2 11 4 1 8 8 8 15 3 2 11 4 1 8 8 8
Output:
6
20
20
20
*/

#include <stdio.h>

int parts;//木棍被切割成碎片的数量
int ticks[65];//ticks[i]第i个碎片的长度
int visited[65];//标记某个碎片是否被使用的标志

int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

/*smallest possible length of original sticks*/
int calculateoriginal(int len, int remains,int num)
{
	int i,j;
	if(remains==0 && num==0)
		return len;
	if(remains==0)
		remains = len;
	for(i=0; i<parts; i++)
	{
		if(visited[i]==1)
			continue;
		if(ticks[i]<= remains)
		{
			visited[i] = 1;
			if(calculateoriginal(len,remains-ticks[i],num-1))
				return len;
			visited[i]=0;
			if(ticks[i]==remains || remains==len)
				break;
			while(ticks[i]==ticks[i+1])
				i++;
		}
		
	}
	return 0;

}

int main()
{
	int i,len;
	int sum = 0;//记录木棍碎片长度总和
	int max = 0;//记录木棍碎片的最大值
	while(1)
	{
		sum = 0;
		max = 0;
		scanf("%d",&parts);//输入碎片总数
		if(parts == 0)
			break;
		for(i=0; i<parts; i++)//记录每一块碎片的长度
		{
			scanf("%d",&ticks[i]);
			sum += ticks[i];
			if(ticks[i]>max)
				max = ticks[i];
		}

		/*for(i=0; i<parts; i++)
		{
			printf("%d\n",ticks[i]);
		}*/
		//printf("max=%d,sum=%d\n",max,sum);

		//printf("*********************\n");
		qsort(ticks,parts,sizeof(int),cmp);
		/*for(i=0; i<parts; i++)
		{
			printf("%d\n",ticks[i]);
		}*/
		//printf("*********************\n");
		
		for(len=max; len<=sum;len++)
		{
			memset(visited,0,sizeof(visited));
			if(sum % len==0)
			{
				if(calculateoriginal(len,0,parts))
				{
					printf("%d\n",len);
					break;
				}
			}
			
		}

	}//end of while
	//system("pause");
	return 0;
}