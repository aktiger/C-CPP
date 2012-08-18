/*
Sum of Consecutive Prime Numbers

Description

Some positive integers can be represented by a sum of one or more consecutive prime numbers. How many such representations does a given positive integer have? For example, the integer 53 has two representations 5 + 7 + 11 + 13 + 17 and 53. The integer 41 has three representations 2+3+5+7+11+13, 11+13+17, and 41. The integer 3 has only one representation, which is 3. The integer 20 has no such representations. Note that summands must be consecutive prime 
numbers, so neither 7 + 13 nor 3 + 5 + 5 + 7 is a valid representation for the integer 20. 
Your mission is to write a program that reports the number of representations for the given positive integer.

Input

The input is a sequence of positive integers each in a separate line. The integers are between 2 and 10 000, inclusive. The end of the input is indicated by a zero.
Output

The output should be composed of lines each corresponding to an input line except the last zero. An output line includes the number of representations for the input integer as the sum of one or more consecutive prime numbers. No other characters should be inserted in the output.
Sample Input

2
3
17
41
20
666
12
53
0
Sample Output

1
1
2
3
0
0
1
2

*/

#include <stdio.h>
#include <math.h>

int primenumber[10001];//数组必须开大点才可以AC，存放2-10000的素数
int index =1;
void setprimearray()
{
    int i = 0;
    int j=2;
    for(j=2; j<=10000; j++)
    {
      for(i=2; i<=j; i++)
      {
             if(j%i == 0)
                break;
      }
      if(i==j)
      {
           primenumber[index++] = j;
      }
    }

}
/*计算num有多少满足要求的拆分情况*/
int combinationcount(int num)
{
	int sum = 0;
	int count = 0;
	int i, j;
	//二重遍历计算拆分次数
	for(i=1; i<=(num/2)+1; i++)
	{
		sum = 0;
		for(j=i;j<=(num/2)+1; j++)
		{
			sum = sum + primenumber[j];
			if(sum == num)
				count++;
			if(sum > num)
				break;
			else
				continue;
		}
	}
	return count;
}

int main(int argc, char* argv[])
{
   int number;
   int i;
   setprimearray();
   //printf("%d\n",index);
   //for(i=1; i<index; i++)
   //{
   //        printf("%d, ",primenumber[i]);
   //        if(i%10 == 0)
   //                printf("\n");
   //}

   while(scanf("%d",&number),number)
   {
		int tmp = combinationcount(number);
		printf("%d\n",tmp);
   }

   /*system("pause");*/
   return 0;
}
