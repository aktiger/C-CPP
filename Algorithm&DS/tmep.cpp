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

//start ��ʾ������Ϊ�Զ��ľ���ʼΨһ��ʶ������ɾ�������ӡ�
//�������main���������в�����
int main()
{
  //wirte your code here;


  return 0;
}
//end   ��ʾ������Ϊ�Զ��ľ����Ψһ��ʶ������ɾ�������ӡ�
