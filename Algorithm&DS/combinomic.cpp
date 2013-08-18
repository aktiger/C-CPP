/*
  Desc:   For the practice of combinomic algrithm, it is recursive
  Time:   Mon Jun  3 16:11:06 CST 2013
  Author: Justinzhang
  Email:  uestczhangchao@gmail.com

 */

#include <iostream>


int combinomic(int n, int k)
{
  if(n < k)
    return 0;
  if(k == 0)
    return 1;
  return combinomic(n-1,k) + combinomic(n-1, k-1);
}

int main()
{
  std::cout << combinomic(7 , 3) << std::endl;
  return 0;
}
