/*
  Desc:   For the purpose of practicing iostream manipunations;
  Time:   Tue May 21 14:42:17 CST 2013
  Author: Justinzhang
  Email:  uestczhangchao@gmail.com

*/
#include <iostream>
#include <string>
#include <sstream>

int main()
{
  std::stringstream	ss;
  ss << 123 << ' ' << 456;
  int		x, y;
  ss >> x >> y;
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  
  return 0;
}
