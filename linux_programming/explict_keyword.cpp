/*
  Desc:   For the practice of explict key words in c++
  Time:   Tue May 21 15:09:50 CST 2013
  Author: Justinzhang
  Email:  uestczhangchao@gmail.com
 */
#include <iostream>

class Foo
{
public:
explicit  Foo(int foo):_m_foo(foo)
  {
    
  }
  int GetFoo()
  {
    return _m_foo;
  }
private:
  int _m_foo;
};

void DoBar(Foo foo)
{
  int	i = foo.GetFoo();
  std::cout << " i = " << i << std::endl;
}
int main()
{
  //without explicit key word, the follwing call is corret , but with explicit on the constructor, it is wrong
  //DoBar(34);
  DoBar(Foo(34));
  return 0;
}
