#include <stdio.h>
#include <math.h>

int primenumber[10001];
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

int combinationcount(int num)
{
	int sum = 0;
	int count = 0;
	int i, j;
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
