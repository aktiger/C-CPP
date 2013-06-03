/*
  For the practice of transform in CPP.
  Author: Justinzhang
  Email: uestczhangchao@gmail.com
  Time: Tue May 28 11:24:52 CST 2013 @F4-B265

 */

#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <iterator>
class Angle{
  int	degrees;
public:
  Angle(int dag) : degrees(dag){}
  int mul(int times){
    return degrees *= times;
  }
};
		  
int main()
{
  std::vector<Angle> va;
  for(size_t i = 0; i < 50; i += 10)
  {
    va.push_back(Angle(i));
  }

  int x[] = {1, 2, 3, 4, 5 };
  std::transform(va.begin(), va.end(), x, std::ostream_iterator<int>(std::cout, " "), std::mem_fun_ref(&Angle::mul));
  std::cout << std::endl;
  
  return 0;
}
