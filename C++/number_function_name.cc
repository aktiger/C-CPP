
/*
  Author: Justinzhang
  Email: uestczhangchao@gmail.com
  Time: Tue Sep  3 18:41:54 CST 2013

  Desc: For the purpose of practicing SIG_DFL
  Link: http://www.delorie.com/gnu/docs/gcc/gcc_42.html 
 */

#include <iostream>

#define SIG_ERR (void(*)())-1
#define SIG_DEF (void(*)(int))0
#define SIG_IGN (void(*)())1

int main(int argc, char *argv[])
{
  std::cout << SIG_IGN << std::endl;
  std::cout << typeid(SIG_IGN).name() << std::endl;
  return 0;
}
