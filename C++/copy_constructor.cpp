/*
  This program show how copy constructor and assign operator works,
  when an object is declared and initialize it will use copy constructor,
  only when an object already exist, the assign operator will be called;
  Author: justinzhang@gmail.com
  Email:uestczhangchao@gmail.com
  Time: Fri May 17 17:10:07 CST 2013 @F4-B265
 */
#include <iostream>
#include <string>
class T
{
public:
  T() {std::cout << "T" << std::endl;}
  T	operator = (const T &other) {std::cout << "operator =" << std::endl;}
  T(const T &other) {std::cout << "T(const &other)" << std::endl;}
  ~T(){std::cout << "delete" << std::endl;}
};

int main()
{
  T	t;
  T	tt(t);
  T	kk = t;
  kk = t;
  return 0;
}
