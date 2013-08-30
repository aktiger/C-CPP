/*
  Author: Justinzhang
  Email:uestczhangchao@gmail.com
  Time:Fri Aug 30 14:08:19 CST 2013
  Desc: For the purpose of practicing convert form int to string, and const_cast<char *>(xxx) function.
 */

#include <iostream>
#include <sstream>

int main()
{
  char	a[15];
  int	x = 1;
  int y = 2;
  sprintf(a,"%d,%d",x,y);
  a[4] = '\0';
  for (int i=0; i<3; i++)
  {
    std::cout << a[i];
  }
  std::cout << std::endl;

  /*~~Begin stringstream practice~~*/
  std::stringstream	ss;
  int			iii = 99999;
  ss << iii;			// put iii in stringstrem,here ss act as outpout string stream
  char *		p   = a;
  std::string  str;

  ss >> str; // get content from ss, put it is var str; Here ss act as input string stream

  std::cout << "--------------------:" << ss.str() << std::endl;
  std::cout << "typeid str.c_str(): " << typeid(str.c_str()).name() << std::endl;
  p = const_cast<char*>(str.c_str());
  
  std::string	plus;
  plus = str + " Hello string stream I love you" ;

  std::cout << "string plus is: " << plus << std::endl;
  std::cout << "str is " << str << std::endl;
  std::cout << "pointer p is " << p << std::endl;
  std::cout << "typeid p is " << typeid(p).name() << std::endl;

  return 0;
}
