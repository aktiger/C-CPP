/*
Author: justinzhang
Email: uestczhangchao@gmail.com
time:Thu Oct 24 13:21:55 CST 2013
Dest: public derive

 */

#include <iostream>
using  namespace	std;


class A{

protected:
  int m_x;
  
};


class B: public A{
  
};


class C: public B{
public:
  void test(int x)
  {
      m_x = x;
  }

  void print()
  {
     std::cout << "m_x:" << m_x << std::endl;
  }
};


 int main()
 {
   C	c;
   c.test(1);
   c.print();
   return 0;
 }
