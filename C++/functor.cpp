
#include <iostream>
#include <vector>
#include <cassert>
#include <list>

class Add
{
public:
  
  Add(int x=1):m_x(x)
  {
    
  }
  int operator()(int y)
  {
    return m_x + y;
  }
  
  void print()
  {
    std::cout << "m_x=:" << m_x << std::endl;
  }
private:
  int m_x;
};



int main()
{
  Add			a(1);
  a.print();
  std::vector<int>	in;
  std::vector<int>	out;
  std::list<int> out2;

  for(int i = 0; i < 10; i++)
  {
    in.push_back(i);
  }

  transform(in.begin(),in.end(), front_inserter(out2), Add());

  // for(int i = 0; i<10; i++)
  // {
  //       std::cout << out2[i] << std::endl;
  // 	//        assert(in[i]+1 == (out[i]));
  // }

  for(std::list<int>::iterator it = out2.begin(); it != out2.end(); ++it)
  {
    std::cout << *it << std::endl;
  }
	
  return 0;
}
