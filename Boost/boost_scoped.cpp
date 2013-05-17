#include <iostream>
#include <boost/scoped_ptr.hpp>
int main()
{
  boost::scoped_ptr<int>	i (new int);
  *i = 2;
  std::cout << *i << std::endl;
  return 0;
}
