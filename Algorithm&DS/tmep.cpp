#include <stdio.h>
#include <string.h>

int MaxSum(int* a,int n)
{
  //write your code here
  int	sum1 = 0;
  int	sum2 = 0;
  for(size_t i=0; i < n; i++)
  {
    if(sum1<0)
    {
      sum1 = 0;
    }
    else
    {
      sum1 = sum1 + a[i];

    }
    if(sum2 < sum1)
    {
      sum2 = sum1;
    }
  }
  return sum2;
}

//start 提示：本行为自动阅卷起始唯一标识，请勿删除或增加。
//完成下面main函数，自行测试下
int main()
{
  //wirte your code here;


  return 0;
}
//end   提示：本行为自动阅卷结束唯一标识，请勿删除或增加。
